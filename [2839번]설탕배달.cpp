#include <iostream>

using namespace std;

int main() {
  int n;
	int count = 0;

	cin >> n;

	while(1){
		if(n % 5 == 0){ // 만약 n이 5의 배수라면
			count += (n/5); // count는 5의 배 만큼 증가신킨다.
			cout << count << endl; // 5의 배수일 경우 5를 나눈 숫자가 가장 적은 갯수가 된다.
			break; // 이후에는 3을 빼줄 이유가 없기 때문에 반복을 종료한다.
		}
		// n이 5의 배수가 아닐 경우
		n -= 3; // 만약 n이 5의 배수가 아니라면 3을 빼준다.
		count++; // 그리고 count를 하나 증가시킨다.

		if(n < 0){ // 만약 n이 0보다 작을 경우, 구할 수 없기 때문에 -1을 출력한다.
			cout << -1 << endl;
			break;
		}
	}
}
