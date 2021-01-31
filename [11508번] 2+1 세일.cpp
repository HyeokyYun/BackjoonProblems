#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int i, int j)
{
    return j < i;
}

int main()
{
    int data[100001] = {0, };
    int N;
    int sum = 0;
    
    cin >> N;
		
    for(int i = 0; i < N; i++)
    {
        cin >> data[i];
    }
    
    sort(data, data+N, desc);

    for(int i = 0; i < N; i++)
    {
        if(i%3 != 2)
        {
			sum+=data[i];
		}
    }
    cout << sum;
    return 0;
}
