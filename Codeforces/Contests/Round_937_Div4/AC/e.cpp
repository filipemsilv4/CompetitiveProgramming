#include <iostream>
#include <vector>

using namespace std;

void compute_divisors(int n, vector<int> *divisors) {
  divisors->push_back(1);
  for (int i = 2; i + i <= n; i++) {
    if (n % i == 0)
      divisors->push_back(i);
  }
  divisors->push_back(n);
}

int testcase() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> divisors;
  compute_divisors(n, &divisors);

  // for each possible substring size that we can sum to get n characters:
  for (const auto &d : divisors) {
    // we take a substring in 2 different places (so we dont end up with, for
    // example "bbbb" from "baaa" and k=1 doesn't count as a correct answer)
    string sub = s.substr(0, d);
    string sub_r = s.substr(s.size() - d, d);

    string sum;
    string sum_r;
    int times = n / d;

    // sum the substring n/d times, so we end up with sum and sum_r with size n
    for (int i = 0; i < times; i++) {
      sum += sub;
      sum_r += sub_r;
    }

    // verify if the sum strings differ from s by only 1
    int count = 0, count_r = 0;
    for (int i = 0; i < s.size(); i++) {
      if (sum[i] != s[i])
        count++;
      if (sum_r[i] != s[i])
        count_r++;
    }

    if (count <= 1 || count_r <= 1)
      return d;
  }

  return n;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
    cout << testcase() << endl;
}
