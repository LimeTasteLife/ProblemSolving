#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int M, N, H; // 가로, 세로, 높이
int box[101][101][101];
bool isFinished = false; // 토마토 다 익었는지 확인용.
int Tomatoes = 0; // 전체 토마토 개수
int curTomatoes = 0; // 현재 익은 토마토 개수

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> q;

void ripe(int x, int y, int z);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> M >> N >> H;
    // 넣을 때는 높이 세로 가로 순.
    for(int k = 0; k < H; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++){
                cin >> num;
                box[i][j][k] = num;

                if(num == -1) continue;

                // 익었으면 BFS 수행하기위해 큐에 넣어둠.
                if(num == 1) {
                    q.push(make_tuple(i, j, k));
                    curTomatoes++;
                }
                Tomatoes++;
            }
                
    int result = 0;
    while(!isFinished){ 
        if(curTomatoes == Tomatoes){
            // 전체토마토 개수와 현재 익은 토마토 개수가 일치하면 끝난 것.
            isFinished = true;
            break;
        }

        int prevTomatoes = curTomatoes; // 토마토 익히기 전에 이전 토마토와 개수 맞춤.

        // 반복돌면서 토마토 익히기
        int iter = q.size();
        for(int i = 0; i < iter; i++){
            tuple<int ,int, int> coord = q.front();
            q.pop();
            ripe(get<0>(coord), get<1>(coord), get<2>(coord));
        }

        result++;

        // 익혔는데 이전 토마토 개수와 현재 토마토 개수가 같으면 문제 있음.
        if(prevTomatoes == curTomatoes){
            result = -1;
            isFinished = true;
        }
    }

    cout << result << '\n';

    return 0;
}

void ripe(int x, int y, int z){
    for(int i = 0; i < 6; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];

        // 좌표검사
        if( nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;

        // 공간이 없거나 이미 익었으면 패스
        if( box[nx][ny][nz] == -1 || box[nx][ny][nz] == 1) continue;

        // 토마토 익히기
        box[nx][ny][nz] = 1;
        q.push(make_tuple(nx, ny, nz));
        curTomatoes++;
    }
    return;
}