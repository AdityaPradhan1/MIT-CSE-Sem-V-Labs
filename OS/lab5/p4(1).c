#include <stdio.h>
int main()
{
    char ch;

    
    FILE *fpbr, *fpbw;

    fpbr = fopen("bin1.exe", "rb");

    if (fpbr == NULL)
    {
        puts("Input Binary file is having issues while opening");
    }

    fpbw= fopen("bin2.exe", "wb");

    if (fpbw == NULL)
    {
       puts("Output binary file is having issues while opening");
    }

    while(1)
    {
        ch = fgetc(fpbr);
        if (ch==EOF)
             break;
         else
             fputc(ch, fpbw);
     }

     fclose(fpbr);
     fclose(fpbw);

     return 0;
}
