#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;


void print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << grid[i][j] << ' ';
        } 
        cout << '\n';
    }       
     cout << '\n';
}

// 반시계
void move1(int y, int x, int m1, int m2, int m3, int m4){
    int m1y = y - m1;
    int m1x = x + m1;
    int pass1 = grid[m1y][m1x];


    int m2y = m1y - m2;
    int m2x = m1x - m2;
    int pass2 = grid[m2y][m2x];

    int m3y = m2y + m3;
    int m3x = m2x - m3;
    int pass3 = grid[m3y][m3x];
    
    int m4y = y;
    int m4x = x;
    int pass4 = grid[m4y][m4x];
    

    int i = m1y + 1;
    int j = m1x - 1;
    while(m1--){
        grid[i-1][j+1] = grid[i][j];
        i++;
        j--;
    }
    grid[m4y-1][m4x+1] = pass4;


    i = m2y + 1;
    j = m2x + 1;
    while(m2--){
        grid[i-1][j-1] = grid[i][j];
        i++;
        j++;
    }
    grid[m1y-1][m1x-1] = pass1;


    i = m3y - 1;
    j = m3x + 1;
    while(m3--){
        grid[i+1][j-1] = grid[i][j];
        i--;
        j++;
    }
    grid[m2y+1][m2x-1]=pass2;


    i = m4y - 1;
    j = m4x - 1;
    while(m4--){
        grid[i+1][j+1] = grid[i][j];
        i--;
        j++;
    }
    grid[m3y+1][m3x+1]=pass3;

}

// 시계
void move2(int y, int x, int m1, int m2, int m3, int m4){
    int m1y = y - m1;
    int m1x = x + m1;
    int pass1 = grid[y][x];


    int m2y = m1y - m2;
    int m2x = m1x - m2;
    int pass2 = grid[m1y][m1x];

    int m3y = m2y + m3;
    int m3x = m2x - m3;
    int pass3 = grid[m2y][m2x];
    
    int m4y = y;
    int m4x = x;
    int pass4 = grid[m3y][m3x];
    

    int i = m1y + 1;
    int j = m1x - 1;
    while(m1--){
        grid[i+1][j-1] = grid[i][j];
        i--;
        j++;
    }
    grid[m1y][m1x] = pass2;


    i = m2y;
    j = m2x;
    while(m2--){
        grid[i+1][j+1] = grid[i][j];
        i--;
        j--;
    }
    grid[m2y][m2x] = pass3;


    i = m3y - 1;
    j = m3x + 1;
    while(m3--){  
        grid[i-1][j+1] = grid[i][j];
        i++;
        j--;
    }
    grid[m3y][m3x]=pass4;


    i = m4y;
    j = m4x;
    while(m4--){
        grid[i-1][j-1] = grid[i][j];
        i++;
        j++;
    }
    grid[m4y-1][m4x-1]=pass1;

}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    if(dir == 0){
        move1(r-1,c-1,m1,m2,m3,m4);
    }else{
        move2(r-1,c-1,m1,m2,m3,m4);
    }
    print();

    return 0;
}
