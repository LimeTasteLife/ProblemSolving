#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, N, M;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        cin >> N >> M;

        vector<int> v;
        queue<pair<int,int>> q;

        int num;
        for(int i = 0; i < N; i++){
            cin >> num;
            q.push(make_pair(i, num));
            v.push_back(num);
        }

        sort(v.begin(), v.end());
        // 오름차순 정렬 후 뒤에서부터 제거.

        int cnt = 0;
        while(!q.empty()){
            if(q.front().second != v.back()){
                pair<int,int> temp;
                temp = q.front();
                q.pop();
                q.push(temp);
            }else{
                cnt++;
                if(q.front().first == M){
                    break;
                }
                q.pop();
                v.pop_back();
            }
        }


        cout << cnt << '\n';
    }

    return 0;
}