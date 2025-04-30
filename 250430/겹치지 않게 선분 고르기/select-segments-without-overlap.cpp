#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x1[15], x2[15];
vector<pair<int,int>> v;
int ans;
bool visited[15];

bool possible(int start, int end){
    for(int i = start; i <= end; i++){
        if(visited[i]){
            return false;
        }
    }

    return true;
}

void alloc(int start, int end){
    for(int i = start; i <= end; i++){
        visited[i] = true;
    }

    // for(int i = 1; i < 15; i++){
    //     if(visited[i]){
    //         cout << "1 ";
    //     } else{
    //         cout << "0 ";
    //     }
    // }
    // cout << '\n';

}

void free(int start, int end){
    for(int i = start; i <= end; i++){
        visited[i] = false;
    }
    // for(int i = 1; i < 15; i++){
    //     if(visited[i]){
    //         cout << "1 ";
    //     } else{
    //         cout << "0 ";
    //     }
    // }
    // cout << '\n';
}

void solve(int cur){
    //cout << "new solve cur = " << cur << '\n';

    if(cur == n){
        //cout << "now return for cur = " << cur << '\n';
        int size = v.size();
        ans = max(ans, size);
        return;
    }


    for(int i = cur; i < n; i++){
        int start = x1[i];
        int end = x2[i];

        //cout << "for loop cur = " << cur << " i = " << i << " n = " << n  <<" start = " << start << " end = " << end << "\n\n";

        if(possible(start, end)){
            alloc(start, end);

            v.push_back({start, end});

            solve(cur + 1);

            v.pop_back();
            free(start, end);
        }

    }

    int size = v.size();
    ans = max(ans, size);
    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    solve(0);
    // Please write your code here.
    cout << ans;
    return 0;
}
