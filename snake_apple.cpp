#include<iostream>
#include<vector>
#include<conio.h>
#include<windows.h>
#include <ctime>
using namespace std;
int score=0;
struct point{
    int x,y;
};
class Snake {
public:
    vector<point> body;
    string dir;   
    Snake(int x, int y) {
        point head = {x, y};
        body.push_back(head);
        dir = "RIGHT";
    }
    bool isdead() {
    if (body[0].x <= 0 || body[0].x >= 19 || body[0].y <= 0 || body[0].y >= 19)
        return true;
    
    for (int i = 1; i < body.size(); i++) {
        if (body[0].x == body[i].x && body[0].y == body[i].y)
            return true;
    }
    return false;
    }
    void move() {
        for (int i =body.size()-1; i>0;i--) {
            body[i] =body[i - 1];
        }
        if (dir=="UP")body[0].x--;
        if (dir=="DOWN")body[0].x++;
        if (dir=="LEFT")body[0].y--;
        if (dir=="RIGHT")body[0].y++;
    }
    void grow(){
        point newpart=body.back();
        body.push_back(newpart);
    }
    void setdir(){
        if(kbhit()){
            char ch = getch();
            if (ch == 'a') dir="LEFT";
            if (ch == 's') dir="DOWN";
            if (ch == 'w') dir="UP";
            if (ch == 'd') dir="RIGHT";      
        }
    }
    void crawl(vector<vector<char>>& vec) {
    for (int i = 0; i < body.size(); i++)
        {
        vec[body[i].x][body[i].y] = 'O';
        }
    }
};

class apple{
    public:
    int x;
    int y;
    void genapple(vector<vector<char>>& vec){
        while (true) {
        x = rand()%18+1;
        y = rand()%18+1;
        if (vec[x][y]==' ') {
            vec[x][y]='*';
            break; 
        }
    }
}
};
void board(vector<vector<char>>& vec){
    cout<<endl<<endl;
    cout<<"      GAME SCORE :  "<<score<<endl<<endl;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            cout<<vec[i][j];
        }
        cout<<endl;
    }
}

int main(){
    srand(time(0));
    vector<vector<char>> vec(20,vector<char>(20,' '));
    for(int i=0;i<20;i++){
        vec[i][0]='|';
        vec[0][i]='-';
        vec[19][i]='-';
        vec[i][19]='|';
    }
    vec[0][0]='#';
    vec[19][19]='#';
    vec[0][19]='#';
    vec[19][0]='#';
        //head 
    Snake b(2,3);
    b.crawl(vec);
    apple a;
    a.genapple(vec);
    board(vec);
     while (true) {
        for(int i = 1; i < 19; i++) {
            for(int j = 1; j < 19; j++) {
                vec[i][j] = ' ';
            }
        }
        vec[a.x][a.y] = '*';
        b.setdir();
        b.move();
        if (b.isdead()) {
            system("cls");
            cout << "\n\n\t !!! GAME OVER BROOO !!!! \n";
            cout << "\tFinal Score: " << score << "\n";
            break;
        }
        if (b.body[0].x == a.x && b.body[0].y == a.y) {
            b.grow();
            score += 10;
            a.genapple(vec);
        }
        b.crawl(vec);
        system("cls");
        board(vec);
        Sleep(250);
    }
    
}