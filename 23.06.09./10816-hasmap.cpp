#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <int, int> um;
int N, M, card;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> card;
        um[card]++;
    }


    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> card;
        cout << um[card] << " ";
    }

    return 0;
}