#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long int N;
  cin >> N;

  vector<long long int> v(N);

  for (long long int i = 0; i < N; i++) {
    cin >> v[i];
  }

  long long int end = v[N - 1] * v[N - 2] * v[N - 3];
  // Negative * Negative = Positive, so the answer may be 2 times the smallests
  // times the biggest, very clever
  long long int neg = v[0] * v[1] * v[N - 1];

  cout << (end > neg ? end : neg) << endl;

  return 0;
}
