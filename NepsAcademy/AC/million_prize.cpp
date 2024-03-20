// AC
#include <iostream>

using namespace std;

int main(void) {
  /*The first line contains an integer N, which indicates the number of days the
   * list contains. Each of the following lines contains a single integer A, the
   * number of accesses in one day. */
  int N;
  cin >> N;

  int days = 0;
  int acesses = 0;

  int tmp;
  int i;
  for (i = 1; i <= N; i++) {
    cin >> tmp;
    acesses += tmp;

    if (acesses >= 1'000'000) {
      cout << i << endl;
      return 0;
    }
  }

  if (acesses >= 1'000'000) {
    cout << i << endl;
    return 0;
  }

  return 0;
}
