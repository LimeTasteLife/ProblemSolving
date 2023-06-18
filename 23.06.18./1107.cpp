#include <iostream>
#include <string>

using namespace std;
bool broken[10] = {false};

bool checkCh(int curCh);

int main(void){
    int targetCh;
    int brokenNum;

    cin >> targetCh >> brokenNum;

    while(brokenNum--){
        int num;
        cin >> num;
        broken[num] = true;
    }
    // 고장난 버튼 체크

    int minNum = abs(targetCh - 100);

    for(int i = 0; i < 1000000; i++){
        if(checkCh(i)){
            int num = abs(targetCh - i) + to_string(i).length();
            minNum = min(minNum, num);
        }
    }

    cout << minNum << endl;

    return 0;
}

bool checkCh(int curCh){
    string str = to_string(curCh);

    for(int i = 0; i < str.length(); i++){
        if(broken[str[i] - '0']){
            return false;
        }
    }
    return true;
}