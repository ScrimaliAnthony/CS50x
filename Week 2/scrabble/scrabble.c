#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score(string player_word, const int POINTS[]);

int main(void)
{
    // Points assigned to each letter
    const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Get words from the two players
    string player1_word = get_string("Player 1: ");
    string player2_word = get_string("Player 2: ");

    // Calculate scores for each player
    int player1_points = score(player1_word, POINTS);
    int player2_points = score(player2_word, POINTS);

    // Determine and announce the winner
    if (player1_points > player2_points)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2_points > player1_points)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Compute the total score of the player's word
int score(string player_word, const int POINTS[])
{
    // Variable to hold the index of each letter in the POINTS array
    int whatChar;

    // Initialize total score to 0
    int points = 0;

    // Loop through each character in the player's word
    for (int i = 0, len = strlen(player_word); i < len; i++)
    {
        // If the character is uppercase, convert it to lowercase
        if (isupper(player_word[i]))
        {
            player_word[i] = player_word[i] + 32;
        }

        // calculate the index of the letter
        whatChar = player_word[i] - 'a';

        // Add the corresponding point value to the total score
        points += POINTS[whatChar];
    }
    return points;
}
