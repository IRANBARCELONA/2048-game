#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
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

    while (true)
    {
        srand(static_cast<unsigned>(time(0)));
        int randomRow = rand() % 4;
        int randomCol = rand() % 4;
        if (board[randomRow][randomCol] == 0)
        {
            board[randomRow][randomCol] = 2;
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
void invalidInput(bool &Gogame)
{
    cout << "INVALID INPUT !" << endl;
    Gogame = false;
    this_thread::sleep_for(std::chrono::seconds(2));
}
// void QuitGame(bool &Gogame)
// {
//     Gogame = false;
//     string sure;
//     cout << "Are sure to exit? (yes/no)";
//     cin >> sure;
//     if (sure == "yes")
//     {
        
//     }
//     else if (sure == "no")
//     {
//         /* code */
//     }
    
    
// }
int main()
{
    
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
        case 'q':
            return 0;
            break;
        default:
            invalidInput(goGame);
            break;
        }
    }

    return 0;
}