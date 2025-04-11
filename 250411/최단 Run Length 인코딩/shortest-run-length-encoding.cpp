#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<char> q;
deque<char> tmpQ;
string A;

int solve(char c){

    int num = 1;
    while(!tmpQ.empty() && tmpQ.front() == c){
        tmpQ.pop_front();
        num++;
    }

    if(num == 10){
        return 3;
    }else{
        return 2;
    }
}

deque<char> move(int count){

    deque<char> tmp = q;

    while(count--){
        char last = tmp.back();
        tmp.pop_back();
        tmp.push_front(last);
    }
    return tmp;
}


int main() {
    cin >> A;

    for(int i = 0; i < A.size(); i++){
        q.push_back(A[i]);
    }

    int ans = 9999999;
    for(int i = 0; i < A.size(); i++){
        tmpQ = move(i);
        int num = 0;
        while(!tmpQ.empty()){
            char front = tmpQ.front();
            tmpQ.pop_front();
            num += solve(front);
        }
        ans = min(num, ans);
    }

    cout << ans;

    return 0;
}
