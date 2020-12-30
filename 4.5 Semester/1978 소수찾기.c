#include <stdio.h>

int main() {
	int N; //입력받을 수의 갯수
	int num, cnt = 0; //입력값과 소수의 갯수 카운트
	int check; //소수인지 아닌지 판별

	scanf("%d", &N); //입력받을 수의 갯수 입력

	for(int i = 0; i < N; i++){ // N번까지 소수확인
		scanf("%d", &num); // N개의 숫자만큼 숫자 입력
		check = 0; // 소수판별여부는 다음 숫자를 판별할때마다 0으로 초기화 됨

		if(num == 1)continue; // 1은 소수가 아니기 때문에 카운트하지 않고 continue

		for(int j = 2; j < num; j++){ // 2부터 각 숫자 직전 숫자까지 확인
			if(num%j == 0)check = 1; // 만약 2를 제외한 숫자 중 나누어 떨어지는 숫자가 있을 경우 check = 1
		}
		if(check == 0)cnt++; // check가 0으로 남아 있을 경우(소수일 경우) count +1, 2는 맨 처음 check가 0부터 시작하기 때문에 count + 1이 됨.
	}

	printf("%d", cnt);
}
