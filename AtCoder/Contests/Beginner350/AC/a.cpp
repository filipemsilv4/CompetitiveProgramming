#include <iostream>
#include <ostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  if (s == "ABC316") {
    cout << "No" << endl;
    return 0;
  }

  if (s <= "ABC349" && s >= "ABC001") {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}
