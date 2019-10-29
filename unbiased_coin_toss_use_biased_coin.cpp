#include <iostream>
#include <cstdlib>

using namespace std;
//https://www.zhihu.com/question/304075115
// p(face) = 0.7, p(back) = 0.3;
int toss() {
  int r = rand()%10 + 1;
  return r <= 7 ? 1 : 0;
};

int coinToss() {
  double l = 0, r = 1.0;
  int count = 0;
  while(l < 0.5 && r > 0.5) {
    if(toss()) {
      r -= (r-l)*0.3;
    }
    else {
      l += (r-l)*0.7;
    }
    ++count;
  }
  // return l > 0.5;

  return count;
};
const int N = 2000000;
int main() {
  int face = 0, back = 0;
  int total_toss = 0;
  for(int i = 0; i < N; ++i) {
    // if(coinToss())
    //   face++;
    // else
    //   back++;
    total_toss += coinToss();
  }
  // cout << face << " " << back << endl;
  cout << "average coin toss is : " << (double)total_toss/N << endl;
}