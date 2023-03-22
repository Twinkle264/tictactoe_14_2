#include <iostream>
using namespace std;

char tictactoe[3][3] = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};

int checkingWinner(){
    if (tictactoe[0][0] == tictactoe[1][1] && tictactoe[0][0] == tictactoe[2][2]) {
        if (tictactoe[0][0] == 'X') {
            return 1;
        } else if (tictactoe[0][0] == 'O') {
            return 2;
        }
    } else if (tictactoe[2][0] == tictactoe[1][1] && tictactoe[0][2] == tictactoe[2][0]) {
        if (tictactoe[2][0] == 'X') {
            return 1;
        } else if (tictactoe[2][0] == 'O') {
            return 2;
        }
    } else {
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j) {
                if ((tictactoe[i][j] == tictactoe[i+1][j]) && (tictactoe[i][j] == tictactoe[i+2][j])) {
                    if (tictactoe[i][j] == 'X') {
                        return 1;
                    } else if (tictactoe[i][j] == 'O') {
                        return 2;
                    }
                } else if ((tictactoe[i][0] == tictactoe[i][1]) && (tictactoe[i][0] == tictactoe[i][2])) {
                    if (tictactoe[i][0] == 'X') {
                        return 1;
                    } else if (tictactoe[i][0] == 'O') {
                        return 2;
                    }
                }

            }
        }
    }
    return 0;
}

bool is_Valid(char a, char b) {
    if ((a >= '1' && a <= '3') && (b >= '1' && b <= '3')) {
        if (tictactoe[a-'1'][b-'1'] != '.') {
            cout << endl << "These coordinates are already taken!" << endl;
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

bool playerController(bool p) {
    int player;
    char x, y;

    if (p) {
        player = 1;
    } else {
        player = 2;
    }

    do {
        cout << "Player " << player << ", input the coordinates of your turn (exp: 3 1)" << endl;
        cin >> x >> y;
    } while (!is_Valid(x, y));

    if (player == 1) {
        tictactoe[x-'1'][y-'1'] = 'X';
    } else {
        tictactoe[x-'1'][y-'1'] = 'O';
    }

    return true;
}

void c_field(char a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    bool player = true;

    c_field(tictactoe);
    for (int i = 0; i < 9; ++i){
        playerController(player);

        c_field(tictactoe);
        if (checkingWinner() == 1) {
            cout << endl << "Player 1 is winner!" << endl;
            return 0;
        } else if (checkingWinner() == 2) {
            cout << endl << "Player 2 is winner!" << endl;
            return 0;
        }
        player = !player;

    }
    cout << endl << "Draw!" << endl;
    return 0;
}
