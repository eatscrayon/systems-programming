#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


// Loop through a string and return True if the string is only made of chars 0-9
int IsNumeric(const char* CharacterList)
{
    for ( ; *CharacterList; CharacterList++)
        if (*CharacterList < '0' || *CharacterList > '9')
            return 0;
    return 1;
}

pid_t GetPIDbyName(const char* ProcessName)
{

    int ipid = -1; // Set our PID to -1 in case we can't find it
    char CommandLinePath[800]  ; // Create a char array to hold /proc/$pid/cmdline
    char NameOfProcess[500]  ; // Create a char array to hold the name of the found process
    char* StringToCompare = NULL ; // Null pointer to the contents of /proc/$pid/cmdline
    DIR* directory = NULL ; // Null pointer to a directory struct from <dirent.h>
    struct dirent* directory_entry = NULL ; // Null pointer to a dirent structure <dirent.h>
    

    // Init our DIR* directory struct
    directory = opendir("/proc/") ;
    if (directory == NULL)
    {
        perror("Couldn't open the /proc/ directory") ;
        return  -2 ;
    }

    // Loop through the contents of our directory
    while ((directory_entry = readdir(directory)) ) // Returns a pointer to a dirent structure
    {
        if (directory_entry->d_type == DT_DIR) // if the type is a directory
        {
            if (IsNumeric(directory_entry->d_name)) // and the name is only numbers...
            {
                // The numbered folders in /proc correspond to the running processes
                // Inside each folder is a file call "cmdline" which has the name of the process
                // Build this filename and store it in CommandLinePath
                strcpy(CommandLinePath, "/proc/") ; // "/proc/"
                strcat(CommandLinePath, directory_entry->d_name) ; // "/proc/666"
                strcat(CommandLinePath, "/cmdline") ;  // "/proc/666/cmdline"

                // Open the file that we constructed in the previious step
                //"rt" mean read mode + text mode
                // CmdLineFile is a pointer to a FILE struct
                FILE* CmdLineFile = fopen (CommandLinePath, "rt") ; 
                
                if (CmdLineFile) // CmdLineFile is NULL if the file didn't open
                {
                    // This will read CmdLineFile until a whitespace "%s" is found
                    // and store the contents in NameOfProcess
                    fscanf(CmdLineFile, "%s", NameOfProcess) ; 
                    fclose(CmdLineFile); //close thefile

                    // strrchr return a pointer to the last occurrence of character in str.
                    // so if we find a '/' then we jump to right of the last '/'
                    // in the string, else we store the pointer as is
                    if (strrchr(NameOfProcess, '/')) 
                        StringToCompare = strrchr(NameOfProcess, '/') +1 ; 
                    else
                        StringToCompare = NameOfProcess ;
                    
                    // like strstr(), but ignores the case of both arguments.
                    // is our taget process a substring of the cmdline?
                    if ( strcasestr(StringToCompare, ProcessName) )
                    {
                        ipid = atoi(directory_entry->d_name); //converts C-string to int.
                        closedir(directory) ; //close the directory
                        return ipid; // Break out of the loop and return the PID
                    }
                }
            }
        }
    }
    closedir(directory) ;// We didn't find it, close the directory
    return ipid ; // We didn't find it, return -1
}

//Define our struct that will hold process information
typedef struct LinuxProc{

    pid_t    ProcId;

} LinuxProc; //<-type def

int main(int argc, char **argv)
{
    //Initialize our struct that will hold process information
    //Passing argv1 to the GetPIDbyName Function
    LinuxProc Process = { 
        .ProcId = GetPIDbyName(argv[1])
    };

    //Print the PID of the Process
    (Process.ProcId > 0) ? printf("Process ID : %i\n", Process.ProcId ) : printf("PID Not Found\n");
    
    return 0;
}