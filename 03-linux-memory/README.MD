# HEAPDUMP
Dumps the heap of a process in xxd -rp compatible format using process_vm_readv

## Limitations
If a process has multiple PID's it grabs the first one.
If a process has multiple heaps, its grabs the first one.

## Instructions
Build:
gcc -o heapdump heapdump.c

Usage:
./heapdump <processname>
