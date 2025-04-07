#include <iostream>

using namespace std;

int n, m, ans;
int grid[20][20];

bool isGold(int y, int x){
    return grid[y][x] == 1;
}

bool isIn(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < n;
}

int getCost(int k){
    return (k * k) + ((k+1)*(k+1));
}

int getGold(int y, int x, int k){
    if(k == 0){
        if(isGold(y,x)){
            return 1;
        }
        return  0;
    }
    
    int cnt = 0;
    int t = 0;

    for(int i = y - k; i <= y; i++){
        for(int j = -t; j <= t; j++){
            if(isIn(i,x + j)){
                if(isGold(i,x + j)){
                    cnt++;
                }
            }
        }
        t++;
    }
    t = 0;

    for(int i = y + k; i > y; i--){
        for(int j = -t; j <= t; j++){
            if(isIn(i,x + j)){
                if(isGold(i,x + j)){
                    cnt++;
                }
            }
        }
        t++;
    }

    return cnt;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k =0; k <= 2 * n; k++){
                int cost = getCost(k);
                int gold = getGold(i, j, k);
                
                int goldMoney = gold * m;
 
                if(goldMoney >= cost){
                    ans = max(ans, gold);
                }
            }
        }
    }

    cout << ans;
    return 0;
}

