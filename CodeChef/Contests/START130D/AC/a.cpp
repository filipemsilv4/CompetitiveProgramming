#include <iostream>
#include <ostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n < 60) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}
