#include <iostream>
using namespace std;

bool isprime(int number)
{
    bool isprime = true;
    if (number <= 1)
    {
        isprime = false;
    }
    for (int counter = 2; counter * counter <= number; counter++)
    {
        if (number % counter == 0)
        {
            isprime = false;
            break;
        }
    }
    return true;
}

int main()
{
    int number;
    cout << "Enter a number: " << endl;
    cin >> number;

    if (isprime(number))
    {
        cout << "prime";
    }
    else
    {
        cout << "not prime";
    }
    return 0;
}