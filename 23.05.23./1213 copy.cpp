#include <iostream>
#include <string>

using namespace std;

int cnt[26];

int main(void){
    string S;
    cin >> S;

    for(int i = 0; i < S.length(); i++){
        cnt[S[i] - 'A']++;
    }

    int checkOdd = 0;
    int idx = -1;
    for(int i = 0; i < 26; i++){
        if(cnt[i] % 2 == 1){
            checkOdd++;
            idx = i;
        }
    }

    if(checkOdd > 1){
        cout << "I'm Sorry Hansoo" << endl;
    }else{
        string newS;

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < cnt[i]/2; j++){
                newS = newS + char('A' + i);
            }
        }

        if(idx != -1){
            newS = newS + char('A' + idx);
        }

        for(int i = 25; i >= 0; i--){
            for(int j = 0; j < cnt[i]/2; j++){
                newS = newS + char('A' + i);
            }
        }
        cout << newS << endl;
    }

    return 0;
}

