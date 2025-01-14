#include <bits/stdc++.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int SIZE = 4;
vector<vector<int>> board = {{2048, 64, 16, 2}, {0, 0, 0, 0}, {0, 0, 0, 0},{0, 0, 0, 0}};
void snow(){
    int r=rand()%23;
    for(int i=0;i<23;i++){
        if(i==r)
            cout<<"*";
        if(i==23-r)
            cout<<"*";

        cout<<" ";
    }
}
void reddead(){
    int x=(rand()%4)+1;
    if(x==1)
        cout<<"RED";
    else if(x==2)
        cout<<"    DEAD";
    else if(x==3)
        cout<<"         REDEMPTION";
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
    int x=1;
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
int main()
{
    printBoard();
    return 0;
}
