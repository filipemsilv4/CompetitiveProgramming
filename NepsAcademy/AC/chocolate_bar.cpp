#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  int st1_x, st1_y, st2_x, st2_y;

  cin >> N;
  cin >> st1_x >> st1_y >> st2_x >> st2_y;

  N = N / 2;

  // If sticker 1 and 2 are in different sides, there's a solution
  if ((st1_x <= N && st2_x > N) || (st1_y <= N && st2_y > N)) {
    cout << 'S' << endl;
    return 0;
  }

  if ((st2_x <= N && st1_x > N) || (st2_y <= N && st1_y > N)) {
    cout << 'S' << endl;
    return 0;
  }

  cout << 'N' << endl;
  return 0;
}
