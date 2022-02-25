#include <stdio.h>
#include <stdlib.h>

int my_square(int param_1, int param_2)
{
    char corner = 111;
    char wide = 45;
    char side = 124;
    int width = (param_1 - 1);
    int depth = (param_2 - 1);
//   printf("the square will be %d deep, and %d wide.\n", depth, width);

    if (param_1 < 0 || param_2 < 0)
    {
        printf("Your input was incorrect!");
        return 0;
    }
    for (int n = 0; n <= depth; n++)
    {
        if (n == 0)
        {
            for (int i = 0; i <= width; i++)
            {
                if (i == 0)
                    printf("%c", corner);
                if (i > 0 && i < width)
                    printf("%c", wide);
                if (i == width -1)
                    printf("%c\n", corner);
            }
        }
        if (n > 0 && n < depth)        
        {
            for (int y = 0; y < width; y++)
            {
                if (y == 0)
                    printf("%c", side);
                if (y > 0 && y < width)
                    printf(" ");
                if (y == width - 1)
                    printf ("%c\n", side);
            }
        }
        if (n == depth - 1)
        {
            for (int i = 0; i < width; i++)
            {
                if (i == 0)
                    printf("%c", corner);
                if (i > 0 && i < width)
                    printf("%c", wide);
                if (i == width - 1)
                    printf("%c\n", corner);
            } 
        }        
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
    return 0;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

  my_square(x, y);
}