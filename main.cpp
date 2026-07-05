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

void displayChoice(char choice)
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

void displayWinner(char player, char computer)
{

    if (player == 'r')
    {
        if (computer == 'r')
            cout << "It's a Tie!\n";
        else if (computer == 'p')
            cout << "You Lose!\n";
        else
            cout << "You Win!\n";
    }

    else if (player == 'p')
    {
        if (computer == 'r')
            cout << "You Win!\n";
        else if (computer == 'p')
            cout << "It's a Tie!\n";
        else
            cout << "You Lose!\n";
    }

    else
    {
        if (computer == 'r')
            cout << "You Lose!\n";
        else if (computer == 'p')
            cout << "You Win!\n";
        else
            cout << "It's a Tie!\n";
    }
}

int main()
{

    srand(time(NULL));

    char player;
    char computer;
    char playAgain;

    do
    {

        Title();

        player = UserChoice();

        computer = ComputerChoice();

        cout << "\n------------------------------------\n";
        cout << "Your Choice     : ";
        displayChoice(player);

        cout << "\nComputer Choice : ";
        displayChoice(computer);

        cout << "\n------------------------------------\n\n";

        displayWinner(player, computer);

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
