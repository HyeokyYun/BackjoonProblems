#include <iostream>
#include <algorithm>

using namespace std;
// 10:15PM - 10:30PM

int main(void){
   
  int A[9] = {0, }; //같은 크기의 배열을 두개 선언해준다.
  int B[9] = {0, };
  int temp = 0;
   
  for(int i = 0; i < 9; i++){
    cin >> A[i]; // 하나의 배열에 9개의 입력을 받는다.
    B[i] = A[i]; // 그 입력을 똑같이 배열B에 저장한다.
  }
   
  sort(A, A + 9); // 배열을 오름차순으로 정렬한다.
   
  do{
    temp = 0;
    for(int i = 0; i < 7; i++){
      temp = temp + A[i]; // 인덱스 0~6번까지의 숫자의 합을 temp에 저장한다.
    }
      
    if(temp == 100){ // 만약 temp가 100이면 종료한다.
      break;
    }
      
  }while(next_permutation(A, A + 9)); // 합이 100이 되는 모든 순열을 구해서 A배열에 저장한다.
   
  for(int j = 0; j < 9; j++){
    for(int i = 0; i < 7; i++){
      if(A[i] == B[j]){ // 정답의 순서가 입력된 순서야 같아야 하기 때문에 B배열에 저장한 원래의 입력값과 A배열의 입력값이 같을 때, A배열을 출력한다.
        cout << A[i] << endl; 
      }
    }  
  }
	return 0;
}
