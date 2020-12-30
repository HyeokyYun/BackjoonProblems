#include<stdio.h>
int main(){
	int input; // input number
	int count = 0; // 동전의 총 갯수
	
	scanf("%d", &input); // 입력값을 받음
	
	while(input > 0){ // 인풋이 0 보다 클 경우 동작.
		if(input % 5 == 0){ // input이 5의 배수인지 확인/우선 5의 배수인지를 확인하는 것이 가장 적은 갯수의 동전을 구할 때 적합
			input -=5; // 만약 5의 배수라면 현 가격에서 5를 빼줌
			count++; // 카운트 증가
			//printf("1: %d\n", input);
		}
		else if(input % 3 ==0){// input이 5의 배수가 아니라면 3의 배수인지 확인
			input -=3; // 만약 3의 배수라면 현 가격에서 3을 빼줌
			count++;
			//printf("2: %d\n", input);
		}
		else if(input > 5){ // input이 5의 배수도 아니고 3의 배수도 아면서 5보다 클 경우
			input -=5; // 현 가격에서 5를 빼줌
			count++; // 카운트 증가
			//printf("3: %d\n", input);
		}
		else{ // input이 3이나 5로 나누어 지지 않고 5보다 작다면 -1 출력.
			count = -1;
			break;
		}
		
	}
	printf("%d", count);
}
