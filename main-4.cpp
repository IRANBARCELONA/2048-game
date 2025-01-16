#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <unistd.h>
#include <fstream>
using namespace std;

#define SIZE 4

string getColor(int number)
{
    switch (number)
    {
    case 2:
        return "\033[1;31m";
    case 4:
        return "\033[1;32m";
    case 8:
        return "\033[1;33m";
    case 16:
        return "\033[1;34m";
    case 32:
        return "\033[1;35m";
    case 64:
        return "\033[1;36m";
    case 128:
        return "\033[0;35m";
    case 256:
        return "\033[0;31m";
    case 512:
        return "\033[0;32m";
    case 1024:
        return "\033[0;33m";
    case 2048:
        return "\033[0;34m";
    default:
        return "\033[0m";
    }
}

string resetColor()
{
    return "\033[0m";
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
    cout << " /\\   /\\    \\  /  " << "        &&&&      mmm               " << indent << "** " << getColor(board[0][0]) << board[0][0] << resetColor();
    space(board[0][0]);
    cout << "| ";
    cout << getColor(board[0][1]) << board[0][1] << resetColor();
    space(board[0][1]);
    cout << "| " << getColor(board[0][2]) << board[0][2] << resetColor();
    space(board[0][2]);
    cout << "| " << getColor(board[0][3]) << board[0][3] << resetColor();
    space(board[0][3]);
    cout << "**" << endl;
    cout << " \\   /__\\    \\/      " << "     &&  &         mmm          m" << indent << "**" << h_line << "**" << endl;
    cout << "  \\ /    \\   /          " << "   &  &      | ---- \\     /--" << indent << "** " << getColor(board[1][0]) << board[1][0] << resetColor();
    space(board[1][0]);
    cout << "| " << getColor(board[1][1]) << board[1][1] << resetColor();
    space(board[1][1]);
    cout << "| " << getColor(board[1][2]) << board[1][2] << resetColor();
    space(board[1][2]);
    cout << "| " << getColor(board[1][3]) << board[1][3] << resetColor();
    space(board[1][1]);
    cout << "**" << endl;
    cout << " \\//      \\ /           " << "   && &      |  &&   |&& |  &&" << indent << "**" << h_line << "**" << endl;
    cout << indent << "    & &      \\      /     \\    " << indent << "** " << getColor(board[2][0]) << board[2][0] << resetColor();
    space(board[2][0]);
    cout << "| " << getColor(board[2][1]) << board[2][1] << resetColor();
    space(board[2][1]);
    cout << "| " << getColor(board[2][2]) << board[2][2] << resetColor();
    space(board[2][2]);
    cout << "| " << getColor(board[2][3]) << board[2][3] << resetColor();
    space(board[2][3]);
    cout << "**" << endl;
    cout << " \\      /   \\   /       " << "     &&         ----         --" << indent << "**" << h_line << "**" << endl;
    cout << " |\\    /|    \\ /        " << "      &            /       \\   " << indent << "** " << getColor(board[3][0]) << board[3][0] << resetColor();
    space(board[3][0]);
    cout << "| " << getColor(board[3][1]) << board[3][1] << resetColor();
    space(board[3][1]);
    cout << "| " << getColor(board[3][2]) << board[3][2] << resetColor();
    space(board[3][2]);
    cout << "| " << getColor(board[3][3]) << board[3][3] << resetColor();
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
    // int x = 1;
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

void gtasa()
{
    int r = rand() % 3;
    for (int i = 0; i < 3; i++)
    {
        if (i == r)
            cout << "|";
        cout << " ";
    }
}
void printBoardGTA(vector<vector<int>> &board)
{

    string h_line = "_____|_____|_____|_____";
    string v_line = "     |     |     |     ";
    string star_line = "***************************";
    string indent = "\t\t\t";                                                          // 4 indent to reach board = 48 space
    cout << indent << "              _________       " << indent << star_line << endl; //+
    cout << "  _________________ " << "                 /         \\     " << indent << "** " << board[0][0];
    space(board[0][0]);
    cout << "| ";
    cout << board[0][1];
    space(board[0][1]);
    cout << "| " << board[0][2];
    space(board[0][2]);
    cout << "| " << board[0][3];
    space(board[0][3]);
    cout << "**" << endl;
    cout << " |     _____       | " << "               |SAN ANDREAS|" << indent << "**" << h_line << "**" << endl;
    cout << " |    |     \\      | " << "              _\\___________/_ " << indent << "** " << board[1][0];
    space(board[1][0]);
    cout << "| " << board[1][1];
    space(board[1][1]);
    cout << "| " << board[1][2];
    space(board[1][2]);
    cout << "| " << board[1][3];
    space(board[1][1]);
    cout << "**" << endl;
    cout << " |    |   __/      | " << "             / | ____ ____ | \\" << indent << "**" << h_line << "**" << endl;
    cout << " |    |    \\       | " << "             \\ |-|__/-\\__|-| /" << indent << "** " << board[2][0];
    space(board[2][0]);
    cout << "| " << board[2][1];
    space(board[2][1]);
    cout << "| " << board[2][2];
    space(board[2][2]);
    cout << "| " << board[2][3];
    space(board[2][3]);
    cout << "**" << endl;
    cout << " |    |     \\/\\__  | " << "              (|    /_\\    |)" << indent << "**" << h_line << "**" << endl;
    cout << " |         \\    /  | " << "                \\  //_\\\\ /" << "\t\t\t        " << "** " << board[3][0];
    space(board[3][0]);
    cout << "| " << board[3][1];
    space(board[3][1]);
    cout << "| " << board[3][2];
    space(board[3][2]);
    cout << "| " << board[3][3];
    space(board[3][3]);
    cout << "**" << endl;
    cout << " |          |/\\|" << "   |                  \\       / " << indent << "**" << v_line << "**" << endl;
    cout << " |_________________|     ";
    gtasa();
    cout << "  ______/ \\-----/ \\______" << "\t\t        " << star_line << endl;
    cout << indent;
    gtasa();
    cout << "  /      \\  \\   /  /      \\" << "\t      " << endl;
    cout << "_______________________ ";
    gtasa();
    cout << " |        \\/-----\\/        |" << "\t            " << endl;
    cout << "|____|_______________(@)" << endl;
}
void BoardPicker(vector<vector<int>> &board, char pick)
{
    switch (pick)
    {
    case '1':
        printBoardWhite(board);
        break;
    case '2':
        printBoardArthur(board);
        break;
    case '3':
        printBoardGTA(board);
        break;
    default:
        break;
    }
}

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

bool canMoveLeft(vector<vector<int>> &board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - 1; j++)
        {
            if ((board[i][j] == 0 && board[i][j + 1] != 0) || (board[i][j] == board[i][j + 1] && board[i][j] != 0))
            {
                return true;
            }
        }
    }
    return false;
}

