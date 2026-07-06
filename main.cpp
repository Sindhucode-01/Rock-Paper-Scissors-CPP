#include <iostream>
#include <ctime>
using namespace std;

void Title()
{
    cout << "\n====================================\n";
    cout << "      ROCK PAPER SCISSORS\n";
    cout << "====================================\n";
}

char UserChoice()
{
    char player;

    do
    {
        cout << "\nChoose your move:\n";
        cout << "[r] Rock\n";
        cout << "[p] Paper\n";
        cout << "[s] Scissors\n";
        cout << "Enter your choice: ";
        cin >> player;

        if (player != 'r' && player != 'p' && player != 's')
        {
            cout << "\nInvalid choice! Please enter r, p, or s.\n";
        }

    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char ComputerChoice()
{
    int num = rand() % 3 + 1;

    switch (num)
    {
    case 1:
        return 'r';
    case 2:
        return 'p';
    case 3:
        return 's';
    }

    return ' ';
}

void ShowChoice(char choice)
{
    switch (choice)
    {
    case 'r':
        cout << "Rock";
        break;
    case 'p':
        cout << "Paper";
        break;
    case 's':
        cout << "Scissors";
        break;
    }
}

char displayWinner(char player, char computer)
{
    if (player == 'r')
    {
        if (computer == 'r')
        {
            cout << "It's a Tie!\n";
            return 'D';
        }
        else if (computer == 'p')
        {
            cout << "You Lose!\n";
            return 'L';
        }
        else
        {
            cout << "You Win!\n";
            return 'W';
        }
    }

    else if (player == 'p')
    {
        if (computer == 'r')
        {
            cout << "You Win!\n";
            return 'W';
        }
        else if (computer == 'p')
        {
            cout << "It's a Tie!\n";
            return 'D';
        }
        else
        {
            cout << "You Lose!\n";
            return 'L';
        }
    }

    else
    {
        if (computer == 'r')
        {
            cout << "You Lose!\n";
            return 'L';
        }
        else if (computer == 'p')
        {
            cout << "You Win!\n";
            return 'W';
        }
        else
        {
            cout << "It's a Tie!\n";
            return 'D';
        }
    }
}

void displayScore(int wins, int losses, int draws)
{
    cout << "\n------------- SCORE -------------\n";
    cout << "Wins   : " << wins << endl;
    cout << "Losses : " << losses << endl;
    cout << "Draws  : " << draws << endl;
    cout << "---------------------------------\n";
}

int main()
{
    srand(time(NULL));

    char player;
    char computer;
    char playAgain;
    char result;

    int wins = 0;
    int losses = 0;
    int draws = 0;

    do
    {
        Title();

        player = UserChoice();
        computer = ComputerChoice();

        cout << "\n------------------------------------\n";
        cout << "Your Choice     : ";
        ShowChoice(player);

        cout << "\nComputer Choice : ";
        ShowChoice(computer);

        cout << "\n------------------------------------\n\n";

        result = displayWinner(player, computer);

        if (result == 'W')
            wins++;
        else if (result == 'L')
            losses++;
        else
            draws++;

        displayScore(wins, losses, draws);

        do
        {
            cout << "\nPlay again? (y/n): ";
            cin >> playAgain;

            if (playAgain != 'y' && playAgain != 'Y' &&
                playAgain != 'n' && playAgain != 'N')
            {
                cout << "Invalid choice! Please enter y or n.\n";
            }

        } while (playAgain != 'y' && playAgain != 'Y' &&
                 playAgain != 'n' && playAgain != 'N');

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n====================================\n";
    cout << "Thanks for playing!\n";
    cout << "====================================\n";

    return 0;
}
