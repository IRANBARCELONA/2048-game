#include <bits/stdc++.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
int SIZE = 4;
vector<vector<int>> board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},{0, 0, 0, 0}};
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

int x=1;
void reddead(){
    if(x==1){
        cout<<"RED";
        x++;
    }
    else if(x==2){
        cout<<"    DEAD";
    x++;
    }
    else if(x==3){
        cout<<"         REDEMPTION";
    x++;
    }
    else{
        cout<<"RED DEAD REDEMPTION";
        x=1;
    }
}
void space(int a){
    int n=0,ox=a;
    while(a>0){
        n++;
        a/=10;
    }
    if(ox!=0){
        for(int i=0;i<4-n;i++)
            cout << " ";
    }
    else
        cout<< "   ";
}
void printBoard()
{
    string h_line = "_____|_____|_____|_____";
    string v_line = "     |     |     |     ";
    string star_line= "***************************";
    string indent = "\t\t\t";//4 indent to reach board = 48 space
    cout << indent<< "                  ______      "<<indent<< star_line<<endl; //+
    cout << "  _________________ "<< "                    /        \\     "<< indent<< "** " << board[0][0];
    space(board[0][0]);
    cout << "| ";
    cout << board[0][1];
    space(board[0][1]);
    cout << "| " << board[0][2];
    space(board[0][2]);
    cout << "| " << board[0][3];
    space(board[0][3]);
    cout <<"**"<< endl;
    cout << " |     _____       | "<< "               -_ /          \\_-"<< indent<< "**"<< h_line <<"**"<<endl;
    cout << " |    |     \\      | "<< "               \\_______________/  "<< indent<< "** "<< board[1][0];
    space(board[1][0]);
    cout << "| " << board[1][1];
    space(board[1][1]);
    cout << "| " << board[1][2];
    space(board[1][2]);
    cout << "| " << board[1][3];
    space(board[1][1]);
    cout <<"**"<< endl;
    cout << " |    |   __/      | "<< "                 \\|  0` |  0  \\"<< indent<< "**"<< h_line <<"**"<< endl;
    cout << " |    |    \\       | "<< "                  |    '-'    |"<< indent<< "** " << board[2][0];
    space(board[2][0]);
    cout << "| " << board[2][1];
    space(board[2][1]);
    cout << "| " << board[2][2];
    space(board[2][2]);
    cout << "| " << board[2][3];
    space(board[2][3]);
    cout <<"**"<< endl;
    cout << " |    |     \\/\\__  | "<< "      ______|-|   \\\\\\ //_\\\\ ///"<< indent<< "**"<< h_line <<"**"<< endl;
    cout << " |         \\    /  | "<< "     (_)____   \\ _ \\\\\\\\\\|/////"<< indent<< "** "<< board[3][0];
    space(board[3][0]);
    cout << "| " << board[3][1];
    space(board[3][1]);
    cout << "| " << board[3][2];
    space(board[3][2]);
    cout << "| " << board[3][3];
    space(board[3][3]);
    cout << "**"<< endl;
    cout << " |          |/\\|"<< "   |           / \\___| \\/\\_     |_ "<< indent<< "**"<< v_line <<"**"<< endl;
    cout << " |_________________|"<< "          /\\  ___|-/   \\_  /   \\_"<< "\t\t        "<< star_line << endl;
    cout << indent<< "      | \\____/ |     \\|       \\ "<< "\t      "<< endl;
    cout << indent<< "       \\______/               | "<< "\t            ";
    reddead();
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
    bool FirstGenerate =true;
    while (true)
    {
        if (goGame == true)
        {
            RandomGenerator();
            if(FirstGenerate)
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

        cout << '\n' <<"Do a move (w/s/a/d) : ";
        char PlayerMovement = _getch();
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
        FirstGenerate=false;
    }

    return 0;
}
