#include <iostream>
#include <ctime>
using namespace std;

char UserChoice()
{
    char player;
    cout << "Rock-Paper-Scissors Game!\n";
    do
    {
        cout << "-------------------------\n";
        cout << "Choose one of the following:\n";
        cout << "Enter 'r' for rock\n";
        cout << "Enter 'p' for paper\n";
        cout << "Enter 's' for scissors\n";
        cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char ComputerChoice()
{
    srand(time(NULL));
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
    return 0;
}
void showChoice(char choice)
{
    switch (choice)
    {
    case 'r':
        cout << "Rock\n";
        break;
    case 'p':
        cout << "Paper\n";
        break;
    case 's':
        cout << "Scissors\n";
        break;
    }
}
void Winner(char player, char computer)
{
    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            cout << "It's a tie!\n";
        }
        else if (computer == 'p')
        {
            cout << "You lose!\n";
        }
        else
        {
            cout << "You win!\n";
        }
        break;
    case 'p':
        if (computer == 'r')
        {
            cout << "You win!\n";
        }
        else if (computer == 'p')
        {
            cout << "It's a tie!\n";
        }
        else
        {
            cout << "You lose!\n";
        }
        break;
    case 's':
        if (computer == 'r')
        {
            cout << "You lose!\n";
        }
        else if (computer == 'p')
        {
            cout << "You win!\n";
        }
        else
        {
            cout << "It's a tie!\n";
        }
        break;
    }
}

int main()
{
    char player;
    char computer;

    player = UserChoice();
    cout << "Your choice: ";
    showChoice(player);

    computer = ComputerChoice();
    cout << "Computer's Choice: ";
    showChoice(computer);

    Winner(player, computer);
    return 0;
}
