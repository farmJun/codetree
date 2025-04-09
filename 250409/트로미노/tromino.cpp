#include <iostream>

using namespace std;

int n, m, ans;
int grid[200][200];

int arrX[] = { 1, 0 , -1, 0, 3 , 0, 1 , 0 , -1 , 0};
int arrY[] = { 0 ,1 , 0, -1, 0, 3, 0 , -1 , 0 , 1};


int cul1(int y, int x){
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;

    for(int i = 0; i < 2; i++){
        if(y + arrY[i] < 0 || y + arrY[i] >= n){
            num1 = 0;
            break;
        }

        if(x+ arrX[i] < 0 || x + arrX[i] >= m){
            num1 = 0;
            break;            
        }

        num1 += grid[y + arrY[i]][x + arrX[i]];
    }
    num1 += grid[y][x];

    for(int i = 2; i < 4; i++){
        if(y + arrY[i] < 0 || y + arrY[i] >= n){
            num2 = 0;
            break;
        }

        if(x+ arrX[i] < 0 || x + arrX[i] >= m){
            num2 = 0;
            break;            
        }

        num2 += grid[y + arrY[i]][x + arrX[i]];
    }
    num2 += grid[y][x];

    for(int i = 8; i < 10; i++){
        if(y + arrY[i] < 0 || y + arrY[i] >= n){
            num4 = 0;
            break;
        }

        if(x+ arrX[i] < 0 || x + arrX[i] >= m){
            num4 = 0;
            break;            
        }

        num4 += grid[y + arrY[i]][x + arrX[i]];
    }
    num4 += grid[y][x];

    for(int i = 6; i < 8; i++){
        if(y + arrY[i] < 0 || y + arrY[i] >= n){
            num3 = 0;
            break;
        }

        if(x+ arrX[i] < 0 || x + arrX[i] >= m){
            num3 = 0;
            break;            
        }

        num3 += grid[y + arrY[i]][x + arrX[i]];
    }
    num3 += grid[y][x];
    
    return max(max(num1, num2), max(num3, num4));
}

int cul2(int y, int x){
    int num1 = 0;
    int num2 = 0;
    
    if(y + arrY[4] > n || x + arrX[4] > m){
        num1 = 0;
    }else{
        for(int i = 0; i < 3; i++){
            num1 += grid[y][x + i];
        }
    }
   
    if(y + arrY[5] > n || x + arrX[5] > m){
        num2 = 0;
    }else{
        for(int i = 0; i < 3; i++){
            num2 += grid[y + i][x];
        }
    }

    return max(num1, num2);
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int big = max(cul1(i,j), cul2(i, j));
            ans = max(ans, big);
        }
    }

    cout << ans;

    return 0;
}

