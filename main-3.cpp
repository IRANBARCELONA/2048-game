#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int SIZE = 4;
vector<vector<int>> board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
bool checklose(vector<vector<int>> &board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
                return false;
            if (j < SIZE - 1 && board[i][j] == board[i][j + 1])
                return false;
            if (i < SIZE - 1 && board[i][j] == board[i + 1][j])
                return false;
        }
    }
    return true;
}

void RandomGenerator()
{
srand(static_cast<unsigned>(time(0)));
    while (true)
    {
        int randomRow = rand() % 4;
        int randomCol = rand() % 4;
        if (board[randomRow][randomCol] == 0)
        {
            board[randomRow][randomCol] = 2;
            break;
        }
    }
}

void snow()
{
    int r = rand() % 23;
    for (int i = 0; i < 23; i++)
    {
        if (i == r)
            cout << "*";
        cout << " ";
    }
}
void space(int a)
{
    int n = 0, ox = a;
    while (a > 0)
    {
        n++;
        a /= 10;
    }
    if (ox != 0)
    {
        for (int i = 0; i < 4 - n; i++)
            cout << " ";
    }
    else
        cout << "   ";
}
void printBoard()
{
    string h_line = "_____|_____|_____|_____";
    string v_line = "     |     |     |     ";
    string star_line = "***************************";
    string indent = "\t\t\t";                                                          // 4 indent to reach board = 48 space
    cout << indent << "  &&                          " << indent << star_line << endl; //+
    cout << " /\\   /\\    \\  /  " << "        &&&&      mmm               " << indent << "** " << board[0][0];
    space(board[0][0]);
    cout << "| ";
    cout << board[0][1];
    space(board[0][1]);
    cout << "| " << board[0][2];
    space(board[0][2]);
    cout << "| " << board[0][3];
    space(board[0][3]);
    cout << "**" << endl;
    cout << " \\   /__\\    \\/      " << "     &&  &         mmm          m" << indent << "**" << h_line << "**" << endl;
    cout << "  \\ /    \\   /          " << "   &  &      | ---- \\     /--" << indent << "** " << board[1][0];
    space(board[1][0]);
    cout << "| " << board[1][1];
    space(board[1][1]);
    cout << "| " << board[1][2];
    space(board[1][2]);
    cout << "| " << board[1][3];
    space(board[1][1]);
    cout << "**" << endl;
    cout << " \\//      \\ /           " << "   && &      |  &&   |&& |  &&" << indent << "**" << h_line << "**" << endl;
    cout << indent << "    & &      \\      /     \\    " << indent << "** " << board[2][0];
    space(board[2][0]);
    cout << "| " << board[2][1];
    space(board[2][1]);
    cout << "| " << board[2][2];
    space(board[2][2]);
    cout << "| " << board[2][3];
    space(board[2][3]);
    cout << "**" << endl;
    cout << " \\      /   \\   /       " << "     &&         ----         --" << indent << "**" << h_line << "**" << endl;
    cout << " |\\    /|    \\ /        " << "      &            /       \\   " << indent << "** " << board[3][0];
    space(board[3][0]);
    cout << "| " << board[3][1];
    space(board[3][1]);
    cout << "| " << board[3][2];
    space(board[3][2]);
    cout << "| " << board[3][3];
    space(board[3][3]);
    cout << "**" << endl;
    cout << " | \\  / |     /         " << "       \\            \\     / " << indent << "**" << v_line << "**" << endl;
    cout << " |  \\/  |    /          " << "        \\        ///////\\\\\\\\\\" << "\t\t       " << "*                           *" << endl;
    cout << indent << "       _/\\      ////////\\\\\\\\\\" << "\t\t      " << "*                             *" << endl;
    cout << " \\   |    /\\    \\     / -----" << " /   \\     ||  _______" << "\t\t     " << "*    ";
    snow();
    cout << "   *" << endl;
    cout << " |\\  |   /__\\   |\\   /| |__ " << "_/     |    ||         " << "\t\t     " << "*                               *" << endl;
    cout << " | \\ |  /    \\  | \\ / | |  " << "/       \\     \\\\\\\\\\\\\\/////" << "\t\t     " << "*                               *" << endl;
    cout << " |  \\| /      \\ |  /  | |----" << indent << "\t\t     ******" << star_line;
    cout << "\n\n";
}

