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
        cout<<" ";
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
    cout << indent<< "  &&                          "<<indent<< star_line<<endl; //+
    cout << " /\\   /\\    \\  /  "<< "        &&&&      mmm               "<< indent<< "** " << board[0][0];
    space(board[0][0]);
    cout << "| ";
    cout << board[0][1];
    space(board[0][1]);
    cout << "| " << board[0][2];
    space(board[0][2]);
    cout << "| " << board[0][3];
    space(board[0][3]);
    cout <<"**"<< endl;
    cout << " \\   /__\\    \\/      "<< "     &&  &         mmm          m"<< indent<< "**"<< h_line <<"**"<<endl;
    cout << "  \\ /    \\   /          "<< "   &  &      | ---- \\     /--"<< indent<< "** "<< board[1][0];
    space(board[1][0]);
    cout << "| " << board[1][1];
    space(board[1][1]);
    cout << "| " << board[1][2];
    space(board[1][2]);
    cout << "| " << board[1][3];
    space(board[1][1]);
    cout <<"**"<< endl;
    cout << " \\//      \\ /           "<< "   && &      |  &&   |&& |  &&"<< indent<< "**"<< h_line <<"**"<< endl;
    cout << indent<< "    & &      \\      /     \\    "<< indent<< "** " << board[2][0];
    space(board[2][0]);
    cout << "| " << board[2][1];
    space(board[2][1]);
    cout << "| " << board[2][2];
    space(board[2][2]);
    cout << "| " << board[2][3];
    space(board[2][3]);
    cout <<"**"<< endl;
    cout << " \\      /   \\   /       "<< "     &&         ----         --"<< indent<< "**"<< h_line <<"**"<< endl;
    cout << " |\\    /|    \\ /        "<< "      &            /       \\   "<< indent<< "** "<< board[3][0];
    space(board[3][0]);
    cout << "| " << board[3][1];
    space(board[3][1]);
    cout << "| " << board[3][2];
    space(board[3][2]);
    cout << "| " << board[3][3];
    space(board[3][3]);
    cout << "**"<< endl;
    cout << " | \\  / |     /         "<< "       \\            \\     / "<< indent<< "**"<< v_line <<"**"<< endl;
    cout << " |  \\/  |    /          "<< "        \\        ///////\\\\\\\\\\"<< "\t\t       "<< "*                           *" << endl;
    cout << indent<< "       _/\\      ////////\\\\\\\\\\"<< "\t\t      "<< "*                             *" << endl;
    cout << " \\   |    /\\    \\     / -----"<< " /   \\     ||  _______"<< "\t\t     "<< "*    ";
    snow();
    cout<<"   *" << endl;
    cout << " |\\  |   /__\\   |\\   /| |__ "<< "_/     |    ||         "<< "\t\t     "<< "*                               *" << endl;
    cout << " | \\ |  /    \\  | \\ / | |  "<< "/       \\     \\\\\\\\\\\\\\/////"<< "\t\t     "<< "*                               *" << endl;
    cout << " |  \\| /      \\ |  /  | |----"<<indent <<"\t\t     ******"<<star_line;
}
int main()
{
    printBoard();
    return 0;
}
