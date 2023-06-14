#include <iostream>
#include <queue>

using namespace std;

int M, N; // 가로, 세로
int box[1001][1001];
int Tomatoes = 0;
int curTomatoes = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int,int>> q;

void BFS(int x, int y);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> box[i][j];
            if(box[i][j] == -1) continue;
            else if(box[i][j] == 1) {
                curTomatoes++;
                q.push(make_pair(i,j));
            }
            Tomatoes++;
        }

    int result = 0;
    while(1){
        if( Tomatoes == curTomatoes){
            break;
        }

        int prevTomatoes = curTomatoes;

        int iter = q.size();
        for(int i = 0; i < iter; i++){
            BFS(q.front().first, q.front().second);
            q.pop();
        }

        result++;

        if( prevTomatoes == curTomatoes){
            result = -1;
            break;
        }
    }

    cout << result << '\n';

    return 0;
}

void BFS(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if( nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

        if(box[nx][ny] == 1 || box[nx][ny] == -1) continue;

        box[nx][ny] = 1;
        q.push(make_pair(nx, ny));
        curTomatoes++; 
    }
    return;
}