void MoveLeft(vector<vector<int>> &board)
{
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                if (board[k][j] == 0 && board[k][j + 1] != 0)
                {
                    swap(board[k][j], board[k][j + 1]);
                }
            }
        }
        for (int j = 0; j < SIZE - 1; j++)
        {
            if (board[k][j] == board[k][j + 1] && board[k][j] != 0)
            {
                board[k][j] *= 2;
                board[k][j + 1] = 0;
            }
        }
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                if (board[k][j] == 0 && board[k][j + 1] != 0)
                {
                    swap(board[k][j], board[k][j + 1]);
                }
            }
        }
    }
}

void MoveRight(vector<vector<int>> &board)
{
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = SIZE - 1; i > 0; i--)
        {
            for (int j = SIZE - 1; j > 0; j--)
            {
                if (board[k][j] == 0 && board[k][j - 1] != 0)
                {
                    swap(board[k][j], board[k][j - 1]);
                }
            }
        }
        for (int j = SIZE - 1; j > 0; j--)
        {
            if (board[k][j] == board[k][j - 1] && board[k][j] != 0)
            {
                board[k][j] *= 2;
                board[k][j - 1] = 0;
            }
        }
        for (int i = SIZE - 1; i > 0; i--)
        {
            for (int j = SIZE - 1; j > 0; j--)
            {
                if (board[k][j] == 0 && board[k][j - 1] != 0)
                {
                    swap(board[k][j], board[k][j - 1]);
                }
            }
        }
    }
}

void MoveUp(vector<vector<int>> &board)
{
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int k = 0; k < SIZE - 1; k++)
            {
                if (board[k][j] == 0 && board[k + 1][j] != 0)
                {
                    swap(board[k][j], board[k + 1][j]);
                }
            }
        }
        for (int i = 0; i < SIZE - 1; i++)
        {
            if (board[i][j] == board[i + 1][j] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i + 1][j] = 0;
            }
        }
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int k = 0; k < SIZE - 1; k++)
            {
                if (board[k][j] == 0 && board[k + 1][j] != 0)
                {
                    swap(board[k][j], board[k + 1][j]);
                }
            }
        }
    }
}

void MoveDown(vector<vector<int>> &board)
{
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = SIZE - 1; i > 0; i--)
        {
            for (int k = SIZE - 1; k > 0; k--)
            {
                if (board[k][j] == 0 && board[k - 1][j] != 0)
                {
                    swap(board[k][j], board[k - 1][j]);
                }
            }
        }
        for (int i = SIZE - 1; i > 0; i--)
        {
            if (board[i][j] == board[i - 1][j] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
            }
        }
        for (int i = SIZE - 1; i > 0; i--)
        {
            for (int k = SIZE - 1; k > 0; k--)
            {
                if (board[k][j] == 0 && board[k - 1][j] != 0)
                {
                    swap(board[k][j], board[k - 1][j]);
                }
            }
        }
    }
}
// void invalidInput(bool &Gogame)
// {
//     cout << "INVALID INPUT !" << endl;
//     Gogame = false;
//     usleep(5000000);
// }
int main()
{
    // char sure = ' ';
    bool goGame = true;
    while (true)
    {
        if (goGame == true)
        {
            RandomGenerator();
        }
        system("cls");
        printBoard();
        bool chaker = checklose(board);
        if (chaker)
        {
            cout << "fukin lost";
            return 0;
        }

        else
            goGame = true;

        char PlayerMovement = ' ';
        cout << "Do a move (w/s/a/d) : ";
        cin >> PlayerMovement;
        switch (PlayerMovement)
        {
        case 'd':
            MoveRight(board);
            break;
        case 's':
            MoveDown(board);
            break;
        case 'a':
            MoveLeft(board);
            break;
        case 'w':
            MoveUp(board);
            break;
        default:
            cout << "INVALID INPUT !" << endl;
            break;
        }
    }

    return 0;
}
