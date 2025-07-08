#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
bool check(vector<vector<char>>& grid) {
    for (int i = 1; i < 4; i++) {
        if (grid[i][1] == grid[i][2] && grid[i][2] == grid[i][3] && grid[i][1] != ' ') {
            cout << "WINNER WINNER CHICKEN DINNER !!!" << grid[i][1] << endl;
            return false;
        }
    }
    for (int i = 1; i < 4; i++) {
        if (grid[1][i] == grid[2][i] && grid[2][i] == grid[3][i] && grid[1][i] != ' ') {
            cout << "WINNER WINNER CHICKEN DINNER !!!" << grid[0][i] << endl;
            return false;
        }
    }
    if (grid[1][1] == grid[2][2] && grid[2][2] == grid[3][3] && grid[1][1] != ' ') {
        cout << "WINNER WINNER CHICKEN DINNER !!!" << grid[1][1] << endl;
        return false;
    }
    if (grid[1][3] == grid[2][2] && grid[2][2] == grid[3][1] && grid[1][3] != ' ') {
        cout << "WINNER WINNER CHICKEN DINNER !!!" << grid[1][3] << endl;
        return false;
    }

    return true; 
}
class Player {
public:
    char x;
public:
    void character() {
        cout<<"enter character: ";
        cin>>x;
    }
public:
    void assign(vector<vector<char>>& vec){
        int t,u;
        cout<<"enter coordinates! ; ";
        cin>>t>>u;
        vec[t+1][u+1]=x;
    }
};

void board(vector<vector<char>>& vec) {
    for(int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            cout<<" "<<vec[i][j];
            if(j>0&&j<3) cout << " |";
        }
        cout <<endl;
        if (i>0 && i<3)cout<<"  ---+---+---" <<endl;
    }
}

int main() {
    Player a,b;
    a.character();
    b.character();
    vector<vector<char>>vec(4,vector<char>(4,' '));
    for (int i=1;i<4;i++) {
        vec[0][i] ='0'+(i - 1);
    }
    for (int i=1;i<4;i++) {
        vec[i][0] ='0'+(i - 1);
    }

    cout << "\n/// LETS BEGIN THIS GAME ///\n\n";
    board(vec);
    int i=0;
    while(i<=8){
        if(i%2==0)a.assign(vec);
        else b.assign(vec);
        if(!check(vec))break;
        system("cls");
        board(vec);
    }
    
}
