#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N, M;
string name[100001];
map<string, int> m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string S;
        cin >> S;
        name[i] = S;
        m.insert(make_pair(S,i));
    }

    for(int i = 1; i <= M; i++){
        string S;
        int n;
        cin >> S;
        if(isdigit(S[0]) == true){
            n = stoi(S);
            cout << name[n] << '\n';
        }else{
            auto it = m.find(S);
            cout << it->second << '\n';
        }
    }
    return 0;
}