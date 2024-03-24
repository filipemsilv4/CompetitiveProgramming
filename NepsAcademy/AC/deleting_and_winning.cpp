// Source:
// https://neps.academy/course/medal-at-obi-%5Bp2%5D-30728-F7qNoJXKR96WmsxX3DABS4/lesson/deleting-and-winning

#include <iostream>

using namespace std;

string del_and_win(int N, int D, string s) {
  string ans; // its a stack
  int erased = 0;

  for (auto c : s) {
    // while we haven't erased D numbers, ans isn't empty and the last number in
    // char is less than c, pop the last number in the stack ans
    while (erased < D && ans.size() > 0 && ans.back() < c) {
      ans.pop_back();
      erased++;
    }

    // add c to the ans stack
    if (ans.size() < N - D) {
      ans.push_back(c);
    }
  }

  return ans;
}

int main() {
  int N; // numbers
  int D; // numbers to be erased
  string s;

  while (true) {
    cin >> N >> D;

    if (N == 0 && D == 0)
      break;

    cin >> s;
    cout << del_and_win(N, D, s) << endl;
  }

  return 0;
}
