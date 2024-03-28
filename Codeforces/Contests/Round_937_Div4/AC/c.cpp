#include <iostream>
#include <string>

using namespace std;

void convert() {
  string s;
  cin >> s;

  int hr = stoi(s.substr(0, 2));

  string ampm = "AM";

  if (hr != 0 && hr >= 12) {
    ampm = "PM";
  }

  if (hr > 12) {
    hr = hr - 12;
  } else if (hr == 0) {
    hr = 12;
  }

  if (hr < 10) {
    cout << "0";
  }

  cout << hr << ":" << s.substr(3, 2) << " " << ampm << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    convert();
  }
}
