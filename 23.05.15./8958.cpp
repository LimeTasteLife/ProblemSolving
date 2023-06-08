#include <iostream>
#include <string>

using namespace std;

int OX(string& s){
    int sum = 0;
    int cnt = 0;

    for(char &v: s){
        if(v == 'O'){
            cnt++;
            sum += cnt;
        } else {
            cnt = 0;
        }
    }

    return sum;
}

int main(){
    int T;
    cin >> T;
    string s;

    for(int i = 0; i < T; i++){
        cin >> s;

        cout << OX(s) << endl;
    }

    return 0;
}