#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int computeBase(int x)
{
    // int ret, base = 4;

    // for(ret = 0; ret <= x; ret++)
    // {
    //     base += (ret + x);
    // }
    // printf("base = %d\n", base);

    int base;
    if(x == 1)
        base = 7;
    if(x == 2)
        base = 13;
    if(x == 3)
        base = 21;
    if(x == 4)
        base = 29;
    if( x == 5)
        base = 39;
    if(x == 6)
        base = 49;   
    if(x == 7)
        base = 61;
    if(x == 8)
        base = 73;
    if(x == 9)
        base = 87;
    return base;
}

void printTriangle(int start, int height, int x, int space)
{

}

void printBase(int baseOfTree, int treeSize)
{
    int j, i, middle;
    
    middle = (baseOfTree + 1) / 2;
    if (treeSize == 4)
        middle = middle - 1;
    if(treeSize == 5)
        middle = middle -2;
    if(treeSize == 9)
        middle = middle - 4;
    for(i = 1; i <= treeSize; i++)
    {
        for(j = 1; j < (middle); j++)
            printf(" ");
        for(j = 1; j <= treeSize; j++)
            printf("|");
        printf("\n");
    }
}

void printTree(int x)
{
    int shrinking = 2, height = 4, startGrowth = 1, growthHeight = 1, space, stars = 2, main;
    int base = computeBase(x);
    int cut = x - (x/2);
    space = (base + 1) / 2;

    for(main = 0; main < x; main++)
    {
        int rows = main + 4;
        int count = startGrowth;
        if(x > 2 && main > 1)
        {
            shrinking++;
            count += 1;
        }
        if (x > 3 && main > 2)
        {
            count += 1;
            //space = space - 2;
        }
        if (x > 4 && main > 3)
        {
            count += 2;
            space = space - 1;
        }
        if(x > 5 && main > 4)
        {
            count += 2;
            shrinking++;
        }
        if(x > 6 && main > 5)
        {
            space = space - 2;
            count += 3;
        }
        if(x > 7 && main > 6)
        {
            space = space - 1;
            count += 3;
        }
        if(x > 8 && main > 7) //Triangle of size 9
        {
            count += 4;
            space = space - 2;
        }
        for(int i = 1; i <= height; i++)
        {
            for(int j = 1; j < space; j++)
                printf(" ");
            space--;
            for(int k = 1; k <= (count * 2) - 1; k++)
            {
                printf("*");
            }
            count++;
            printf("\n");
        }
        height++;
        space += shrinking;
        startGrowth += stars;
    }
    printBase(base, x);
}


int main(int ac, char** av)
{
    //printf("height is = %d\n", atoi(av[1]));
	if(ac > 0)
    {
        int height = atoi(av[1]);
        //printf("we get here\n");
	    printTree(height);
    }
    else printf("please specify the size of the tree");
	return 0;
}
