#include <iostream>

using namespace std;

int N, M;
int map[101][71];
bool visited[101][71];
bool isPeak;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int x, int y);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j]) continue;

            isPeak = true;
            visited[i][j] = true;
            DFS(i, j);
            if(isPeak) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}

void DFS(int x, int y){
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 좌표검사
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

        // 봉우리를 하려면 주변보다 커야 함.
        if(map[x][y] < map[nx][ny]) isPeak = false;
            
        if(visited[nx][ny]) continue;
       

        if(map[x][y] == map[nx][ny]){
            visited[nx][ny] = true;
            DFS(nx, ny);
        }            
    }

    return;
}