bool canMoveRight(vector<vector<int>> &board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = SIZE - 1; j > 0; j--)
        {
            if ((board[i][j] == 0 && board[i][j - 1] != 0) || (board[i][j] == board[i][j - 1] && board[i][j] != 0))
            {
                return true;
            }
        }
    }
    return false;
}

bool canMoveUp(vector<vector<int>> &board)
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[i][j] == 0 && board[i + 1][j] != 0) || (board[i][j] == board[i + 1][j] && board[i][j] != 0))
            {
                return true;
            }
        }
    }
    return false;
}

bool canMoveDown(vector<vector<int>> &board)
{
    for (int i = SIZE - 1; i > 0; i--)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[i][j] == 0 && board[i - 1][j] != 0) || (board[i][j] == board[i - 1][j] && board[i][j] != 0))
            {
                return true;
            }
        }
    }
    return false;
}

void MoveLeft(vector<vector<int>> &board)
{
    if (!canMoveLeft(board))
        return;
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
    if (!canMoveRight(board))
        return;
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
    if (!canMoveUp(board))
        return;
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
    if (!canMoveDown(board))
        return;
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
void SaveBoard(vector<vector<int>> &board, string &filename, char themeAdress)
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
        load << themeAdress;
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

char LoadLastTheme(string &filename)
{
    ifstream load(filename);
    if (!load.is_open()) return ' ';

    string line;
    char theme = '\0';
    for (int i = 1; i <= 5 && getline(load, line); i++) {
        if (i == 5 && !line.empty()) {
            theme = line[0];
        }
    }

    load.close();
    return theme;
}
void InvalidInput()
{
    cout << "INVALID INPUT!" << endl;
    usleep(1500000);
}

int main()
{
    vector<vector<int>> board;
    bool CanGenerate = true;
    char theme;
    string filename = "board.txt";
    ifstream load(filename);

    cout << "Welcome to 2048 by RS - Nhtm - MCyber" << endl;
    cout << "Checking saved data ..." << endl;
    usleep(2500000);

    if (load.good())
    {
        cout << "Saved game found! Wanna continue last game? (if not, new game will be started) (y/n) :";
        char ch = _getch();
        bool x = true;
        while (x)
        {
            if (ch == 'y')
            {
                cout << "Loading savedgame..." << endl;
                board = LoadSave(filename);
                theme = LoadLastTheme(filename);
                CanGenerate = false;
                x = false;
                usleep(2000000);
                break;
            }
            else if (ch == 'n')
            {
                board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
                cout << "Pick a board :" << endl;
                cout << "Enter number Breaking Bad(1) , Red Dead Redemption(2) , GTA(3) : ";
                theme = _getch();
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
        char check = _getch();
        bool x = true;
        while (x)
        {
            if (check == 'y')
            {
                cout << "Pick a board :" << endl;
                cout << "Enter number Breaking Bad(1) , Red Dead Redemption(2) , GTA(3) : ";
                theme = _getch();
                x = false;
                break;
            }
            else if (check == 'n')
            {
                cout << "\nBye my friend ...." << endl;
                return EXIT_SUCCESS;
            }
            else
                cout << "what ? (y/n):";
        }
    }

    while (true)
    {
        bool cheker = checklose(board);
        if (cheker)
        {
            cout << "You Lost ! ";
            cout << "Wanna start a new game ? (y/n)";
            char check = _getch();
            bool x = true;
            while (x)
            {

                if (check == 'y')
                {
                    cout << "Pick a board :" << endl;
                    cout << "Enter number Breaking Bad(1) , Red Dead Redemption(2) , GTA(3) : ";
                    theme = _getch();
                    x = false;
                }
                else if (check == 'n')
                {
                    cout << "Bye my friend ...." << endl;
                    return EXIT_SUCCESS;
                }
                else
                    cout << "what ? (y/n):";
            }
        }
        

        system("cls");

        if (CanGenerate)
            RandomGenerator(board);

        BoardPicker(board, theme);
        cout << "\n *Press Q to quit game* \n";
        cout << "\n Do a move (w/s/a/d) : ";
        // get input
        char PlayerMovement = _getch();

        switch (PlayerMovement)
        {
        case 'w':
            if (canMoveUp(board))
            {
                MoveUp(board);
                CanGenerate = true;
            }
            else
                CanGenerate = false;
            break;
        case 'a':
            if (canMoveLeft(board))
            {
                MoveLeft(board);
                CanGenerate = true;
            }
            else
                CanGenerate = false;
            break;
        case 's':
            if (canMoveDown(board))
            {
                MoveDown(board);
                CanGenerate = true;
            }
            else
                CanGenerate = false;
            break;
        case 'd':
            if (canMoveRight(board))
            {
                MoveRight(board);
                CanGenerate = true;
            }
            else
                CanGenerate = false;
            break;
        case 'q':
            if (true)
            {
                cout << "\nDo you wnat to exit ? (y/n)";
                char QuitSure = _getch();
                if (QuitSure == 'y')
                {
                    cout << "\nDo you wnat to save this game or not ? (y/n)";
                    char SaveSure = _getch();
                    if (SaveSure == 'y')
                    {
                        SaveBoard(board, filename, theme);
                        cout << "\ngame successfully saved !";
                        return 0;
                    }
                    else
                        return 0;
                }
                else
                    CanGenerate = false;
            }

            break;
        default:
            InvalidInput();
            break;
        }
    }
}