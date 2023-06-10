#include <iostream>

using namespace std;

int N, M;
bool pos[1001][1001];

void dfs(int x, int y);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // 좌표 입력
    int x, y;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        pos[x][y] = true;
        pos[y][x] = true;
    }

    // 정답 찾기
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(pos[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

void dfs(int x, int y){
    if(!pos[x][y]) return;

    pos[x][y] = false;
    pos[y][x] = false;

    for(int i = 0; i < N; i++){
        dfs(i, y);
    }

    return;
}