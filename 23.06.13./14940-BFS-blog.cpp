#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1000][1000];
bool visited[1000][1000];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M;
queue<pair<int,int>> q;

void BFS();

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> num;
            if(num == 2){
                q.push(make_pair(i,j));
                visited[i][j] = true;
                map[i][j] = 0;
            }else if(num == 0)
                visited[i][j] = true;
            else
                map[i][j] = num;
        }

    BFS();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] == false){
                cout << "-1 ";
            }else{
                cout << map[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                if(visited[nx][ny] == false){
                    map[nx][ny] = map[x][y] + 1;
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

}