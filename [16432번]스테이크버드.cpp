#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int fruit[1001]={0,};
	int snakebody;
	int fruitNum;

	cin >> fruitNum >> snakebody;
	
	for(int i = 0; i < fruitNum; i++){
		cin >> fruit[i];
	}
	sort(fruit, fruit+fruitNum);

	for(int i = 0; i < fruitNum; i++){
		if(snakebody >= fruit[i]){
			snakebody++;
		}
		else {
			break;
		}
	}
		cout << snakebody;
}
