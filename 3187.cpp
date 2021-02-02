#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 250 // 최대 250개의 입력

char arr[MAX][MAX]; // 케릭터 배열을 받아온다.
int visit[MAX][MAX]; // 방문여부를 체크한다. -1이면 미방문, 1이면 방문이다.

int dx[] = {-1, 0, 0, 1}; // x좌표의 이동가능 경로
int dy[] = {0, 1, -1, 0}; // y좌표의 이동가능 경로
int T_sheepNum, T_wolfNum = 0; // 전체 양과 늑대의 수
int sheepNum, wolfNum; // 현재 양과 늑대의 수

int main() {
  int r, c; // 가로, 세로의 길이
	cin >> r >> c;

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> arr[i][j]; // arr에 문자열을 입력한다.
			visit[i][j] = arr[i][j]; // 그 입력을 그대로 visit배열에 넣어준다. 그 이유는 visit에 알맞게 크기를 할당하기 위함이다.
		}
	}

	memset(visit, -1, sizeof(visit)); // visit의 크기만큼 전체를 -1로 세팅한다.

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(arr[i][j] == '#') continue; // arr배열 입력값이 #이면 다음 인덱스를 확인한다. 이를 통해 울타리의 경계를 확인할 수 있다.

			if(visit[i][j] == -1){ // 만약 현재 인덱스가 -1, 즉 아직 방문하지 않았다면,
				sheepNum = wolfNum = 0;
				queue<pair<int, int>> q;
				q.push({i, j}); // i, j의 값을 큐에 push 한다.
				visit[i][j] = 1; // 그리고 visit의 i, j인덱스는 방문처리한다.

				if(arr[i][j] == 'k')sheepNum++; // 만약 arr의 값이 k 이면 양의 수를 증가신다.
				if(arr[i][j] == 'v')wolfNum++; // 만약 arr의 값이 v 이면 늑대의 수를 증가시킨다.

				while(!q.empty()){ // q가 empty가 될 때까지,
					int x = q.front().first; // x에 q의 가장 앞, 첫번째 값을 저장한다.
					int y = q.front().second; // y에 q의 가장 앞, 두번째 값을 저장한다.
					q.pop(); // 그리고 q의 가장 앞의 값을 pop해준다.

					for(int k = 0; k < 4; k++){// 이동경로가 상하좌우 네가지 이기 때문에 4번만 반복한다.
						int nx = x + dx[k]; // nx에 x와 dx의 값을 계산한 결과를 저장한다.
						int ny = y + dy[k]; // ny에 y와 dy의 값을 계산한 결과를 저장한다.

						if(nx >= 0 && nx >= 0 && nx < r && ny < c){ // 만약 nx와 ny가 0이상이고, r, c 보다 작은 경우,
							if(visit[nx][ny] == -1){// 아직 nx, ny를 방문하지 않았다면,
								if(arr[nx][ny] == '.'){ // arr의 nx, ny의 값이 . 이면,
									visit[nx][ny] = 1; // nx, ny를 방문처리하고
									q.push({nx, ny}); //nx, ny를 큐에 push 한다.
								}
								else if(arr[nx][ny] == 'v'){// arr의 nx, ny의 값이 v 이면,
									visit[nx][ny] = 1; // nx, ny를 방문처리하고
									q.push({nx, ny}); //nx, ny를 큐에 push 한다.
									wolfNum++; // 늑대의 수를 증가신킨다.
								}
								else if(arr[nx][ny] == 'k'){// arr의 nx, ny의 값이 k 이면,
									visit[nx][ny] = 1; // nx, ny를 방문처리하고
									q.push({nx, ny}); //nx, ny를 큐에 push 한다.
									sheepNum++; // 양의 수를 증가시킨다.
								}
							}
						}
					}
				}
				if(sheepNum > wolfNum){ // 만약 양의 수가 늑대보다 많으면
					T_sheepNum+=sheepNum; // 총 양의 수를 계산한다.
				}
				else T_wolfNum+=wolfNum; // 늑대와 양이 같거나 늑대가 더 많을 경우 총 늑대의 수를 계산한다.
			}
		}
	}
	cout << T_sheepNum << " " << T_wolfNum << endl;

	return 0;
}
​
