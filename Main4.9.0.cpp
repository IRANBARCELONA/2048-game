#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <unistd.h>
#include <fstream>
using namespace std;

#define SIZE 4
// public Varibles
int score = 0;
int x=1;

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
    cout << '\n' << "                                                                                 "<< "\033[1;35m" << "Score:  "<< resetColor() << "\033[1;34m" << score << resetColor();
}

void reddead()
{
    if (x == 1){
        cout << "RED";
        x++;}
    else if (x == 2){
        cout << "    DEAD";
        x++;}
    else if (x == 3){
        cout << "         REDEMPTION";
        x++;}
    else
    {
        cout << "RED DEAD REDEMPTION";
        x = 1;
    }
}

void printBoardArthur(vector<vector<int>> &board)
{
    string h_line = "_____|_____|_____|_____";
    string v_line = "     |     |     |     ";
    string star_line = "***************************";
    string indent = "\t\t\t";                                                          // 4 indent to reach board = 48 space
    cout << indent << "                  ______      " << indent << star_line << endl; //+
    cout << "  _________________ " << "                    /        \\     " << indent << "** " << getColor(board[0][0]) << board[0][0] << resetColor();
    space(board[0][0]);
    cout << "| ";
    cout << getColor(board[0][1]) << board[0][1] << resetColor();
    space(board[0][1]);
    cout << "| " << getColor(board[0][2]) << board[0][2] << resetColor();
    space(board[0][2]);
    cout << "| " << getColor(board[0][3]) << board[0][3] << resetColor();
    space(board[0][3]);
    cout << "**" << endl;
    cout << " |     _____       | " << "               -_ /          \\_-" << indent << "**" << h_line << "**" << endl;
    cout << " |    |     \\      | " << "               \\_______________/  " << indent << "** " << getColor(board[1][0]) << board[1][0] << resetColor();
    space(board[1][0]);
    cout << "| " << getColor(board[1][1]) << board[1][1] << resetColor();
    space(board[1][1]);
    cout << "| " << getColor(board[1][2]) << board[1][2] << resetColor();
    space(board[1][2]);
    cout << "| " << getColor(board[1][3]) << board[1][3] << resetColor();
    space(board[1][1]);
    cout << "**" << endl;
    cout << " |    |   __/      | " << "                 \\|  0` |  0  \\" << indent << "**" << h_line << "**" << endl;
    cout << " |    |    \\       | " << "                  |    '-'    |" << indent << "** " << getColor(board[2][0]) << board[2][0] << resetColor();
    space(board[2][0]);
    cout << "| " << getColor(board[2][1]) << board[2][1] << resetColor();
    space(board[2][1]);
    cout << "| " << getColor(board[2][2]) << board[2][2] << resetColor();
    space(board[2][2]);
    cout << "| " << getColor(board[2][3]) << board[2][3] << resetColor();
    space(board[2][3]);
    cout << "**" << endl;
    cout << " |    |     \\/\\__  | " << "      ______|-|   \\\\\\ //_\\\\ ///" << indent << "**" << h_line << "**" << endl;
    cout << " |         \\    /  | " << "     (_)____   \\ _ \\\\\\\\\\|/////" << indent << "** " << getColor(board[3][0]) << board[3][0] << resetColor();
    space(board[3][0]);
    cout << "| " << getColor(board[3][1]) << board[3][1] << resetColor();
    space(board[3][1]);
    cout << "| " << getColor(board[3][2]) << board[3][2] << resetColor();
    space(board[3][2]);
    cout << "| " << getColor(board[3][3]) << board[3][3] << resetColor();
    space(board[3][3]);
    cout << "**" << endl;
    cout << " |          |/\\|" << "   |           / \\___| \\/\\_     |_ " << indent << "**" << v_line << "**" << endl;
    cout << " |_________________|" << "          /\\  ___|-/   \\_  /   \\_" << "\t\t        " << star_line << endl;
    cout << indent << "      | \\____/ |     \\|       \\ " << "\t\t         " <<"\033[1;35m" << "Score:  "<< resetColor() << "\033[1;34m" << score << resetColor() << endl;
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
    cout << "  _________________ " << "                 /         \\     " << indent << "** " << getColor(board[0][0]) << board[0][0] << resetColor();
    space(board[0][0]);
    cout << "| ";
    cout << getColor(board[0][1]) << board[0][1] << resetColor();
    space(board[0][1]);
    cout << "| " << getColor(board[0][2]) << board[0][2] << resetColor();
    space(board[0][2]);
    cout << "| " << getColor(board[0][3]) << board[0][3] << resetColor();
    space(board[0][3]);
    cout << "**" << endl;
    cout << " |     _____       | " << "               |SAN ANDREAS|" << indent << "**" << h_line << "**" << endl;
    cout << " |    |     \\      | " << "              _\\___________/_ " << indent << "** " << getColor(board[1][0]) << board[1][0] << resetColor();
    space(board[1][0]);
    cout << "| " << getColor(board[1][1]) << board[1][1] << resetColor();
    space(board[1][1]);
    cout << "| " << getColor(board[1][2]) << board[1][2] << resetColor();
    space(board[1][2]);
    cout << "| " << getColor(board[1][3]) << board[1][3] << resetColor();
    space(board[1][1]);
    cout << "**" << endl;
    cout << " |    |   __/      | " << "             / | ____ ____ | \\" << indent << "**" << h_line << "**" << endl;
    cout << " |    |    \\       | " << "             \\ |-|__/-\\__|-| /" << indent << "** " << getColor(board[2][0]) << board[2][0] << resetColor();
    space(board[2][0]);
    cout << "| " << getColor(board[2][1]) << board[2][1] << resetColor();
    space(board[2][1]);
    cout << "| " << getColor(board[2][2]) << board[2][2] << resetColor();
    space(board[2][2]);
    cout << "| " << getColor(board[2][3]) << board[2][3] << resetColor();
    space(board[2][3]);
    cout << "**" << endl;
    cout << " |    |     \\/\\__  | " << "              (|    /_\\    |)" << indent << "**" << h_line << "**" << endl;
    cout << " |         \\    /  | " << "                \\  //_\\\\ /" << "\t\t\t        " << "** " << getColor(board[3][0]) << board[3][0] << resetColor();
    space(board[3][0]);
    cout << "| " << getColor(board[3][1]) << board[3][1] << resetColor();
    space(board[3][1]);
    cout << "| " << getColor(board[3][2]) << board[3][2] << resetColor();
    space(board[3][2]);
    cout << "| " << getColor(board[3][3]) << board[3][3] << resetColor();
    space(board[3][3]);
    cout << "**" << endl;
    cout << " |          |/\\|" << "   |                  \\       / " << indent << "**" << v_line << "**" << endl;
    cout << " |_________________|     ";
    gtasa();
    cout << "  ______/ \\-----/ \\______" << "\t\t        " << star_line << endl;
    cout << indent;
    gtasa();
    cout << "  /      \\  \\   /  /      \\" << "\t\t\t         " <<"\033[1;35m" << "Score:  "<< resetColor() << "\033[1;34m" << score << resetColor() << endl;
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
// functions and movements
int HighScore()
{
    int max = 0;
    if (score > max)
    {
        max = score;
    }
    return max;
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
                score += board[k][j];
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
                score += board[k][j];
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
                score += board[i][j];
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
                score += board[i][j];
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
void SaveBoard(vector<vector<int>> &board, string &filename, char themeAdress, int RawScore)
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
        load << themeAdress << endl;
        load << RawScore;
        load.close();
    }
    else
    {
        cerr << "The game can not be saved ! " << endl;
    }
}
void SaveHighScore()
{
    string filename = "HighScore.txt";
    ofstream load(filename);
    if (load.is_open())
    {
        load << HighScore();
        load.close();
    }
    else
    {
        cerr << "The game can not be saved ! " << endl;
    }
}
int LastHighScore()
{
    string filename = "HighScore.txt";
    ifstream load(filename);
    if (!load.is_open())
        return 0;
    int number = 0;
    load >> number;
    load.close();
    return number;
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
    if (!load.is_open())
        return ' ';

    string line;
    char theme = '\0';
    for (int i = 1; i <= 5 && getline(load, line); i++)
    {
        if (i == 5 && !line.empty())
        {
            theme = line[0];
        }
    }

    load.close();
    return theme;
}

