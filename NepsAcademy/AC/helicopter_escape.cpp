#include <iostream>

using namespace std;

int main() {
  int h, p, f, d; // helicopter, police, fugitive, direction
  cin >> h >> p >> f >> d;

  while (true) {
    f += d;
    if (f == -1)
      f = 15;
    else if (f == 16)
      f = 0;
    if (f == p) {
      cout << "N" << endl;
      return 0;
    }
    if (f == h) {
      cout << "S" << endl;
      return 0;
    }
  }

  return 0;
}
