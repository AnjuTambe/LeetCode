#include <iostream>
using namespace std;

int  binarySearchRecursion(int arr[], int st, int end, int key){
   if(st > end){
       return -1;
   }
   int mid = (st + end)/2;
   if(arr[mid] == key){
       return mid;
   }
   else if(arr[mid] < key){
     return  binarySearchRecursion(arr,mid+1,end,key);
   }
   else{
     return  binarySearchRecursion(arr,st, mid -1,key);
   }
}

int main() {
   int arr[] = {1,2,3,4,5,6,7};
   int result =  binarySearchRecursion(arr, 0, 6,5);
   cout << "result is : " << result<<endl;
   return 0;
}
