# HEAPDUMP
Dumps the heap of a process in xxd -rp compatible format.
## Limitation
If a process as multiple PID's it grabs the first one.
If a process has multiple heaps, its grabs the first one.

Build:
gcc -o heapdump heapdump.c

Usage:
./heapdump <processname>