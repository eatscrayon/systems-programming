#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <dirent.h>


// variadic function to concat strings
// https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
char* concat(int count, ...)
{
    va_list ap;
    int i;

    // Find required length to store merged string
    int len = 1; // room for NULL
    va_start(ap, count);
    for(i=0 ; i<count ; i++)
        len += strlen(va_arg(ap, char*));
    va_end(ap);

    // Allocate memory to concat strings
    char *merged = calloc(sizeof(char),len);
    int null_pos = 0;

    // Actually concatenate strings
    va_start(ap, count);
    for(i=0 ; i<count ; i++)
    {
        char *s = va_arg(ap, char*);
        strcpy(merged+null_pos, s);
        null_pos += strlen(s);
    }
    va_end(ap);

    return merged;
}

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
                char *CommandLinePath = concat(3,"/proc/",directory_entry->d_name,"/cmdline");

                // Open the file that we constructed in the previious step
                //"rt" mean read mode + text mode
                // CmdLineFile is a pointer to a FILE struct
                FILE* CmdLineFile = fopen (CommandLinePath, "rt") ; 

                free(CommandLinePath); // dont need this anymore so free it
                
                if (CmdLineFile) // CmdLineFile is NULL if the file didn't open
                {
                    // This will read CmdLineFile until a whitespace "%s" is found
                    // and store the contents in NameOfProcess
                    char NameOfProcess[4096]  ; // Create a char array to hold the name of the found process
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
    
    exit(EXIT_SUCCESS);
}