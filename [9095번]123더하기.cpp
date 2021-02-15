#include <iostream>

using namespace std;

int dp[1000] = {0,};

int sum(int x){
	if(x < 0)return 0;
	if(x <= 1)return 1;
	if(dp[x] != 0)return dp[x];
	return dp[x] = sum(x - 3) + sum(x - 2) + sum(x - 1);
}

int main() {
  int n;
	
	cin >> n;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cout << sum(x) << endl;
	}
}
