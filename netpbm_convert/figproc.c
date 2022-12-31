/* This program converts RGB images to Grayscale images and Grayscale images to Black-and-White images. The images must respect the NetPBM format for either Binary or ASCII encoding (P6-P1). */
   
#include <ctype.h>  /* Used for the isspace() function. */
#include <stdio.h>  /* Used for the getchar(), putchar(), ungetc(), printf(), fprintf() functions. */
#define ERROR -1


/* Declaring functions written for the program */
void error();                  /* Void function used to print an error message to the Terminal for any invalid user input case. */
int getinteger(int base);      /* Function used to return an integer value of numerical base 'base', which is received from the standard input stream (stdin). 
                                  NOTE: The function stops whenever it receives a blank character (using the getchar() function). 
                                  Therefore, keep in mind that after using the function we understand that the NetPBM format is respected. */

/*Further explanation for the functions exist in the functions' definitions. */

int main(void)
{
    unsigned char ch, magicnum, check, count, temp, R, G, B, luminosity, byte;
    int val, width, height, i, j, k, endfile, max;

    /* Checking and receiving the magic number */
    ch = getchar();
    if (ch != 'P') 
    {
        error();
        return 0;
    }
    
    magicnum = getchar();    /* Variable that stores the magic number (from 1 to 6) */
    if ( !('1' <= magicnum && magicnum <= '6') )
    {
        error();
        return 0;
    }
    /* Printing the letter 'P' and the magic number afterwards, with respect to the NetPBM format. */
    putchar(ch);            
    putchar(magicnum-1);

    ch = getchar();        /* After the magic number, at least one blank character is expected. */
    if (!isspace(ch))
    {
        error();
        return 0;
    }
    putchar('\n');         /* Printing newline with respect to the NETPBM format */


    /* Between the magic number value and the image's width value, there can be comments starting from the character '#'. The character must exist in the start of each new line which has a comment. */
    check = 0;     /* Variable used to check if the character '#' exists in a line. */
    do
    {
        ch = getchar();
        if (ch == '#') check = 1;
        if (ch == '\n') check = 0;
    }
    while (isspace(ch) || check == 1);  /* Receiving data until the first character of the image's width is received. The "isspace()" function checks if the argument of the function is a blank character. */

    ungetc(ch, stdin);    /* The last character received by the getchar() function must the image's width, therefore, 
                             it is sent back into the standard input stream in order for the width to be evaluated by the getinteger() function later. */

    do     /* Evaluating width */
    {
        width = getinteger(10);
    }
    while (width == ERROR - 1);
    
    if (width == ERROR)
    {
        error();
        return 0;
    }
    printf("%d", width);
    putchar(' ');   /* Printing space with respect to the NETPBM format */

    do     /* Evaluating height */
    {
        height = getinteger(10);
    }
    while (height == ERROR - 1);
    
    if (height == ERROR)
    {
        error();
        return 0;
    }
    printf("%d", height);
    putchar('\n');   /* Printing newline with respect to the NETPBM format */


    /* Checking and receiving max value that an integer representing a pixel's color can take. */
    
    max = 0;
    do     /* Evaluating max */
    {
        max = getinteger(10);     /* Reminder for line 105: We have already checked that there is a blank character since getinteger() was used. */
    }                             /* Therefore, no error checking is needed for magicnumber = 1,2,3 since AT LEAST one blank character is expected after the 'max' value. */
    while (max == ERROR - 1);
    
    if (max == ERROR)
    {
        error();
        return 0;
    }

    if (magicnum >= '4')            /* For binary encoding, exactly one blank character is expected after the 'max' value. */
    {
        ch = getchar();
        if (isspace(ch))
        {
            error();
            return 0;
        }
    }



    if (magicnum == '3' || magicnum == '6')
    {
        printf("%d", max);
        putchar('\n');   /* Printing newline with respect to NetPBM format */
    }
    
    

    /* Starting image type conversion (RGB --> Grayscale, or Grayscale --> B/W) for both Binary and ASCII encoding. */
    switch (magicnum)
    {
        /* Note that for ASCII encoding, getch() receives each digit of a base 10 number at a time. */
        case '3':
            /*Converting RGB to Grayscale, for ASCII encoding */
            for (i = 0; i < height * width; i++)
            {
                /* Computing R */
                do
                {
                    val = getinteger(10);
                }
                while (val == ERROR - 1);
                

                if (val > max || val == ERROR)
                {
                    error();
                    return 0;
                }

                R = (char) val;

                
                /* Computing G */
                do
                {
                    val = getinteger(10);
                }
                while (val == ERROR - 1);

                if (val > max || val == ERROR)
                {
                    error();
                    return 0;
                }

                G = (char) val;


                /* Computing B */
                do
                {
                    val = getinteger(10);
                }
                while (val == ERROR - 1);

                if (val > max || val == ERROR)
                {
                    error();
                    return 0;
                }

                B = (char) val;


                /* The conversion from RGB to Grayscale is done by the following equation: */
                luminosity = (299*R+587*G+114*B)/1000;
                printf("%d ", luminosity);
                if (i != 0 && i%width == 0) printf("\n");   /* Printing newlines in order to respect the general format for output ASCII files. */
            }
            break;

        case '2':
        /*Converting Grayscale to B/W, for ASCII encoding */
            for (i = 0; i < height * width; i++)
            {
                /* Computing pixel's grayscale value */
                do
                {
                    val = getinteger(10);
                }
                while (val == ERROR - 1);
                

                if (val > max || val == ERROR)
                {
                    error();
                    return 0;
                }                
                
                /* The conversion from Grayscale to B/W is done by the following equation: */
                if (val > (max + 1) / 2)
                {
                    printf("0 ");
                }
                else
                {
                    printf("1 ");
                }
                if (i != 0 && i%width == 0) printf("\n");    /* Printing newlines in order to respect the general format for output ASCII files. */
            }
            break;

        case '6':
        /* Note that for Binary encoding, getch() receives ASCII characters. Therefore, each value that getch() returns is a pixel's base 10 value. " */

        /*Converting RGB to Grayscale, for Binary encoding */

            ungetc(ch, stdin);    /* Returning last-received 'ch' character into the standard input stream in order to respect the NetPBM format. */
            for (i = 0; i < height * width; i++)
            {
                /* Computing R */
                R = getchar();

                if (R > max)
                {
                    error();
                    return 0;
                }

                
                /* Computing G */
                G = getchar();

                if (G > max)
                {
                    error();
                    return 0;
                }


                /* Computing B */
                B = getchar();

                if (B > max)
                {
                    error();
                    return 0;
                }


                /* The conversion from RGB to Grayscale is done by the following equation: */
                luminosity = (299*R+587*G+114*B)/1000;
                putchar(luminosity);
            }
            break;

        case '5':            
        /*Converting Grayscale to B/W, for Binary encoding */
            ungetc(ch, stdin);      /* Returning last-received 'ch' character into the standard input stream in order to respect the NetPBM format. */
            endfile = 0;
            j = 0;
            for (k = 0; k < width * height; k++)
            {
                for (i=1; i<=8; i++)
                {    
                    j++;
                    val = getchar();
                
                    if (val == EOF)
                    {
                        endfile = 1;
                        break;
                    }

                    if (val > max)
                    {
                        error();
                        return 0;
                    }

                    if (val > ((max + 1) / 2))
                    {
                        if (i == 1) byte = 0;
                        else byte = byte << 1;
                    }
                    else
                    {
                        if (i == 1) byte = 1;
                        else
                        {
                            byte = byte << 1;
                            byte++;
                        }
                    }

                    
                    if (j == width)
                    {
                        j = 0;

                        if (i = 8)
                        {
                            break;
                        }
                        else
                        {
                            count = 0;
                            while (count != 8 - i)
                            {
                                count++;
                                byte = byte << 1;
                                byte++;
                            }
                            break;
                        }
                    }
                }
                putchar(byte);
                
                if (endfile) break;   
            }
            break;
             
    }
    return 0;
}





void error()
{
    fprintf(stderr, "Input error!\n");
}





int getinteger(int base)
{
    char ch, check;
    int val = 0;
    ch = getchar();
    check = 0;     /* Variable used to check if a value was computed */
    while (!isspace(ch))
    {
        check = 1;
        if (ch >= '0' && ch <= '0' + base - 1)
        {
            val = base * val + (ch - '0');
        }
        else
        {
            return ERROR;
        }
        ch = getchar();
    }
    if (check == 0) return ERROR-1;   /* Returning ERROR-1 since the <do ... while> loops stop for val >= ERROR */
    return val;
}