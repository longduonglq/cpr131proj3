#include <iostream>
#include <time.h>
using namespace std;

void homeworkHeader(string title);

const int MAX = 3;
void printBoard(char array[], int eleNum);
void printFirstRow();
void printRow(char array[], int& i, int& row);
void printInstructions();
void getMove(int& move);
void ranMove(int& move);
void moveToR_C(int move, int& row, int& column);
string checkWinner(char board[MAX][MAX]);
bool loop(bool on);

void putNchars(char character, int n) {
    for (int i = 0; i < n; i++) {
        cout << character;
    }
}

/*void printBoard(char array[], int eleNum) {
    int i = 0;
    int row = 1;
    printFirstRow();
    printRow(array, i, row);
    printRow(array, i, row);
    printRow(array, i, row);
    cout << "\n";
}
void printFirstRow() {
    cout << "\n   ";
    for (int n = 1; n <= 3; n++)
        cout << "   " << n << "   ";
    cout << "\n   ";
}
void printRow(char array[], int& i, int& row) {
    cout << "   -      -      -   \n  " << row;
    for (i; i < (MAX * row); i++)
        cout << " | " << array[i] << " | ";
    cout << "\n   ";
    row++;
    if (row > 3)
        cout << "   -      -      -   \n   ";
}*/
void printInstructions() {
    cout << "\nInput:  [Space #]\n";
    cout << "Examples: 2\n";
    cout << "          1\n";
    cout << "          6";
}
void getMove(int& move) {
    cout << "\nYour move: ";
    cin >> move;
}
void ranMove(int& move) {
    move = rand() % 9 + 1;
}
void moveToR_C(int move, int& row, int& column) {
    row = (move - 1) / 3;
    column = (move - 1) % 3;
}
string checkWinner(char board[MAX][MAX]) {
    //check rows
    for (int row = 0; row < MAX; ++row) {
        if (board[row][0] == 'O') {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
                return "O";
        }
    }
    for (int row = 0; row < MAX; ++row) {
        if (board[row][0] == 'X') {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
                return "X";
        }
    }
    //check columns
    for (int col = 0; col < MAX; ++col) {
        if (board[0][col] == 'O') {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
                return "O";
        }
    }
    for (int col = 0; col < MAX; ++col) {
        if (board[0][col] == 'X') {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
                return "X";
        }
    }
    //check diagonals
    if (board[0][0] == 'X') {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return "X";
    }
    if (board[0][2] == 'X') {
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return "X";
    }
    if (board[0][0] == 'O') {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return "O";
    }
    if (board[0][2] == 'O') {
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return "O";
    }
    //no win
    return "No one";
}
bool loop(bool on) {
    string ans = "";
    cout << "\n\nType 'y' to accept another challenge. Anything else to exit.\n";
    cin >> ans;
    if (ans == "y" || ans == "Y") {
        cout << "\n";
    }
    else {
        on = false;
        cout << "\nGoodbye\n";
    }
    return on;
}

