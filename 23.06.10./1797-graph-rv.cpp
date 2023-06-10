#include <iostream>

using namespace std;

int T, M, N, K;
bool map[50][50];

void dfs(int x, int y);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> M >> N >> K;
        int x, y, ans;
        for(int i = 0; i < K; i++){
            cin >> x >> y;
            map[x][y] = true;
        }

        ans = 0;
        for(int row = 0; row < N; row++){
            for(int col = 0; col < M; col++){
                if(map[col][row]){
                    ans++;
                    dfs(col, row);    
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

void dfs(int x, int y){
    // 인덱스 검사
    if( x < 0 || y < 0) return;
    if( x >= 50 || y >= 50) return;

    if(!map[x][y]) return;

    map[x][y] = false;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}