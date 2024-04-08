// https://codeforces.com/problemset/problem/118/A

#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

bool is_vowel(char c) {
  vector<char> vowels = {'a', 'o', 'y', 'e', 'u', 'i'};
  for (auto const &ch : vowels) {
    if ((char)tolower(c) == ch)
      return true;
  }
  return false;
}

int main() {
  string s;
  cin >> s;

  for (auto const &c : s) {
    if (is_vowel(c)) {
      continue;
    }
    cout << "." << (char)tolower(c);
  }

  cout << endl;
}
