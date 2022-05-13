#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>


// My printf functions declaration
int my_printf(char * restrict format, ...);
int my_putchar(char c);
int my_putcharU(unsigned char c);
void my_putstr(char* param_1);
char* itoa(int num, char* str, int base);
char* reverse_string(char* param_1);
char* itoaU(unsigned int num, char* str, int base);
void * printp(void *pPointer, int * hexsize);
char *trim_leading(char *dest, int char_to_trim);


/////////////////////    ----------- main ---------------    //////////////////////////////////////////////
int main (int argc, char *argv[]) {
   int i = 1;
   int octal = 012;
   char *stringTest = "say welcome to C";
   int integer = 0;
   int un = 345;
   /// Unsigned hexa
   int unb=-3423;
   int una = '@';
   /// p void
   int x = 7890;
   int *ptr = &x;
   int sizePrintf=0;
   int sizeMyPrintf=0;

   //////////////////////////////// Test inputs ///////////////////////////////////////////////
   
   // Standard Printf
   sizePrintf = printf("%c hello hello wsw%o %x %s %p\n",una,una,unb,stringTest,ptr);
   /// My own Printf
   sizeMyPrintf = my_printf("%c hello hello wsw%o %x %s %p\n",una,una,unb,stringTest,ptr);

   // Standard Printf
   printf("Size printf:%d\n",sizePrintf);
   // My own  Printf
   my_printf("Size Myprintf:%d\n",sizeMyPrintf);

   return 0;
}


///////////////////////////////// My own printf function //////////////////////////////////////////
int my_printf(char * restrict format, ...){
    int printInteger;
    unsigned int printOctal;
    unsigned int printUnsigDec;
    unsigned int printUnsExa;
    char *IntegerString;
    int printchar;
    char *printString;
    char str[250];
    int argIndx;
    int *pointer;
    int* countPointerHexSize;
    int result;
    int lengthCount=-1;

    // declare the list which is going to store all the arguments
    va_list argument;
    va_start(argument, format);


    //////////////// Iterate over the fomart input//////////////////////
    for (argIndx = 0; format[argIndx] != '\0'; argIndx++){
        if(format[argIndx] == '%'){
            argIndx++;
            switch(format[argIndx]){
                case 's':
                   printString = va_arg(argument,char*);
                   lengthCount=lengthCount+strlen(printString);
                   my_putstr(printString);
                   break;
                case 'd':
                    printInteger = va_arg(argument, int);
                   if(printInteger==0){
                       my_putchar('0');
                       lengthCount++;
                   }else{
                      char *itoaRes= itoa(printInteger,str, 10);
                       lengthCount=lengthCount+strlen(itoaRes);
                   }
                    break;
                case 'o':
                printOctal = va_arg(argument, unsigned int);
                    if(printOctal==0){
                        my_putchar('0');
                        lengthCount++;
                    }else{
                        char *itoaRes= itoaU(printOctal,str, 8);
                        lengthCount=lengthCount+strlen(itoaRes);
                    }
                    break;
                case 'u':
                    printUnsigDec = (va_arg(argument, unsigned int));
                     if(printUnsigDec==0){
                       my_putchar('0');
                       lengthCount++;
                   }else{
                    char *itoaRes=itoaU(printUnsigDec,str,10);
                    lengthCount=lengthCount+strlen(itoaRes);
                   }
                    break;
                case 'x':
                    printUnsExa = (va_arg(argument,int));
                    if(printUnsExa==0){
                       my_putchar('0');
                       lengthCount++;
                   }else{
                    char *itoaRes=itoaU(printUnsExa,str,16);
                    lengthCount=lengthCount+strlen(itoaRes);
                   }
                    break;
                case 'c':
                    printchar = va_arg(argument,int);
                    my_putchar((unsigned char)printchar);
                    lengthCount++;
                    break;
                case 'p':
                    pointer = va_arg(argument,void*);
                    int* res = printp(pointer,countPointerHexSize);
                    lengthCount=lengthCount+*res;
                    break;
                case '\0':
                    break;
                default:
                    lengthCount++;
                    my_putchar(format[argIndx]);
                    break;  
            }
        }else{
           lengthCount++;
            my_putchar(format[argIndx]);
        }
    }

va_end(argument);

return lengthCount+1;
    
}

//////////////////////////////////////// End of my own function//////////////////////////////////

///////////////// Standard output
int my_putchar(char c){
    write(1, &c, 1);
}

int my_putcharU(unsigned char c){
    write(1, &c, 1);
}

void my_putstr(char* param_1){
    
    // print the string
  while(*param_1 != '\0') {
      my_putchar(*param_1);
    param_1++;
  }
}

/////////////////////// Itoa implemantation ///////////////////////////////
char* itoa(int num, char* str, int base){
	int i = 0;
	bool isNegative = false;
	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}
	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}

	// Process individual digits
	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num = num/base;
	}

	// If number is negative, append '-'
	if (isNegative)
		str[i++] = '-';

	str[i] = '\0'; // Append string terminator

	// Reverse the string
	reverse_string(str);
    //// printint the string
    my_putstr(str);
	return str;
}

//////////////////////// itoa unsigned ///////////////////
char* itoaU(unsigned int num, char* str, int base){
	int i = 0;
	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	// Process individual digits
	while (num != 0){
		int rem = num % base;
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num = num/base;
	}

	str[i] = '\0'; // Append string terminator

	// Reverse the string
	reverse_string(str);
    // printing the string
    my_putstr(str);
    return str;
}


////////////////////////////////Reverse function//////////////////////////////////////////
char* reverse_string(char* param_1)
{
    char Temp = 0;
    int iLoop =0, iLen = 0;
    
    while(param_1[iLen++] != '\0');
    //Remove the null character
    iLen--;
    //Array index start from 0 to (length -1)
    iLen--;
    while (iLoop < iLen)
    {
        Temp = param_1[iLoop];
        param_1[iLoop] = param_1[iLen];
        param_1[iLen] = Temp;
        iLoop++;
        iLen--;
    }
  
    return param_1;
}

//////////////////// %p void //////////////////////////////////////

void * printp(void *pPointer, int* hexsize){
 uintptr_t j = (uintptr_t) pPointer;
 char lst[(sizeof j * CHAR_BIT + 3)/ 4 + 1]; // Size needed to print in base 16
 char *p = &lst[sizeof lst] - 1;
 /////// terminator
  *p = '\0';
  do {
    p--;
    *p = "0123456789abcdef"[j%16];
    //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F.
    j /= 16;
  } while (p > lst);

    // call the function to remove the extra 0
    trim_leading(p, '0');
    ////////////////////////////// add the 0x
    char exl[] = "0x";
    strcat(exl,p);
    // call the functions to print in stdout
    my_putstr(exl);
    int size = (int)strlen(exl);
    hexsize = &size;
}

/////////////// trim function//////////////////
char *trim_leading(char *dest, int char_to_trim){
    char *p=strdup(dest);
	if(*p)
	{
	    while (*p && *p == char_to_trim) p++;
	    strcpy(dest,p);
	}
	return dest;	
}