int LastRawScore(string &filename)
{
    ifstream load(filename);
    if (!load.is_open())
        return 0;
    int number = 0;
    string line;
    for (int i = 0; i < 6 && getline(load, line); ++i)
        ;

    if (!line.empty())
    {
        number = stoi(line);
    }

    load.close();
    return number;
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
    bool FirstGenerate = true;
    char theme;
    int HighestScore = LastHighScore();
    string filename = "board.txt";
    ifstream load(filename);
    cout << "Welcome to 2048 by RS - Nhtm - MCyber" << endl;
    cout << "Checking saved data ..." << endl;
    usleep(2500000);

    if (load.good())
    {
        cout << "Saved game found! Wanna continue last game? (if not, new game will be started) (y/n) :";
        char ch = _getch();
        bool LastGameContinue = true;
        while (LastGameContinue)
        {
            if (ch == 'y')
            {
                cout << "Loading savedgame..." << endl;
                board = LoadSave(filename);
                theme = LoadLastTheme(filename);
                score = LastRawScore(filename);
                FirstGenerate=false;
                CanGenerate = false;
                LastGameContinue = false;
                usleep(2000000);
                break;
            }
            else if (ch == 'n')
            {
                load.close();
                fstream(filename,ios::trunc);
                board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
                cout << "\nPick a board :" << endl;
                cout << "Enter number Breaking Bad(1) , Red Dead Redemption(2) , GTA(3) : ";
                theme = _getch();
                LastGameContinue = false;
            }
            // else
            //     cout << "what ? (y/n):";
        }
    }
    else
    {
        board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

        cout << "No saved data found." << endl;
        cout << "New Game? (y/n) :";
        char check = _getch();
        bool NewGameStart = true;
        while (NewGameStart)
        {
            if (check == 'y')
            {
                cout << "\nPick a board :" << endl;
                cout << "Enter number Breaking Bad(1) , Red Dead Redemption(2) , GTA(3) : ";
                theme = _getch();
                NewGameStart = false;
                break;
            }
            else if (check == 'n')
            {
                cout << "\nBye my friend ...." << endl;
                return EXIT_SUCCESS;
            }
            // else
            //     cout << "what ? (y/n):";
        }
    }
    load.close();

    // Main Loop Of the game
    while (true)
    {
        if (checklose(board))
        {
            SaveHighScore();
            fstream(filename,ios::trunc);
            cout << "You Lost ! ";
            cout << "Wanna start a new game ? (y/n)";
            char check;
            cin >> check;
            bool GameAfterLose = true;
            while (GameAfterLose)
            {

                if (check == 'y')
                {
                    score = 0;
                    cout << "Pick a board :" << endl;
                    cout << "Enter number Breaking Bad(1) , Red Dead Redemption(2) , GTA(3) : ";
                    theme = _getch();
                    GameAfterLose = false;
                }
                else if (check == 'n')
                {
                    cout << "Bye my friend ...." << endl;
                    return EXIT_SUCCESS;
                }
                // else
                //     cout << "what ? (y/n):";
            }
        }
        
        system("cls");

        if (FirstGenerate)
        {
            RandomGenerator(board);
            RandomGenerator(board);
            FirstGenerate = false;
        }
        else if (CanGenerate)
            RandomGenerator(board);

        if (LastHighScore() < HighScore())
            HighestScore = HighScore();

        cout <<"\t\t\t\t\t\t\t\t\t   " << "\033[1;32m" << "Highest score is :  " << resetColor() << "\033[1;34m" << HighestScore << resetColor()<< "\n";
        BoardPicker(board, theme);
        cout << "\n*Press Q to quit game* \n";
        cout << "\nDo a move (w/s/a/d) : ";
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
                        SaveHighScore();
                        SaveBoard(board, filename, theme, score);
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
        case 13:
            CanGenerate = false;
            break;
        default:
            InvalidInput();
            CanGenerate = false;
            break;
        }
    }
}