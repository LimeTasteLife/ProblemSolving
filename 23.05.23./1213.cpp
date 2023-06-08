#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int aFlag[26];
int idx;

bool checkNums(string S);

int main(void){
    string S;
    cin >> S;
    
    sort(S.begin(), S.end());

    bool flag = checkNums(S);
    if(S.length() == 1){
        cout << S << endl;
    }else if(flag){
        char newString[S.length()];
        
        for(int i = 0; i < S.length(); i++)
            newString[i] = '1';
            
        int sidx = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < aFlag[i]/2; j++){
                newString[sidx] = 'A' + i;
                newString[S.length() - sidx - 1] = 'A' + i;
                sidx++;
            }
            if(aFlag[i] % 2 == 1){
                newString[S.length()/2] = 'A' + i;
            }
            //cout << i << "th: " << newString << endl;
        }
        cout << newString << endl;
    }else{
        cout << "I'm Sorry Hansoo" << endl;
    }

    return 0;
}

bool checkNums(string S){
    for(int i = 0; i < S.length(); i++){
        aFlag[S[i] - 65]++;
    }

    bool odd = false;
    for(int i = 0; i < 26; i++) {
        if(aFlag[i] % 2 == 1 && odd == false){
            idx = i;
            odd = true;
        }else if(aFlag[i] % 2 == 1 && odd == true){
            return false;
        }
    }
    return true;
}