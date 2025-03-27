#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt;
vector<int> v;

void solve(){

    if(v.size() == n){
        cnt++;
        return;
    }

    for(int i = 1; i <= 4; i++){
        int size = v.size();

        if(size + i <= n){
            for(int j = 0; j < i; j++){
                v.push_back(i);
            }
            solve();
             for(int j = 0; j < i; j++){
                v.pop_back();
            }
        }
    }
}

int main() {
    cin >> n;

    solve();

    cout << cnt;
    
    return 0;
}
