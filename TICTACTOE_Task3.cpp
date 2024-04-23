#include <iostream>
#include <vector>

using namespace std;

void display(const vector<vector<char>>& table) {
    for (const auto& row : table) {
        for (char cell : row) {
            cout << cell << "|";
        }
        cout << endl;
    }
}

bool win(const vector<vector<char>>& table, char user) {
    for (int i = 0; i < 3; i++) {
        if ((table[i][0] == user && table[i][1] == user && table[i][2] == user) ||
            (table[0][i] == user && table[1][i] == user && table[2][i] == user)) {
            return true;
        }
    }
    if ((table[0][0] == user && table[1][1] == user && table[2][2] == user) ||
        (table[0][2] == user && table[1][1] == user && table[2][0] == user)) {
        return true;
    }
    return false;
}

bool draw(const vector<vector<char>>& table) {
    for (const auto& row : table) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> table(3, vector<char>(3, ' '));
    char user1 = 'X';
    int col, row;

    while (true) {
        cout << "Player " << user1 << "'s turn" << endl << "Enter col(1-3), row(1-3)" << endl;
        cin >> col >> row;

        col--;
        row--;

        if (table[col][row] != ' ') {
            cout << "Cell already taken, enter value again" << endl;
            continue;
        }

        table[col][row] = user1;
        display(table);

        if (win(table, user1)) {
            cout << "Player " << user1 << " is the winner!" << endl;
            break;
        }
        if (draw(table)) {
            cout << "Game is DRAW! " << endl;
            break;
        }

        if (user1 == 'X') {
            user1 = 'O';
        } else {
            user1 = 'X';
        }
    }
    return 0;
}
