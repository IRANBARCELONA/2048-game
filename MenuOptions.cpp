#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <fstream>
using namespace std;

#define SIZE 4

// Game operators
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
void RandomGenerator(vector<vector<int>> &board)
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

// Board drawing
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
void printBoard(vector<vector<int>> &board)
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

// Movements
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

// Saving methods
void SaveBoard(vector<vector<int>> &board, string &filename)
{
    ofstream load(filename);
    if (load.is_open())
    {
        for (auto &row : board)
        {
            for (int &number : row)
            {
                load << number << " ";
            }
            load << endl;
        }

        load.close();
    }
    else
    {
        cerr << "The game can not be saved ! " << endl;
    }
}
vector<vector<int>> LoadSave(string &filename)
{
    vector<vector<int>> board(SIZE, vector<int>(SIZE));
    ifstream load(filename);
    if (load.is_open())
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                load >> board[i][j];
            }
        }
        load.close();
        return board;
    }
    else
    {
        cerr << "Save not found ! " << endl;
    }
}

int main()
{

    vector<vector<int>> board;
    bool RandomValidation = true;

    string filename = "board.txt";
    ifstream load(filename);
    if (load.good())
    {
        cout << "Loading savedgame..." << endl;
        board = LoadSave(filename);
        RandomValidation = false;
        usleep(3000000);
    }
    else
    {
        board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
        char check;
        cout << "No saved game." << endl;
        cout << "New Game? (y/n) :";
        cin >> check;
        bool x = true;
        while (x)
        {
            if (check == 'y')
                x = false;
            else if (check == 'n')
            {
                cout << "Bye my friend ...." << endl;
                usleep(3000000);
                return EXIT_SUCCESS;
            }
            else
                cout << "what ? (y/n):";
        }
    }
    bool wrongInput = false;
    while (true)
    {
        system("cls");
        if (RandomValidation)
        {
            RandomGenerator(board);
            printBoard(board);
            cout << "\nDo a move (w/s/a/d) : ";
        }
        else
        {
            printBoard(board);
            cout << "save and quit by pressing 'q' " <<endl;
            if (wrongInput)
                cout << "Invalid input !  (w/s/a/d) : ";
            else
                cout << "\nDo a move (w/s/a/d) : ";
            
        }

        bool cheker = checklose(board);
        if (cheker)
        {
            cout << "You Lost ! ";

            return 0;
        }
        else
            RandomValidation = true;

        // get input
        char PlayerMovement = ' ';
        cin >> PlayerMovement;

        if (PlayerMovement == 'w')
        {
            MoveUp(board);
            RandomValidation = true;
        }
        else if (PlayerMovement == 's')
        {
            MoveDown(board);
            RandomValidation = true;
        }
        else if (PlayerMovement == 'a')
        {
            MoveLeft(board);
            RandomValidation = true;
        }
        else if (PlayerMovement == 'd')
        {
            MoveRight(board);
            RandomValidation = true;
        }
        else if (PlayerMovement == 'q')
        {
            SaveBoard(board, filename);
            return 0;
        }
        else
        {
            RandomValidation = false;
            wrongInput = true;
        }
    }

    return 0;
}