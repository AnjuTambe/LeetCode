#include <iostream>
using namespace std;
void allOccurrence(int arr[], int i, int n, int key){
    if( i == n){
        return;
    }
    if(arr[i] == key){
        cout << i << " ";
    }
    allOccurrence(arr, i+1, n, key);
}

int main() {
   int arr[] = {3,2,4,5,6,2,7,2,2};
   allOccurrence(arr,0,9,2);
    return 0;
}