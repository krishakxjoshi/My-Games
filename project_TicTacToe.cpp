#include <iostream>
#include <vector>
using namespace std;

void space() {
    for (int i = 0; i < 20; i++) {
        cout << " ";
    }
}

bool checkchar(vector<vector<char>>& grid, int x, int y) {
    return grid[x][y] == '_';
}

void printgrid(vector<vector<char>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        space();
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << "       ";
        }
        cout << endl << endl;
    }
    cout << endl << endl << endl;
}

bool check(vector<vector<char>>& grid) {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '_') {
            cout << "WINNER WINNER CHICKEN DINNER !!!" << grid[i][0] << endl;
            return false;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '_') {
            cout << "WINNER WINNER CHICKEN DINNER !!!" << grid[0][i] << endl;
            return false;
        }
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '_') {
        cout << "WINNER WINNER CHICKEN DINNER !!!" << grid[0][0] << endl;
        return false;
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != '_') {
        cout << "WINNER WINNER CHICKEN DINNER !!!" << grid[0][2] << endl;
        return false;
    }

    return true; // Game continues
}

class Player {
public:
    char character;

    void setchar(int num) {
        cout << "Enter character for Player " << num << ": ";
        cin >> character;
    }
};

int main() {
    Player a, b;
    a.setchar(1);
    b.setchar(2);

    cout << "\nPlayer 1: " << a.character;
    cout << "\nPlayer 2: " << b.character << "\n\n";

    cout << "_____ L E T  T H E  G A M E  B E G I N _____\n\n";

    vector<vector<char>> grid(3, vector<char>(3, '_'));
    printgrid(grid);

    int i = 0;
    while (i < 9) {
        cout << "Enter coordinates: ";
        int x, y;
        cin >> x >> y;
        if (x < 0 || x > 2 || y < 0 || y > 2) {
            cout << "Invalid coordinates! Try again.\n";
            continue;
        }
        if (!checkchar(grid, x, y)) {
            cout << "Error!! GALAT BLOCK HAI \n";
            continue;
        }
        grid[x][y] = (i % 2 == 0) ? a.character : b.character;
        i++;

        printgrid(grid);

        if (!check(grid)) break;
    }

    if (i == 9) {
        cout << "Game Draw!!!\n";
    }

    return 0;
}

