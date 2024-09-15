#include <iostream>
#include<stack>
using namespace std;

   void stockSpanProblem(vector<int> stocks, vector<int> span){
      stack<int> s;
      s.push(0);
      span[0] = 1;
      for(int i= 1; i< stocks.size(); i++){
          while(!s.empty() && stocks[i] >= stocks[s.top()]){
              s.pop();
          }

          if(s.empty()){
              span[i] = i+1;
          }else{
              int prevHigh = s.top();
              span[i] = i - prevHigh;
          }
      }
      for(int i=0; i<span.size(); i++){
          cout << span[i] << " ";
      }
      cout << endl;

}
int main() {
   vector<int> stocks = {100, 80, 60, 70, 60, 85, 100};
   vector<int> span = {0,0,0,0,0,0,0};

    stockSpanProblem(stocks, span);

    return 0;
}
