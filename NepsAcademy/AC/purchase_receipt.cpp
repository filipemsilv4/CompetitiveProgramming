// OBI 2018 - Third Phase
#include <iostream>

using namespace std;

int R, K; // Total purchase value, ammount of items
int ans = 0;

void combinations(int level, int min, int max) {
  // If there's only 1 item left
  if (level == 1) {
    // If the min value available is less or equal to the max, the item's value
    // is valid and it's max
    if (min <= max)
      ans++;
  } else {
    for (int i = min; i <= max; i++) {
      combinations(level - 1, i + 1, max - i);
    }
  }
}

int main() {
  cin >> R >> K;

  combinations(K, 1, R);

  cout << ans << endl;
}
