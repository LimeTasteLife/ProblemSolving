#include <iostream>
#include <deque>
#include <string>

using namespace std;

// 일단은 각 반복(testcase)마다 명령어를 받는다.
// 그 후 문자열을 받는다. 파싱해서 vector에 숫자를 넣는다.
// 이후 명령어에 따라 vector를 변환한다.
// R이면 앞 뒤 변경, D면 맨 앞에 수 제거.
// 마지막으로 그 결과를 출력한다.
// 에러가 나면, 에러를 출력한다.
// >> 에러의 경우? 더 이상 남아있는 숫자가 없을 때 D 연산을 수행하면 에러가 난다.

// 첫시도, 타임오버났다. 어떻게 시간을 줄일까?
// 일단 R 연산을 reverse로 한다.
// 또, D연산을 통해 맨 앞 요소를 제거하기 때문에 O(n)의 시간이 걸린다.
// 이를 해결하기 위해 queue를 쓴다면?

// 또 시간초과가 걸려서 Solution을 봤다.
// deque로 자료구조를 변경하는 것 까지는 맞았다.
// Solution에서는 일일히 데이터를 뒤집지 않고, Reverse가 없으면 pop_front
// reverse가 있으면 pop_back로 논리적으로 나눠서 물리적인 연산을 최소화 했다.

// 출력을 반복문 기반으로 하니까 자꾸 틀린다. 잠깐 쉬었다하자.
// 솔루션은 함수형프로그래밍을 지향한다.

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    while(T--){
        bool errorFlag = false;
        bool reverseFlag = false;
        string cmd;
        cin >> cmd;
        int num;
        cin >> num;

        string s;
        cin >> s;
        deque <int> dq;
        string temp = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '['){
            }else if(s[i] == ',' || s[i] == ']'){
                if(num == 0){
                    break;
                }
                dq.push_back(stoi(temp));
                temp = "";
            }else{
                temp.push_back(s[i]);
            }
        }
        
        for(int i = 0; i < cmd.length(); i++){
            if(cmd[i] == 'R'){
                if(reverseFlag)
                    reverseFlag = false;
                else
                    reverseFlag = true;
            }else if(cmd[i] == 'D'){
                if(dq.size() == 0){
                    errorFlag = true;
                    break;
                }
                if(reverseFlag){
                    dq.pop_back();
                }else{
                    dq.pop_front();
                }
            }
        }

        if(errorFlag){
            cout << "error\n";
        }else if(reverseFlag){
            cout << "[";
            while(!dq.empty()){
                if(dq.size()!=1) cout << dq.back() << ",";
                else cout << dq.back();
                dq.pop_back();
            }
            cout << "]\n";
        }else if(!reverseFlag){
            cout << "[";
            while(!dq.empty()){
                if(dq.size()!=1) cout << dq.front() << ",";
                else cout << dq.front();
                dq.pop_front();
            }
            cout << "]\n";
        }else if(num == 0){
            cout << "[]\n";
        }
    }

    return 0;
}