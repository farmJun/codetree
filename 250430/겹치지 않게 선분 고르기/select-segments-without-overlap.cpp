#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x1[15], x2[15];
vector<pair<int,int>> v;
int ans;

bool over(int start1, int end1, int start2, int end2){
    return (start1 <= start2 && start2 <= end1) || (start1 <= end2 && end2 <= end1)
        || (start2 <= start1 && start1 <= end2) || (start2 <= end1 && end1 <= end2);
}

bool possible(){
    for(int i = 0 ; i < (int) v.size(); i++){
        int start1 = v[i].first;
        int end1 = v[i].second;

        for(int j = i + 1; j < (int) v.size(); j++){
            int start2 = v[j].first;
            int end2 = v[j].second;

            if(over(start1,end1,start2,end2)){
                return false;
            }
        }
    }
  
  return true;
}


void solve(int cur){
    if(cur == n){
        if(possible()){
            int size = v.size();
            ans = max(ans, size);
        }
        return;
    }

    int start = x1[cur];
    int end = x2[cur];

    v.push_back({start, end});

    solve(cur + 1);

    v.pop_back();
    
    solve(cur + 1);

    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    solve(0);
    cout << ans;
    return 0;
}
