#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string S;
map<string, int> m;
vector<string> vt;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> S;
        m[S]++;
    }

    for(int i = 0; i < M; i++){
        cin >> S;
        if(m[S] == 1){
            vt.push_back(S);
        }
    }

    sort(vt.begin(), vt.end());

    cout << vt.size() << endl;
    for(auto o: vt)
        cout << o << endl;
    
    return 0;
}