#include <iostream>

using namespace std;

int x[100];

int dp(int n){
	if(n == 1)return 1;
	if(n == 2)return 2;
	if(x[n] != 0)return x[n]; // 만약 이미 구했던 숫자라면 바로 리턴해준다.
	return x[n] = dp(n-1) + dp(n-2); // 처음 구한 숫자를 배열에 저장한다.
}
int main() {
  cout << dp(30) << endl;
}
