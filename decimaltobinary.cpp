#include<iostream>
using namespace std;
int main(){
    int decimal;
    int binary = 0;
    int position = 1;
    cout << "Enter decimal number" << endl;
    cin >> decimal;
    while(decimal > 0){
        int remainder = decimal %2;
        binary = binary + (remainder * position);
        decimal = decimal /2;
        position = position * 10;
    }
    cout << "Binary Representation" << binary << endl;
    return 0;

}