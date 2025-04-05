#include <iostream>

using namespace std;

int n, m, ans = -9999999999;
int grid[5][5];

bool visited[5][5];
bool visited2[5][5];

bool isIn(int y, int x){
    return y >= 0 && y < n && x >=0 && x < m;
}

void clear(){
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            visited[i][j] = false;
        }
    }
}

void clear2(){
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            visited2[i][j] = false;
        }
    }
}

bool check(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] && visited2[i][j]){
                return false;
            }
        }
    }
    return true;
}

int solve(int up, int right, int y, int x){

    if(!isIn(y + up, x + right)){
        return 0;
    }

    int cnt = 0;
    for(int i = y; i <= y + up; i++ ){
        for(int j= x; j <= x + right; j++){
            cnt += grid[i][j];
            visited[i][j] = true;
        }
    }
    
    return cnt;
}

int solve2(int up, int right, int y, int x){

    if(!isIn(y + up, x + right)){
        return 0;
    }

    int cnt = 0;
    for(int i = y; i <= y + up; i++ ){
        for(int j= x; j <= x + right; j++){
            cnt += grid[i][j];
            visited2[i][j] = true;
        }
    }
    
    return cnt;
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

            if(i == n-1 && j == m-1){
                continue;
            }

            // 첫 번째 직사각형
            for(int k = 0; k < n; k++){
                for(int z = 0; z < m; z++){
                    if(!isIn(i + k, j + z)){
                        continue;
                    }

                    int box1= solve(k,z,i,j);

                    for(int i2= 0; i2 <n; i2++){
                        for(int j2 = 0; j2 < m; j2++){

                            if(visited[i2][j2]){
                                continue;
                            }

                            for(int k2 =0; k2 < n; k2++){
                                for(int z2 =0; z2 <m; z2++){
                                    if(!isIn(i2 + k2, j2 + z2)){
                                        continue;
                                    }
                                    int box2 = solve2(k2, z2, i2, j2);

                                    if(check()){
                                        ans = max(ans, box1 + box2);
                                    }
                                    clear2();
                                }
                            }
                        }
                    }
                    clear();
                    clear2();
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}

