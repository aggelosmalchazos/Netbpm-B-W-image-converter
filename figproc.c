#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{

    int p1 = getchar();
    int p2 = getchar();
    int typeP = p2 - 48;
    if (p1 == 80)
    {

        if (p2 > 49 && p2 <= 54 && p2 != 52)
        {
            int temp = p2 - 1;
            putchar(p1);
            putchar(temp);
        }
        else
        {
            printf("INPUT ERROR!\n");
            exit(0);
        }
    }
    else
    {
        printf("INPUT ERROR!\n");
        exit(0);
    }
    // printf("%d %d\n", p1, p2);

    int ch;
    int space;
    do
    {
        ch = getchar();
        space = isspace(ch);
        if (space != 0 || ch == 35)
        {
            putchar(ch);
        }
    } while (space != 0);

    int diesi = 0;
    do
    {
        if (ch == 35)
        {
            diesi = 1;
            do
            {
                ch = getchar();
                putchar(ch);
                if (ch == EOF)
                {
                    printf("INPUT ERROR!\n");
                    exit(0);
                }
            } while (ch != 10);
            ch = getchar();
            // putchar(ch);
            diesi = 0;
            if (ch == 35)
            {
                putchar(ch);
                diesi = 1;
            }
        }
    } while (diesi == 1);
    /// feygontas apo edw ch=10

    // read width of image

    int tnum = 0;
    space = isspace(ch);
    while (space == 0)
    {
        putchar(ch);
        ch -= 48;
        if (ch < 0 || ch > 9)
        {
            printf("INPUT ERROR!\n"); // if ch is not number between 0-9
            exit(0);
        }
        tnum = tnum * 10 + ch;
        ch = getchar();
        space = isspace(ch);
    }
    int width = tnum;

    putchar(ch);
    do
    {
        ch = getchar();
        space = isspace(ch);
    } while (space != 0);

    // diabazw mhkos

    tnum = 0;
    space = isspace(ch);
    while (space == 0)
    {
        ch -= 48;
        if (ch < 0 || ch > 9)
        {
            printf("INPUT ERROR!\n"); // if ch is not number between 0-9
            exit(0);
        }
        tnum = tnum * 10 + ch;
        ch = getchar();
        space = isspace(ch);
    }
    int height = tnum;
    printf("%d\n", height);

    // pernaw apo white space
    do
    {
        ch = getchar();
        if (isspace(ch) != 0)
        {
            putchar(ch); // gia na mhn ektypwnei kai char
        }
        space = isspace(ch);
    } while (space != 0);

    if (typeP == 2 || typeP == 3|| typeP == 5 || typeP == 6 )
    {

        tnum = 0;
        space = isspace(ch);
        while (space == 0)
        {
            ch -= 48;
            if (ch < 0 || ch > 9)
            {
                printf("INPUT ERROR!\n"); // if ch is not number between 0-9
                exit(0);
            }
            tnum = tnum * 10 + ch;
            ch = getchar();
            space = isspace(ch);
        }
    }

    int max;
    if (typeP == 3 || typeP == 6 || typeP == 2 || typeP == 5)
    {
        max = tnum;
    }
    if (ch == EOF)
    {
        printf("INPUT ERROR!\n"); // if data has ended before pixel data
        exit(0);
    }
    if (typeP == 3)
    {
        printf("%d\n", max);
        while (ch != EOF)
        {
            int temp = 0;
            do
            {
                ch = getchar();

                space = isspace(ch);
            } while (space != 0);

            int c1 = ch;
            c1 -= 48;

            int c2, c3;
            ch = getchar();
            space = isspace(ch);
            int R;
            if (space == 0)
            {
                c2 = ch;
                c2 -= 48;
                ch = getchar();
                space = isspace(ch);

                if (space == 0)
                {
                    c3 = ch;
                    c3 -= 48;
                    R = (c1 * 100) + (c2 * 10) + c3;
                }
            }
            else
            {
                R = c1;
            }

            do
            {
                ch = getchar();
                space = isspace(ch);
            } while (space != 0);

            c1 = ch;
            if (isdigit(c1) == 0 && c1 != EOF)
            {
                printf("INPUT ERROR!\n"); // if data has ended before pixel data
                exit(0);
            }
            c1 -= 48;
            c2, c3;
            ch = getchar();
            space = isspace(ch);

            int G;
            if (space == 0)
            {
                c2 = ch;
                if (isdigit(c2) == 0 && c2 != EOF)
                {
                    printf("INPUT ERROR!\n"); // if data has ended before pixel data
                    exit(0);
                }
                c2 -= 48;
                ch = getchar();
                space = isspace(ch);

                if (space == 0)
                {
                    c3 = ch;
                    if (isdigit(c3) == 0 && c3 != EOF)
                    {
                        printf("INPUT ERROR!\n"); // if data has ended before pixel data
                        exit(0);
                    }
                    c3 -= 48;
                    G = (c1 * 100) + (c2 * 10) + c3;
                }
                else
                {
                    G = (c1 * 10) + (c2);
                }
            }
            else
            {
                G = c1;
            }
            do
            {
                ch = getchar();
                space = isspace(ch);
            } while (space != 0);

            c1 = ch;
            c1 -= 48;
            c2, c3;
            ch = getchar();
            space = isspace(ch);
            int B;
            if (space == 0)
            {
                c2 = ch;
                c2 -= 48;
                ch = getchar();
                space = isspace(ch);

                if (space == 0)
                {
                    c3 = ch;
                    c3 -= 48;
                    B = (c1 * 100) + (c2 * 10) + c3;
                }
                else
                {
                    B = (c1 * 10) + (c2);
                }
            }
            else
            {
                B = c1;
            }
          
                if (R > max || G > max || B > max)
                {
                    printf("INPUT ERROR!\n"); // if data has ended before pixel data
                    exit(0);
                }
                else
                {
                    int pix = (299 * R + 587 * G + 114 * B) / 1000;
                    printf("%d ", pix);
                }
            
        }
    }

    if (typeP == 2)
    {
        
        int temp = 0;
        while (ch != EOF)
        {
            do
            {
                ch = getchar();
                space = isspace(ch);
            } while (space != 0);

            int c1 = ch;
            c1 -= 48;
            int c2, c3;
            ch = getchar();
            space = isspace(ch);
            int G;
            if (space == 0)
            {
                c2 = ch;
                c2 -= 48;
                ch = getchar();
                space = isspace(ch);

                if (space == 0)
                {
                    c3 = ch;
                    c3 -= 48;
                    G = (c1 * 100) + (c2 * 10) + c3;
                }
                else
                {
                    G = (c1 * 10) + (c2);
                }
            }
            else
            {
                G = c1;
            }
            if (G > max)
            {
                printf("INPUT ERROR!\n"); // if data has ended before pixel data
                exit(0);
            }
            else
            {temp++;
                if (G > (max + 1) / 2)
                {
                    int pix = '0';
                    putchar(pix);
                    putchar(32);
                }
                else
                {
                    int pix = '1';
                    putchar(pix);
                    putchar(32);
                }
                if (G==EOF && temp<height*width){
                 printf("INPUT ERROR!\n"); // if data has ended before pixel data
                exit(0);
            }
            }
            
        }
    }

    int k;
    if (typeP == 6)
    {
          if (max>255){
             
                    printf("INPUT ERROR!\n"); // if data has ended before pixel data
                    exit(0);
               
        }
        printf("%d ", max);
        int R, G, B;
        for (int i = 1; i <= height; i++)
        {
            for (int k = 1; k <= width; k++)
            {

                R = getchar();
                G = getchar();
                B = getchar();
              
             //   int digit=isdigit(R)+isdigit(B)+isdigit(G); //checks if R,G, or B is digit. If they are not digits, they could be spaces etc.
                if ((R > max) || (G > max) || (B > max)||(R==EOF)||(G==EOF)||(B==EOF))
                {
                    printf("INPUT ERROR! digitdigitidigit\n"); // if data has ended before pixel data
                    exit(0);
                }
                else
                {
                    int pixel = (299 * R + 587 * G + 114 * B) / 1000;
                   putchar(pixel);
                }
            
            }
        }

    }

    if (typeP == 5)
    {
        if (max>255){
             
                    printf("INPUT ERROR!\n"); // if data has ended before pixel data
                    exit(0);
               
        }

        char binary;
        for (int i = 1; i <= height; i++)
        {

            for (int k = 1; k <= width; k++)
            {
                ch = getchar();
                if (ch >max || ch < 0)
                {
                    printf("INPUT ERROR!\n"); // if data has ended before pixel data
                    exit(0);
                }
                if (ch > (max + 1) / 2)
                {
                    binary = binary * 2 + 0;
                }
                else
                {
                    binary = binary * 2 + 1;
                }
                if (k % 8 == 0)
                {
                    putchar(binary);
                }
                if (width % 8 != 0)
                {
                    if (k == width)
                    {
                        for (int i = 1; i <= 8 - (width % 8); i++)
                        {
                            binary = (binary * 2) + 1;
                        }
                        putchar(binary);
                    }
                }
            }
        }
        ch=getchar();
        if (ch!=EOF){
                    printf("INPUT ERROR!\n"); // if data has ended before pixel data
                    exit(0);
        }
    }
}
