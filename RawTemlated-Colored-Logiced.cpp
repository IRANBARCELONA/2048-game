#include <bits/stdc++.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

int SIZE = 4;
vector<vector<int>> board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

string getColor(int number) {
    switch (number) {
        case 2: return "\033[1;31m";  
        case 4: return "\033[1;32m";
        case 8: return "\033[1;33m";
        case 16: return "\033[1;34m";
        case 32: return "\033[1;35m";
        case 64: return "\033[1;36m";
        case 128: return "\033[0;35m";
        case 256: return "\033[0;31m";
        case 512: return "\033[0;32m";
        case 1024: return "\033[0;33m";
        case 2048: return "\033[0;34m";
        default: return "\033[0m";
    }
}

string resetColor() {
    return "\033[0m";
}

void printBoard(vector<vector<int>> &board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cout << getColor(board[i][j]) << board[i][j] << resetColor() << "\t"; 
        cout << endl;
    }
}


bool checklose(vector<vector<int>> &board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
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

void RandomGenerator() {
    srand(static_cast<unsigned>(time(0)));
    while (true) {
        int randomRow = rand() % 4;
        int randomCol = rand() % 4;
        if (board[randomRow][randomCol] == 0) {
            board[randomRow][randomCol] = 2;
            break;
        }
    }
}

bool canMoveLeft(vector<vector<int>> &board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if ((board[i][j] == 0 && board[i][j + 1] != 0) || (board[i][j] == board[i][j + 1] && board[i][j] != 0)) {
                return true;
            }
        }
    }
    return false;
}

bool canMoveRight(vector<vector<int>> &board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 1; j > 0; j--) {
            if ((board[i][j] == 0 && board[i][j - 1] != 0) || (board[i][j] == board[i][j - 1] && board[i][j] != 0)) {
                return true;
            }
        }
    }
    return false;
}

bool canMoveUp(vector<vector<int>> &board) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((board[i][j] == 0 && board[i + 1][j] != 0) || (board[i][j] == board[i + 1][j] && board[i][j] != 0)) {
                return true;
            }
        }
    }
    return false;
}

bool canMoveDown(vector<vector<int>> &board) {
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = 0; j < SIZE; j++) {
            if ((board[i][j] == 0 && board[i - 1][j] != 0) || (board[i][j] == board[i - 1][j] && board[i][j] != 0)) {
                return true;
            }
        }
    }
    return false;
}

void MoveLeft(vector<vector<int>> &board) {
    if (!canMoveLeft(board))
        return;
    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - 1; j++) {
                if (board[k][j] == 0 && board[k][j + 1] != 0) {
                    swap(board[k][j], board[k][j + 1]);
                }
            }
        }
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[k][j] == board[k][j + 1] && board[k][j] != 0) {
                board[k][j] *= 2;
                board[k][j + 1] = 0;
            }
        }
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - 1; j++) {
                if (board[k][j] == 0 && board[k][j + 1] != 0) {
                    swap(board[k][j], board[k][j + 1]);
                }
            }
        }
    }
}

void MoveRight(vector<vector<int>> &board) {
    if (!canMoveRight(board))
        return;
    for (int k = 0; k < SIZE; k++) {
        for (int i = SIZE - 1; i > 0; i--) {
            for (int j = SIZE - 1; j > 0; j--) {
                if (board[k][j] == 0 && board[k][j - 1] != 0) {
                    swap(board[k][j], board[k][j - 1]);
                }
            }
        }
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[k][j] == board[k][j - 1] && board[k][j] != 0) {
                board[k][j] *= 2;
                board[k][j - 1] = 0;
            }
        }
        for (int i = SIZE - 1; i > 0; i--) {
            for (int j = SIZE - 1; j > 0; j--) {
                if (board[k][j] == 0 && board[k][j - 1] != 0) {
                    swap(board[k][j], board[k][j - 1]);
                }
            }
        }
    }
}

void MoveUp(vector<vector<int>> &board) {
    if (!canMoveUp(board))
        return;
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE - 1; i++) {
            for (int k = 0; k < SIZE - 1; k++) {
                if (board[k][j] == 0 && board[k + 1][j] != 0) {
                    swap(board[k][j], board[k + 1][j]);
                }
            }
        }
        for (int i = 0; i < SIZE - 1; i++) {
            if (board[i][j] == board[i + 1][j] && board[i][j] != 0) {
                board[i][j] *= 2;
                board[i + 1][j] = 0;
            }
        }
        for (int i = 0; i < SIZE - 1; i++) {
            for (int k = 0; k < SIZE - 1; k++) {
                if (board[k][j] == 0 && board[k + 1][j] != 0) {
                    swap(board[k][j], board[k + 1][j]);
                }
            }
        }
    }
}

void MoveDown(vector<vector<int>> &board) {
    if (!canMoveDown(board))
        return;
    for (int j = 0; j < SIZE; j++) {
        for (int i = SIZE - 1; i > 0; i--) {
            for (int k = SIZE - 1; k > 0; k--) {
                if (board[k][j] == 0 && board[k - 1][j] != 0) {
                    swap(board[k][j], board[k - 1][j]);
                }
            }
        }
        for (int i = SIZE - 1; i > 0; i--) {
            if (board[i][j] == board[i - 1][j] && board[i][j] != 0) {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
            }
        }
        for (int i = SIZE - 1; i > 0; i--) {
            for (int k = SIZE - 1; k > 0; k--) {
                if (board[k][j] == 0 && board[k - 1][j] != 0) {
                    swap(board[k][j], board[k - 1][j]);
                }
            }
        }
    }
}

int main() {
    bool firstGenerate = true;
    bool CanGenerate = true;

    while (true) {
        if (firstGenerate) {
            RandomGenerator();
            RandomGenerator();
            firstGenerate = false;
        }
        else if(CanGenerate)
            RandomGenerator();


        system("cls");
        printBoard(board);

        if (checklose(board)) {
            cout << "Fukin Lost!" << endl;
            break;
        }

        cout << "\nDo a move (w/s/a/d): ";
        char PlayerMovement = _getch();

        switch (PlayerMovement) {
            case 'w':
                if (canMoveUp(board)){
                    MoveUp(board);
                    CanGenerate=true;
                }
                else
                    CanGenerate=false;
                break;
            case 'a':
                if (canMoveLeft(board)){
                    MoveLeft(board);
                    CanGenerate=true;
                }
                else
                    CanGenerate=false;
                break;
            case 's':
                if (canMoveDown(board)){
                    MoveDown(board);
                    CanGenerate=true;
                }
                else
                    CanGenerate=false;
                break;
            case 'd':
                if (canMoveRight(board)){
                    MoveRight(board);
                    CanGenerate=true;
                }
                else
                    CanGenerate=false;
                break;
            default:
                cout << "INVALID INPUT!" << endl;
                break;
        }
    }

    return 0;
}