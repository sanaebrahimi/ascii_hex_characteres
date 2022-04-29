All I/O is done with the open(2) / read(2) and/or write(2)
system calls.

ascii.c:

This program prints an ASCII table that prints the ASCII characters
from 0 to 127 in 4 separate columns.  Each character is preceded by
its value, which is printed in decimal by default. The program accept a command line switch to modify the output of ASCII values to alternatively print it in binary (-b option), hexadecimal (-h option) or octal (-o option).

Non-printable ASCII characters should be printed as a dot (.).
Example output:

    0: '.'        32: ' '         64: '@'         96: '`'
    1: '.'        33: '!'         65: 'A'         97: 'a'
    2: '.'        34: '"'         66: 'B'         98: 'b'
...

hex.c:
This program prints a hex-dump of its input (either stdin or from
a file, name provided on the command line.) Example output:

00000000 : 23 69 6E 63 6C 75 64 65  20 3C 75 6E 69 73 74 64 : #include <unistd
00000010 : 2E 68 3E 0A 23 69 6E 63  6C 75 64 65 20 3C 73 79 : .h>.#include <sy
...
000000D0 : 31 34 29 3B 0A 0A 20 20  72 65 74 75 72 6E 20 30 : 14);..  return 0
000000E0 : 3B 0A 7D 0A                                      : ;.}.

The first hex value is the byte offset within the input, then the data read
is printed as 8 bit hex-values followed by a " : " then the ASCII
representation of that data (prints a dot (.) if the character is not a printable
character.