int main() {
    int move = 0;
    int cpuMove = 0;
    int r, c;
    char board[MAX][MAX];
    char spaces[10] = "123456789";
    char space = ' ';
    srand(time(0));
    int moves = 0;
    bool win = false;
    char XorO = 'X';
    string winner = "No one";
    int plays = 0;

    bool on = true;
    bool playing = true;
    while (on) {
        if (plays == 0) {
            //empty board
            for (int row = 0; row < MAX; ++row)
                for (int col = 0; col < MAX; ++col)
                    board[row][col] = spaces[((row * 3)) + col];
            //print board
            for (int row = 0; row < 3; ++row) {
                cout << "\n";
                for (int col = 0; col < MAX; ++col) {
                    space = board[row][col];
                    cout << space << " \t";
                }
            }
            printInstructions();
        }
        while (playing) {
            //your move
            getMove(move);
            if (move > 9 || move < 1) {
                cout << "\n\nERROR\n";
                return 0;
            }
            moveToR_C(move, r, c);
            while (board[r][c] == 'X' || board[r][c] == 'O') {
                cout << "Space taken";
                getMove(move);
                if (move > 9 || move < 1) {
                    cout << "\n\nERROR\n";
                    return 0;
                }
                moveToR_C(move, r, c);
            }
            board[r][c] = 'X'; moves++;
            //check if someone won
            winner = checkWinner(board);
            if (winner != "No one") win = true;
            if (win == true || moves >= 9) break;
            //cpu move
            ranMove(cpuMove);
            while (cpuMove == move)
                ranMove(cpuMove);
            moveToR_C(cpuMove, r, c);
            while (board[r][c] == 'X' || board[r][c] == 'O') {
                ranMove(cpuMove);
                moveToR_C(cpuMove, r, c);
            }
            board[r][c] = 'O'; moves++;
            //print board
            for (int row = 0; row < 3; ++row) {
                cout << "\n";
                for (int col = 0; col < MAX; ++col) {
                    if (board[row][col] == '1' || board[row][col] == '2' ||
                        board[row][col] == '3' || board[row][col] == '4' ||
                        board[row][col] == '5' || board[row][col] == '6' ||
                        board[row][col] == '7' || board[row][col] == '8' ||
                        board[row][col] == '9') {
                        space = '-';
                    }
                    else {
                        space = board[row][col];
                    }
                    cout << space << " \t";
                }
            }
            //check if someone won
            winner = checkWinner(board);
            if (winner != "No one") win = true;
            if (win == true || moves >= 9) break;
        } cout << "\n";
        if (win || moves >= (MAX * 3)) {
            cout << "\n" << winner << " wins!";
            //print board
            for (int row = 0; row < 3; ++row) {
                cout << "\n";
                for (int col = 0; col < MAX; ++col) {
                    if (board[row][col] == '1' || board[row][col] == '2' ||
                        board[row][col] == '3' || board[row][col] == '4' ||
                        board[row][col] == '5' || board[row][col] == '6' ||
                        board[row][col] == '7' || board[row][col] == '8' ||
                        board[row][col] == '9') {
                        space = '-';
                    }
                    else {
                        space = board[row][col];
                    }
                    cout << space << " \t";
                }
            }
        }
        plays++;
        on = loop(on);
        if (on == true) {
            moves = 0;
            win = false;
            //empty board
            for (int row = 0; row < MAX; ++row)
                for (int col = 0; col < MAX; ++col)
                    board[row][col] = spaces[((row * 3)) + col];
        }
        if (on == true && winner == "O") {
            //print board
            for (int row = 0; row < 3; ++row) {
                cout << "\n";
                for (int col = 0; col < MAX; ++col) {
                    if (board[row][col] == '1' || board[row][col] == '2' ||
                        board[row][col] == '3' || board[row][col] == '4' ||
                        board[row][col] == '5' || board[row][col] == '6' ||
                        board[row][col] == '7' || board[row][col] == '8' ||
                        board[row][col] == '9') {
                        space = '-';
                    }
                    else {
                        space = board[row][col];
                    }
                    cout << space << " \t";
                }
            }
        }
        if (on == true && winner == "X") {
            //cpu move
            ranMove(cpuMove);
            while (cpuMove == move)
                ranMove(cpuMove);
            moveToR_C(cpuMove, r, c);
            while (board[r][c] == 'X' || board[r][c] == 'O') {
                ranMove(cpuMove);
                moveToR_C(cpuMove, r, c);
            }
            board[r][c] = 'O'; moves++;
            //print board
            for (int row = 0; row < 3; ++row) {
                cout << "\n";
                for (int col = 0; col < MAX; ++col) {
                    if (board[row][col] == '1' || board[row][col] == '2' ||
                        board[row][col] == '3' || board[row][col] == '4' ||
                        board[row][col] == '5' || board[row][col] == '6' ||
                        board[row][col] == '7' || board[row][col] == '8' ||
                        board[row][col] == '9') {
                        space = '-';
                    }
                    else {
                        space = board[row][col];
                    }
                    cout << space << " \t";
                }
            }
        }
        winner = "No one";
    }
    return 0;
}