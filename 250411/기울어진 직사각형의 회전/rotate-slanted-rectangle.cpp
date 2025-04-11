#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[100][100];
int temp[100][100];

int r, c, m1, m2, m3, m4, dir;


void paste(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            temp[i][j] = grid[i][j];
        }
    }
}

void print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
           cout << temp[i][j] << ' ';
        }
        cout << '\n';
    }
}


void move(int y, int x, int m1, int m2, int dir){
    vector<int> dx, dy, count;

    if(dir == 0){
        dx = {1, -1, -1, 1};
        dy = {-1, -1, 1, 1};
        count = {m1, m2, m1, m2};
    }else{
        dx = {-1, 1, 1, -1};
        dy = {-1, -1, 1, 1};
        count = {m2, m1, m2, m1};
    }

    paste();
    int curX;
    int curY;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < count[i]; j++){
            curX = x + dx[i];
            curY = y + dy[i];

            temp[curY][curX] = grid[y][x];

            x = curX;
            y = curY;
        }
    }

    print();   
}




int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    move(r-1, c-1, m1, m2, dir);
    return 0;
}
