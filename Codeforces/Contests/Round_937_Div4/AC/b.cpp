#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  int n;
  for (int i = 0; i < t; i++) {
    cin >> n;

    bool alternate = true;
    for (int i = 1; i <= n; i++) {

      alternate = !alternate;

      for (int j = 1; j <= n; j++) {
        if ((j + alternate) % 2 == 1) {
          cout << "##";
          continue;
        }
        cout << "..";
      }

      cout << endl;
      for (int j = 1; j <= n; j++) {
        if ((j + alternate) % 2 == 1) {
          cout << "##";
          continue;
        }
        cout << "..";
      }

      cout << endl;
    }
  }
}
