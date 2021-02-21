//quick_sort
 
#include<iostream>
using namespace std;
 
void swap(int *arr,int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
 
void myQuickSort(int *arr, int start, int end){
    int pivot = arr[start];
    int left = start+1;
    int right = end;
 
    while(left <= right){
 
        while(arr[left] < pivot){ left++; } //pivot보다 작은 경우는 건너뛰고 크거나 같은경우 멈춤
        while(arr[right] > pivot) { right--; } //pivot보다 큰 경우는 건너뛰고 작거나 같은경우 멈춤
 
        if(left <= right){ swap(arr, left, right); }
    }
 
 
    if(start < end){  //1개로 쪼개질때 까지
        swap(arr, start, right);   //pivot값과 arr[right] 값 swap
 
        myQuickSort(arr, start, right-1);  //앞 부분
        myQuickSort(arr, right+1, end);    //뒷 부분
    }
 
    return;
}
 
void outPut(int *arr, int len){
 
    for(int i=0; i<len ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
 
int main(void){
    int arr[7] = {5,3,7,6,2,1,4};
    
    outPut(arr, 7);
 
    //0 ~ len-1 범위.
    myQuickSort(arr, 0, 6);
 
    outPut(arr, 7);
 
    return 0;
}
