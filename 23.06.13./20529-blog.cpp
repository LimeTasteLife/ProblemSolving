#include <iostream>

using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};

int mount[101][101];
bool visited[101][101];

int N,M;
bool isPeak;
int cnt = 0;

// 이름만 DFS지 그냥 재귀를 이용한 것.
void DFS(int x, int y);

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> mount[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j]) continue;
            isPeak = true;
            visited[i][j] = true;
            DFS(i,j);
            if(isPeak)cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}

void DFS(int x, int y){
    for(int dir = 0; dir < 8; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 범위 체크
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        // 나보다 큰 봉우리라면 탐색이 끝났을 때. false가 되어있으므로 봉우리 아님.
        if(mount[x][y] < mount[nx][ny]) isPeak = false;

        // 방문 체크
        if(visited[nx][ny]) continue;

        // 나랑 높이가 같은 봉우리라면 걔도 조사
        if(mount[x][y] == mount[nx][ny]){
            visited[nx][ny] = true;
            DFS(nx, ny);
        }
    }

    return;
}