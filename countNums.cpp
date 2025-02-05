#include <iostream>
using namespace std;

//function to calculate the sum of the digits

int digitSum(int num){
    int sum = 0;
    while(num > 0){
        sum = sum + (num %10);
        num = num / 10;
    }
    return sum;
}


void funCount(int inputNum1 , int inputNum2){
    int count =0;
    for(int i=1; i<= inputNum1; i++){
        if(digitSum(i) == inputNum2){
            count++;
        }
    }
    cout  << (count > 0 ? count : -1) << endl;
}


int main() {
     int inputNum1 = 20;
     int inputNum2  = 5;

    funCount(inputNum1 , inputNum2);
    return 0;
}
