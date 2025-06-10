#include <cs50.h>
#include <stdio.h>

void pyramid(int height);

int main(void)
{
    int height;

    height = 0;
    while (height <= 0)
    {
        height = get_int("Height: ");
    }

    pyramid(height);
}

void pyramid(int height)
{
    int turn;

    turn = 1;
    for (int i = 0; i < height; i++)
    {

        for (int j = turn; j < height; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < turn; k++)
        {
            printf("#");
        }
        printf("\n");
        turn++;
    }
}
