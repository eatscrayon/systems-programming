#include <stdio.h>
#include <stdlib.h>

#include "LinuxMemory.h"

int main()
{
    LinuxProc_t CodeBlocks;
    /* Fill structure */
    CodeBlocks = LinuxProcFromID((pid_t)GetPIDbyName("codeblocks",0,0));
    printf("Process ID : %i\n", CodeBlocks.ProcId);
    void* address = 0x8b6b3000;
    attach(CodeBlocks);
    Read(CodeBlocks,0,address,0);
    detach(CodeBlocks);
    return 0;
}