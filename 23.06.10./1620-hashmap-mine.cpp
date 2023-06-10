#include <iostream>
#include <map>
#include <string>

using namespace std;
int N, M;
string S;
map<string, int> m;
string name[100001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> S;
        m.insert(make_pair(S, i+1));
        name[i] = S;
    }

    for(int i = 0; i < M; i++){
        cin >> S;
        if(S[0] >= 65 && S[0] <= 90){
            // 위에서 받은 것이 문자열이라면, 영어인것을 활용.
            auto it = m.find(S);
            cout << it->second << '\n';
        }else{
            cout << name[stoi(S)-1] << '\n';
        }
    }

    return 0;
}

