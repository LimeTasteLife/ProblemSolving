#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void){
    int N;
    deque<int> dq;
    cin >> N;

    string S;
    for(int i = 0; i < N; i++){
        cin >> S;
        if(S == "push_back"){
            int n;
            cin >> n;
            dq.push_back(n);
        }else if(S == "push_front"){
            int n;
            cin >> n;
            dq.push_front(n);
        }else if(S == "front"){
            if(dq.empty() != true)
                cout << dq.front() << endl;
            else
                cout << -1 << endl;
        }else if(S == "back"){
            if(dq.empty() != true)
                cout << dq.back() << endl;
            else
                cout << -1 << endl;
        }else if(S == "size"){
            cout << dq.size() << endl;;
        }else if(S == "empty"){
            if(dq.empty() == true)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }else if(S == "pop_front"){
            if(dq.empty() != true){
                int n = dq.front();
                dq.pop_front();
                cout << n << endl;
            }else{
                cout << -1 << endl;
            }
        }else if(S == "pop_back"){
            if(dq.empty() != true){
                int n = dq.back();
                dq.pop_back();
                cout << n << endl;
            }else{
                cout << -1 << endl;
            }
        }
    }

    return 0;
}