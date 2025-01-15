#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <fstream>
using namespace std;

#define SIZE 4
enum boardPicker
{
    WalterWhite = 1,
    RedDead = 2
};
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

void printBoardWhite(vector<vector<int>> &board)
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

void reddead()
{
    int x = (rand() % 4) + 1;
    if (x == 1)
        cout << "RED";
    else if (x == 2)
        cout << "    DEAD";
    else if (x == 3)
        cout << "         REDEMPTION";
    else
    {
        cout << "RED DEAD REDEMPTION";
        x = 1;
    }
}
void printBoardArthur(vector<vector<int>> &board)
{
    //int x = 1;
    string h_line = "_____|_____|_____|_____";
    string v_line = "     |     |     |     ";
    string star_line = "***************************";
    string indent = "\t\t\t";                                                          // 4 indent to reach board = 48 space
    cout << indent << "                  ______      " << indent << star_line << endl; //+
    cout << "  _________________ " << "                    /        \\     " << indent << "** " << board[0][0];
    space(board[0][0]);
    cout << "| ";
    cout << board[0][1];
    space(board[0][1]);
    cout << "| " << board[0][2];
    space(board[0][2]);
    cout << "| " << board[0][3];
    space(board[0][3]);
    cout << "**" << endl;
    cout << " |     _____       | " << "               -_ /          \\_-" << indent << "**" << h_line << "**" << endl;
    cout << " |    |     \\      | " << "               \\_______________/  " << indent << "** " << board[1][0];
    space(board[1][0]);
    cout << "| " << board[1][1];
    space(board[1][1]);
    cout << "| " << board[1][2];
    space(board[1][2]);
    cout << "| " << board[1][3];
    space(board[1][1]);
    cout << "**" << endl;
    cout << " |    |   __/      | " << "                 \\|  0` |  0  \\" << indent << "**" << h_line << "**" << endl;
    cout << " |    |    \\       | " << "                  |    '-'    |" << indent << "** " << board[2][0];
    space(board[2][0]);
    cout << "| " << board[2][1];
    space(board[2][1]);
    cout << "| " << board[2][2];
    space(board[2][2]);
    cout << "| " << board[2][3];
    space(board[2][3]);
    cout << "**" << endl;
    cout << " |    |     \\/\\__  | " << "      ______|-|   \\\\\\ //_\\\\ ///" << indent << "**" << h_line << "**" << endl;
    cout << " |         \\    /  | " << "     (_)____   \\ _ \\\\\\\\\\|/////" << indent << "** " << board[3][0];
    space(board[3][0]);
    cout << "| " << board[3][1];
    space(board[3][1]);
    cout << "| " << board[3][2];
    space(board[3][2]);
    cout << "| " << board[3][3];
    space(board[3][3]);
    cout << "**" << endl;
    cout << " |          |/\\|" << "   |           / \\___| \\/\\_     |_ " << indent << "**" << v_line << "**" << endl;
    cout << " |_________________|" << "          /\\  ___|-/   \\_  /   \\_" << "\t\t        " << star_line << endl;
    cout << indent << "      | \\____/ |     \\|       \\ " << "\t      " << endl;
    cout << indent << "       \\______/               | " << "\t            ";
    reddead();
}

void BoardPicker(vector<vector<int>> &board, int pick)
{
    switch (pick)
    {
    case 1:
        printBoardWhite(board);
        break;
    case 2:
        printBoardArthur(board);
        break;
    default:
        break;
    }
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

int highScoreCounter(vector<vector<int>> &board)
{
    int max = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] > max)
                max = board[i][j];
        }
    }
    return max;
}

int main()
{

    vector<vector<int>> board;
    bool RandomValidation = true;
    int theme;
    string filename = "board.txt";
    ifstream load(filename);

    cout << "Welcome to 2048 by RS - Nhtm - MCyber" << endl;
    cout << "Checking saved data ..." << endl;
    usleep(2500000);

    if (load.good())
    {
        cout << "Saved game found! Wanna continue last game? (if not, new game will be started) (y/n) :";
        char ch;
        cin >> ch;
        bool x = true;
        while (x)
        {
            if (ch == 'y')
            {
                cout << "Loading savedgame..." << endl;
                board = LoadSave(filename);
                RandomValidation = false;
                x = false;
                usleep(3000000);
                break;
            }
            else if (ch == 'n')
            {
                board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
                cout << "Pick a board :" << endl;
                cout << "Enter number Breaking Bad(1) , Red Dead Redemption(2) : ";
                cin >> theme;
                x = false;
            
            }
            else
                cout << "what ? (y/n):";
        }
    }
    else
    {
        board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

        cout << "No saved data found." << endl;
        cout << "New Game? (y/n) :";
        char check;
        cin >> check;
        bool x = true;
        while (x)
        {
            if (check == 'y')
            {
                cout << "Pick a board :" << endl;
                cout << "Enter number Breaking Bad(1) , Red Dead Redemption(2) : ";
                
                cin >> theme;
                x = false;
            }

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
        bool cheker = checklose(board);
        if (cheker)
        {
            cout << "You Lost ! ";
            cout << "Your hit is " << highScoreCounter(board) << " !" << endl;
            cout << "Wanna start a new game ? (y/n)";
            char check;
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
        else
            RandomValidation = true;

        system("cls");
        if (RandomValidation)
        {
            RandomGenerator(board);
            BoardPicker(board, theme);
            cout << "\nDo a move (w/s/a/d) : ";
        }
        else
        {
            BoardPicker(board, theme);
            cout << "save and quit by pressing 'q' " << endl;
            if (wrongInput)
                cout << "Invalid input !  (w/s/a/d) : ";
            else
                cout << "\nDo a move (w/s/a/d) : ";
        }

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