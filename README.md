## Printf Linux command

### The very first thing we do when learning a programming language is to write "Hello World !" on the screen.

## Description:
### The my_printf() function produce output according to a format as described below. The my_printf() functions write output to stdout, the standard output stream;

### This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.

### The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

### Each conversion specification is introduced by the % character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the %, the following appear in sequence:

### doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
### c The int argument is converted to an unsigned char, and the resulting character is written.
### s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
### p The void * pointer argument is printed in hexadecimal.

## Compilation:

### 1. Run this command to compile the programm: gcc -o my_printf my_printf.command
### 2. After compile the program run the next command: ./my_printf if you want you can run: -Wall -Wextra -Werror
### 3. In the main part I have added a comment saying Test inputs: 
### here I have added some examples, I have called the standard print and also my own printf in order that you
### can see that my own printf is returning the same as the standard, 
### you can change the parameters or you can change the type of data that you want to see.
