#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

vector<int> binary_decimals;
vector<bool> dp(N);

int main() {
  binary_decimals.push_back(1);
  dp[1] = true;

  // Fill all binary decimals up to some value that fits the test cases
  for (int i = 0; i < 100; i++) {
    if (binary_decimals[i] >= 10000)
      break;
    int val = binary_decimals[i] * 10;
    binary_decimals.push_back(val);
    binary_decimals.push_back(val + 1);
    dp[val] = true;
    dp[val + 1] = true;
  }

  // For all the numbers within the problem's bounds...
  for (int i = 2; i <= N; i++) {
    for (auto const &d : binary_decimals) {
      // If we can divide it by the d binary decimal
      if (i % d == 0) {
        // And the result can also be divided by a binary decimal
        if (dp[i / d] == true) {
          // So the number can be represented as as a product of binary decimals
          dp[i] = true;
        }
        // this works because we are computing all the numbers in ascending
        // order, so if we find, for example, 100, we already found the answer
        // to 10
      }
    }
  }

  // Queries
  int t, q;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> q;
    if (dp[q]) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
    continue;
  }
}
