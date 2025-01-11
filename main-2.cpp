#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 4;
char board[SIZE][SIZE] = {{'0', '0', '0', '0'}, {'0', '0', '0', '0'}, {'0', '0', '0', '0'}, {'0', '0', '0', '0'}};

void RandomGenerator()
{
    srand(static_cast<unsigned>(time(0)));
    int randomRow = rand() % 4;
    int randomCol = rand() % 4;
    board[randomRow][randomCol] = '2';
}
void printBoard()
{

    string h_line = "_____|_____|_____|_____";
    string v_line = "     |     |     |     ";
    string star_line = "***************************";
    string indent = "\t\t\t"; // 4 indent to reach board = 48 space
    cout << indent << indent << indent << star_line << endl;
    cout << indent << indent << indent << "**  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |  " << board[0][3] << "  **" << endl;
    cout << indent << indent << indent << "**" << h_line << "**" << endl;
    cout << indent << indent << indent << "**  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |  " << board[1][3] << "  **" << endl;
    cout << indent << indent << indent << "**" << h_line << "**" << endl;
    cout << indent << indent << indent << "**  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |  " << board[2][3] << "  **" << endl;
    cout << indent << indent << indent << "**" << h_line << "**" << endl;
    cout << indent << indent << indent << "**  " << board[3][0] << "  |  " << board[3][1] << "  |  " << board[3][2] << "  |  " << board[3][3] << "  **" << endl;
    cout << indent << indent << indent << "**" << v_line << "**" << endl;
    cout << indent << indent << indent << star_line << endl;
}

void MoveLeft(char board[SIZE][SIZE])
{
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                if (board[k][j] == '0' && board[k][j + 1] != '0')
                {
                    swap(board[k][j], board[k][j + 1]);
                }
            }
        }
        for (int j = 0; j < SIZE - 1; j++)
        {
            if (board[k][j] == board[k][j + 1] && board[k][j] != '0')
            {
                board[k][j] *= 2;
                board[k][j + 1] = '0';
            }
        }
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                if (board[k][j] == '0' && board[k][j + 1] != '0')
                {
                    swap(board[k][j], board[k][j + 1]);
                }
            }
        }
    }
}

void MoveRight(char board[SIZE][SIZE])
{
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = SIZE - 1; i > 0; i--)
        {
            for (int j = SIZE - 1; j > 0; j--)
            {
                if (board[k][j] == '0' && board[k][j - 1] != '0')
                {
                    swap(board[k][j], board[k][j - 1]);
                }
            }
        }
        for (int j = SIZE - 1; j > 0; j--)
        {
            if (board[k][j] == board[k][j - 1] && board[k][j] != '0')
            {
                board[k][j] *= 2;
                board[k][j - 1] = '0';
            }
        }
        for (int i = SIZE - 1; i > 0; i--)
        {
            for (int j = SIZE - 1; j > 0; j--)
            {
                if (board[k][j] == '0' && board[k][j - 1] != '0')
                {
                    swap(board[k][j], board[k][j - 1]);
                }
            }
        }
    }
}

void MoveUp(char board[SIZE][SIZE])
{
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int k = 0; k < SIZE - 1; k++)
            {
                if (board[k][j] == '0' && board[k + 1][j] != '0')
                {
                    swap(board[k][j], board[k + 1][j]);
                }
            }
        }
        for (int i = 0; i < SIZE - 1; i++)
        {
            if (board[i][j] == board[i + 1][j] && board[i][j] != '0')
            {
                board[i][j] *= 2;
                board[i + 1][j] = '0';
            }
        }
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int k = 0; k < SIZE - 1; k++)
            {
                if (board[k][j] == '0' && board[k + 1][j] != '0')
                {
                    swap(board[k][j], board[k + 1][j]);
                }
            }
        }
    }
}

void MoveDown(char board[SIZE][SIZE])
{
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = SIZE - 1; i > 0; i--)
        {
            for (int k = SIZE - 1; k > 0; k--)
            {
                if (board[k][j] == '0' && board[k - 1][j] != '0')
                {
                    swap(board[k][j], board[k - 1][j]);
                }
            }
        }
        for (int i = SIZE - 1; i > 0; i--)
        {
            if (board[i][j] == board[i - 1][j] && board[i][j] != '0')
            {
                board[i][j] *= 2;
                board[i - 1][j] = '0';
            }
        }
        for (int i = SIZE - 1; i > 0; i--)
        {
            for (int k = SIZE - 1; k > 0; k--)
            {
                if (board[k][j] == '0' && board[k - 1][j] != '0')
                {
                    swap(board[k][j], board[k - 1][j]);
                }
            }
        }
    }
}

int main()
{
    RandomGenerator();
    printBoard();
   
    // cout << "Hello, " << '\n';
    // system("pause");
    return 0;
}
