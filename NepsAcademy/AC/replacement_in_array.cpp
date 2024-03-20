#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(10);

  int small;
  cin >> small;
  v[0] = small;

  for (int i = 1; i < 10; i++) {
    cin >> v[i];
    if (v[i] < small)
      small = v[i];
  }

  cout << "Menor: " << small << endl;
  cout << "Ocorrencias:";

  for (int i = 0; i < v.size(); i++) {
    if (v[i] == small) {
      cout << " " << i;
      v[i] = -1;
    }
  }

  cout << endl;

  for (const auto &a : v) {
    cout << a << " ";
  }

  cout << endl;

  return 0;
}
