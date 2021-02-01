#include<iostream>
#include<queue>
//#include<cstring> //memset 메소드 사용

#define MAX 201
using namespace std;
int dist[MAX][MAX];
int dx[]={-2, -2, 0, 0, 2, 2}; // 각 경우의 x좌표 값
int dy[]={-1, 1, -2, 2, -1, 1}; // 각 경우의 y좌표 값
 
int main(void)
{
    int n; // 체스판의 크기
    cin >> n;

    int s, c, es, ec; // 시작점, 도착점
    cin >> s >> c >> es >> ec;

	//memset(dist, -1, sizeof(dist)); //거리를 모두 -1로 초기화

    queue<pair<int, int>> q;
    q.push({s, c}); // 시작점 큐에 입력
    dist[s][c] = 0; // 처음 거리를 0으로 함.

    while(!q.empty()) // 모든 큐를 비울 때 까지
    {
        int x = q.front().first; // x에는 큐의 가장 앞쪽 x좌표
        int y = q.front().second; // y에는 큐의 가장 앞쪽 y좌표
        q.pop(); // 가장 앞쪽의 값을 pop 해줌.

        for(int i = 0; i < 6; i++) // 총 이동 가능한 모든 경우는 6가지
        {
            int nx = x + dx[i]; // nx에 처음 push 됐던 x값 + dx의 i번째 인덱스의 값을 더해줌.
            int ny = y + dy[i]; // ny에 처음 push 됐던 y값 + dy의 i번째 인덱스의 값을 더해줌.
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 이동하게 되는 nx, ny의 값이 0보다 작거나, 체스판의 크기를 넘어가면 continue

			//if(dist[nx][ny] == -1)
            if(dist[nx][ny] == 0) // 아직 확인하지 않은 경우
            {
                q.push({nx, ny}); // nx, ny값을 푸쉬해줌
                dist[nx][ny] = dist[x][y] + 1; // 확인함으로 변경
            }
        }
    }
    if(dist[es][ec] == 0) // 만약 도착점을 한번도 방문하지 않았을 경우, -1 출력
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[es][ec] << endl; // 도착점을 방문 했을 때의 숫자를 출력
    }
    return 0;
}
