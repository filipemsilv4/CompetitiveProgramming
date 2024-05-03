#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main() {
  int n;
  cin >> n;

  while (n != 0) {
    vector<lli> factors = trial_division1(n);

    if (factors.size() % 2 == 0){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    cin >> n;
  }
}
