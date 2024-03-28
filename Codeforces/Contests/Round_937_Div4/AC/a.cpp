#include <iostream>

using namespace std;

void test() {
  int a, b, c;
  cin >> a >> b >> c;

  // stair
  if (a < b && b < c) {
    cout << "STAIR" << endl;
    return;
  }

  // peak
  if (a < b && b > c) {
    cout << "PEAK" << endl;
    return;
  }

  cout << "NONE" << endl;

  return;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    test();
  }
}
