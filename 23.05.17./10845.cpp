#include <iostream>
#include <queue>
#include <string>

using namespace std;
queue<int> q;


int Q(string s){
    int res = -2;
    if(s == "push"){
        int num;
        cin >> num;
        q.push(num);
    }else if(s == "pop"){
        if(q.empty()){
            res = -1;
        }else{
            res = q.front();
            q.pop();
        }
    }else if(s == "size"){
        res = q.size();
    }else if(s == "empty"){
        if(q.empty()){
            res = 1;
        }else{
            res = 0;
        }
    }else if(s == "front"){
        if(q.empty()){
            res = -1;
        }else{
            res = q.front();
        }
    }else if(s == "back"){
        if(q.empty()){
            res = -1;
        }else{
            res = q.back();
        }
    }
    return res;
}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        string s;
        cin >> s;

        int res = Q(s);
        if(res != -2)
            cout << res << endl;
    }

    return 0;
}