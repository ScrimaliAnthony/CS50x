#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int twentyFiveCents, twentyCents, tenCents, fiveCents, oneCents, changeOwed, change,
        howManyPiecies;

    twentyFiveCents = 25;
    twentyCents = 20;
    tenCents = 10;
    fiveCents = 5;
    oneCents = 1;
    change = 0;
    howManyPiecies = 0;
    changeOwed = -1;

    while (changeOwed < 0)
    {
        changeOwed = get_int("Change owed: ");
    }

    while (change != changeOwed)
    {
        if (change + twentyFiveCents <= changeOwed)
        {
            change += twentyFiveCents;
            howManyPiecies++;
        }
        else if (change + twentyCents <= changeOwed)
        {
            change += twentyCents;
            howManyPiecies++;
        }
        else if (change + tenCents <= changeOwed)
        {
            change += tenCents;
            howManyPiecies++;
        }
        else if (change + fiveCents <= changeOwed)
        {
            change += fiveCents;
            howManyPiecies++;
        }
        else if (change + oneCents <= changeOwed)
        {
            change += oneCents;
            howManyPiecies++;
        }
    }
    printf("%i\n", howManyPiecies);
}
