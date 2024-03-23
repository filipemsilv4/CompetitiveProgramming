// Source: https://neps.academy/course/programming-logic/lesson/is-it-prime

#include <iostream>

using namespace std;

int main() {
  long long int N;
  cin >> N;

  if (N == 1) {
    cout << "N" << endl;
    return 0;
  }

  for (long long int i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      cout << "N" << endl;
      return 0;
    }
  }

  cout << "S" << endl;
}
