/*
#  redirect a.out's stdin to read from file infile.txt:
$ ./a.out < infile.txt

#  redirect a.out's stdout to print to file outfile.txt:
$ ./a.out > outfile.txt

# redirect a.out's stdout and stderr to a file out.txt
$ ./a.out &> outfile.txt
# redirect all three to different files:
#   (< redirects stdin, 1> stdout, and 2> stderr):
$ ./a.out < infile.txt 1> outfile.txt 2> errorfile.txt


%f, %g: placeholders for a float or double value
%d:     placeholder for a decimal value (char, short, int)
%u:     placeholder for an unsigned decimal
%c:     placeholder for a single character
%s:     placeholder for a string value
%p:     placeholder to print an address value

%ld:    placeholder for a long value
%lu:    placeholder for an unsigned long value
%lld:   placeholder for a long long value
%llu:   placeholder for an unsigned long long  value

%5.3f: print float value in space 5 chars wide, with 3 places beyond decimal
%20s:  print the string value in a field of 20 chars wide, right justified
%-20s: print the string value in a field of 20 chars wide, left justified
%8d:   print the int value in a field of 8 chars wide, right justified
%-8d:  print the int value in a field of 8 chars wide, left justified

%x:     print value in hexadecimal (base 16)
%o:     print value in octal (base 8)
%d:     print value in signed decimal  (base 10)
%u:     print value in unsigned decimal (unsigned base 10)
%e:     print float or double in scientific notation
(there is no formatting option to display a value in binary)
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE * infile;
    FILE * outfile;
    infile = fopen("07-io-and-printf.c", "r");  // relative path name of file, read mode
    if (infile == NULL) {
        printf("Error: unable to open file %s\n", "07-io-and-printf.c");
        exit(1);
    }

    // fopen with absolute path name of file, write mode
    outfile = fopen("/home/me/output.txt", "w");
    if (outfile == NULL) {
        printf("Error: unable to open outfile\n");
        exit(1);
    }
}
