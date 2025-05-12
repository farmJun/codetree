#include <iostream>

using namespace std;

int n;
int grid[200][200];
int r, c;

bool isIn(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < n;
}

void print(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

}

void gravity(){
     for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {

            int curY = i;

            while(grid[curY + 1][j] == 0 && curY < n){
                grid[curY + 1][j]= grid[curY][j];
                grid[curY][j] = 0;
                curY++;
            }
        }
    }
}

void bomb(int y, int x){
    int count = grid[y][x];
    grid[y][x] = 0;

    // 위 아래로
    for(int i = 1; i < count; i++){
        if(isIn(y + i, x)){
            grid[y + i][x] = 0;
        }

        if(isIn(y - i, x)){
            grid[y - i][x] = 0;
        }

        if(isIn(y, x + i)){
            grid[y][x+i]=0;
        }

        if(isIn(y, x-i)){
            grid[y][x-i] = 0;
        }
    }
}



int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    bomb(r-1,c-1);

    //print();
    //cout << '\n';
    gravity();
    print();

    return 0;
}
