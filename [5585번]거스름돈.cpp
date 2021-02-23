#include <iostream>

using namespace std;

int main() {
  int N;
	int count = 0;
	int rest;
	int i;

	cin >> N;

	rest = 1000 - N;

	while(1){
		if(rest == 0)break;
		if(rest >= 500){
			rest -= 500;
			count++;
			continue;
		}
		if(rest >= 100){
			rest-=100;
			count++;
			continue;
		}
		if(rest >= 50){
			rest-=50;
			count++;
			continue;
		}
		if(rest >= 10){
			rest-=10;
			count++;
			continue;
		}
		if(rest >= 5){
			rest-=5;
			count++;
			continue;
		}
		if(rest >= 1){
			rest-=1;
			count++;
			continue;
		}
	}
	cout << count << endl;
  return 0;
}
