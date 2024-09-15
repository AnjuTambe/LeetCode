#include <iostream>
#include<string>
#include "vector"
#include<list>
using namespace std;

//create stack using LinkedList(with STL list)
template <class T>
class Stack{

    list<T> ll;
public:
    void push(T val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    T top(){
       return ll.front();  // which is the head of the ll
    }
    bool isEmpty(){
        return ll.size() == 0;
    }
};


int main() {
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout <<s.top()<< " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

