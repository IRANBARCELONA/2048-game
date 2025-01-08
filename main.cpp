#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int SIZE = 4;
char board[4][4] = {{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
void RandomGenerator()
{

    while (true)
    {
        srand(static_cast<unsigned>(time(0)));
        int randomRow = rand() % 4;
        int randomCol = rand() % 4;
        if (board[randomRow][randomCol] == ' ')
        {
            board[randomRow][randomCol] = '2';
            break;
        }
    }
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

int main()
{
    int row, col;
    RandomGenerator();
    printBoard();
    cout << "Hello, " << '\n';
    // system("pause");
    return 0;
}
