#include<iostream>
using namespace std;

int findMax(int arr[], int n){
    int max = arr[0];
    for(int i=0 ;i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }else{
            continue;
        }
    }
    return max;
}

int main(){

    int arr[] = {5,4,3,9,2,-1,23,55,23,67,98,23,98};
    int n  = sizeof(arr) / sizeof(int);
    int maxValue =   findMax(arr , n);
    cout << "maxValue is : " << maxValue << endl;
    return 0;
}