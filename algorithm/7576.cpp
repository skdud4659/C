#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1001][1001];
bool visit[1001][1001];

int v1[4] = {-1, 0, 1, 0};
int v2[4] = {0, 1, 0, -1};

queue<pair<int, int>> que;


void bfs() {
    
    while(que.empty() == 0) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++) {
            int xx = v1[i] + x;
            int yy = v2[i] + y;
            
            if(xx >= 0 && xx < N && yy >= 0 && yy < M) {
                if(arr[xx][yy] != -1 && !visit[xx][yy]) {
                    arr[xx][yy] = arr[x][y] + 1;
                    visit[xx][yy] = true;
                    que.push({xx, yy});
                }
            }
        }
    }
    
}

int MAX() {
    int max = -1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == 0) { // 못채운 곳이 있다면
                return -1;
            }
            max = (max < arr[i][j])? arr[i][j]:max;
        }
    }
    if(max == 1) // 모든 토마토가 처음부터 익은상태. 값이 아무것도 늘지 않은 상태.
        return 0;
    
    return max - 1; // 토마토 위치가 1이며, 인접 날짜는 첫날부터 2부터 시작했으므로 하루를 빼줘야 함.
}

int main() {
    int i, j;
    
    
    cin >> M >> N;
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            cin >> arr[i][j];
            
            if(arr[i][j] == 1) {
                que.push({i, j});
                visit[i][j] = 1;
            }
        }
    }
    bfs();
    
    cout << MAX();
}