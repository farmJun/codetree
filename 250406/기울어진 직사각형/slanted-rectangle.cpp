#include <iostream>

using namespace std;

int n, ans;
int grid[20][20];

int dx[] = {1, -1, -1, 1};
int dy[] = {-1, -1, 1, 1};


bool isIn(int y, int x){
    return y >= 0 && y < n && x >=0 && x < n;
}

int solve(int r, int l, int y, int x){
    int cnt = 0;
    int curX = x;
    int curY = y;
    int tmpR = r;
    int tmpL = l;

    int right = 0;
    while(isIn(curY,curX) && r-- ){
           //cout << curY << ' ' << curX << ' ' << grid[curY][curX] << '\n';
            cnt += grid[curY][curX];
            curX += dx[0];
            curY += dy[0];
            right++;
    }


    if(!isIn(curY, curX)){
        curX -= dx[0];
        curY -= dy[0];
        cnt -= grid[curY][curX];
        right--;
    }
    
    if(tmpR > right){
        return 0;
    }

    int left = 0;
    while(isIn(curY,curX) && l--){
            //cout << "heel o " << l << '\n';
           // cout << curY << ' ' << curX << ' ' << grid[curY][curX] << '\n';
            cnt += grid[curY][curX];
            curX += dx[1];
            curY += dy[1];
            left++;
    }
   
    if(!isIn(curY, curX)){
        curX -= dx[1];
        curY -= dy[1];
        cnt -= grid[curY][curX];
        left--;
    }

    if(tmpL > left){
        return 0;
    }

    while(tmpR--){
            //cout << curY << ' ' << curX << ' ' << grid[curY][curX] << '\n';
            cnt += grid[curY][curX];
            curX += dx[2];
            curY += dy[2];
            if(!isIn(curY, curX)){
                return 0;
            }
    }

    if(!isIn(curY, curX)){
        curX -= dx[2];
        curY -= dy[2];
        cnt -= grid[curY][curX];  
    }


    while(tmpL--){
            //cout << curY << ' ' << curX << ' ' << grid[curY][curX] << '\n';
            cnt += grid[curY][curX];
            curX += dx[3];
            curY += dy[3];
             if(!isIn(curY, curX)){
                return 0;
            }
    }

    if(!isIn(curY, curX)){
        curX -= dx[3];
        curY -= dy[3];
        cnt -= grid[curY][curX];  
    }


    return cnt;
}
int solve2(int r, int l, int y, int x){
    int cnt = 0;
    int curX = x;
    int curY = y;
    int tmpR = r;
    int tmpL = l;

    int right = 0;
    while(isIn(curY,curX) && r-- ){
           cout << curY << ' ' << curX << ' ' << grid[curY][curX] << '\n';
            cnt += grid[curY][curX];
            curX += dx[0];
            curY += dy[0];
            right++;
    }

   cout << '\n';

    if(!isIn(curY, curX)){
        curX -= dx[0];
        curY -= dy[0];
        cnt -= grid[curY][curX];
        right--;
    }
    
    if(tmpR > right){
        return 0;
    }

    int left = 0;
    while(isIn(curY,curX) && l--){
    //cout << "heel o " << l << '\n';
           cout << curY << ' ' << curX << ' ' << grid[curY][curX] << '\n';
            cnt += grid[curY][curX];
            curX += dx[1];
            curY += dy[1];
            left++;
    }
   
   cout << '\n';
    if(!isIn(curY, curX)){
        curX -= dx[1];
        curY -= dy[1];
        cnt -= grid[curY][curX];
        left--;
    }

    if(tmpL > left){
        return 0;
    }

    while(tmpR--){
            cout << curY << ' ' << curX << ' ' << grid[curY][curX] << '\n';
            cnt += grid[curY][curX];
            curX += dx[2];
            curY += dy[2];
            if(!isIn(curY, curX)){
                return 0;
            }
    }
   cout << '\n';

    if(!isIn(curY, curX)){
        curX -= dx[2];
        curY -= dy[2];
        cnt -= grid[curY][curX];  
    }


    while(tmpL--){
            cout << curY << ' ' << curX << ' ' << grid[curY][curX] << '\n';
            cnt += grid[curY][curX];
            curX += dx[3];
            curY += dy[3];
             if(!isIn(curY, curX)){
                return 0;
            }
    }
   cout << '\n';

    if(!isIn(curY, curX)){
        curX -= dx[3];
        curY -= dy[3];
        cnt -= grid[curY][curX];  
    }


    return cnt;
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for(int k = 1; k <= n -1; k++){
                for(int z =1; z <= n -1; z++){
                    int size = solve(k, z, i, j);
                    ans = max(ans, size);
                }
            }
        }
    }

     cout << ans;

    //cout << solve(1,3,4,2);
    //cout << solve(1,4,4,4);
    return 0;
}

