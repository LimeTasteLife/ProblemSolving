#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N, M;
    cin >> N;
    int list[N];
    for(int i = 0; i < N; i++)
        cin >> list[i];
    cin >> M;
    int goal[M];
    for(int i = 0; i < M; i++)
        cin >> goal[i];

    sort(list, list + N);

    int cnt;
    for(int i = 0; i < M; i++){
        cnt = 0;
        for(int j = 0; j < N; j++){
            if(goal[i] == list[j])
                cnt++;
            if(goal[i] < list[j])
                break;
        }
        cout << cnt << ' ';
    }
    cout << endl;

    return 0;
}