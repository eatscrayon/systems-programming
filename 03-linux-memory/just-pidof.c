#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <fcntl.h>

#define PROC_DIRECTORY "/proc/"  
#define CASE_SENSITIVE    1
#define CASE_INSENSITIVE  0
#define EXACT_MATCH       1
#define INEXACT_MATCH     0

typedef struct LinuxProc_s{

    char*    ProcMemPath;
    pid_t    ProcId;

} LinuxProc_t; //type def

int IsNumeric(const char* ccharptr_CharacterList)
{
    for ( ; *ccharptr_CharacterList; ccharptr_CharacterList++)
        if (*ccharptr_CharacterList < '0' || *ccharptr_CharacterList > '9')
            return 0;
    return 1;
}

pid_t GetPIDbyName(const char* cchrptr_ProcessName)
{
    int intExactMatch =0;
    int intCaseSensitiveness = 0;
    int ipid = -1;
    char chrarry_CommandLinePath[800]  ;
    char chrarry_NameOfProcess[500]  ;
    char* chrptr_StringToCompare = NULL ;
    struct dirent* de_DirEntity = NULL ;
    DIR* dir_proc = NULL ;

    dir_proc = opendir(PROC_DIRECTORY) ;
    if (dir_proc == NULL)
    {
        perror("Couldn't open the " PROC_DIRECTORY " directory") ;
        return  -2 ;
    }


    while ((de_DirEntity = readdir(dir_proc)) )
    {
        if (de_DirEntity->d_type == DT_DIR)
        {
            if (IsNumeric(de_DirEntity->d_name))
            {
                strcpy(chrarry_CommandLinePath, PROC_DIRECTORY) ;
                strcat(chrarry_CommandLinePath, de_DirEntity->d_name) ;
                strcat(chrarry_CommandLinePath, "/cmdline") ;
                FILE* fd_CmdLineFile = fopen (chrarry_CommandLinePath, "rt") ; 
                if (fd_CmdLineFile)
                {
                    fscanf(fd_CmdLineFile, "%s", chrarry_NameOfProcess) ; 
                    fclose(fd_CmdLineFile);

                    if (strrchr(chrarry_NameOfProcess, '/'))
                        chrptr_StringToCompare = strrchr(chrarry_NameOfProcess, '/') +1 ;
                    else
                        chrptr_StringToCompare = chrarry_NameOfProcess ;

                    if ( strcasestr(chrptr_StringToCompare, cchrptr_ProcessName) )
                    {
                        ipid = atoi(de_DirEntity->d_name);
                        closedir(dir_proc) ;
                        return ipid;
                    }
                }
            }
        }
    }
    closedir(dir_proc) ;
    return ipid ;
}

int main(int argc, char **argv)
{
    LinuxProc_t Process = { 
        .ProcId = GetPIDbyName(argv[1])
    };

    printf("Process ID : %i\n", Process.ProcId);
    

    return 0;
}