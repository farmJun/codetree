#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> v;

void solve(int num){
    if(num == N){
        for(int i = 0 ; i < v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= K; i++){
        v.push_back(i);
        solve(num + 1);
        v.pop_back();
    }
}

int main() {
    cin >> K >> N;

    solve(0);

    return 0;
}
