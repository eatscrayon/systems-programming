### Precompiler Step
```
$ gcc -E  myprog.c
$ gcc -E  myprog.c  > out
$ nano out
```

### Compile step
```
$ gcc -S  myprog.c
$ nano myprog.s
```

### Assembly step
```
$ gcc -c  myprog.c

# disassemble functions in myprog.o with objdump:
$ objdump -d myprog.o
```

### Linking step
```
$ gcc myprog.c
$ ./a.out

# disassemble functions in a.out with objdump:
$ objdump -d a.out

# The ldd utility lists an executable file’s shared object dependencies
$ ldd a.out
```