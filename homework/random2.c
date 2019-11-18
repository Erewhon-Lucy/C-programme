#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SIZE 12

int main()
{
    char a[SIZE][SIZE], character='A';
    int i,j,direct;

    for ( i = 0; i < SIZE; i++)
    {
        for ( j = 0; j < SIZE; j++)
        {
            if (i == 0 || i == SIZE - 1 || j == SIZE - 1)
            {
                a[i][j] = '#';
            }
            else
            {
                a[i][j] = '-';
            }
            
        }
        
    }
    i = 1;
    j = 1;
    a[i][j] = 'A';
    character = 'B';

    srand ((unsigned) time (NULL));

    while (character <= 'Z')
    {
        direct = rand()%4;
        if (direct == UP && a[i - 1][j] == '-')
        {
            i --;
            a[i][j] = character;
            character++;
        }
        else if (direct == DOWN && a[i + 1][j] == '-') 
        {
            i++;
            a[i][j] = character;
            character++;
        }
        else if (direct == LEFT && a[i][j - 1] == '-')
        {
            j --;
            a[i][j] = character;
            character++;
        }
        else if (direct == RIGHT && a[i][j + 1] == '-')
        {
            j++;
            a[i][j] = character;
            character++;
        }
        if (a[i - 1][j] != '-' && a[i + 1][j] != '-' && a[i][j - 1] != '-' && a[i][j - 1] != '-')
        {
            break;
        }
    }
    for ( i = 1; i < SIZE - 1; i++)
    {
        for ( i = 1; i < SIZE - 1; i++)
        {
            printf("%3c", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}