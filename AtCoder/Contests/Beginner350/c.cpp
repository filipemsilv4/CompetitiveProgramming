#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<pair<int, int>> op;
int n;

void merge(vector<int> &a, int begin, int mid, int end) { int ptr1 = }

void merge_sort(vector<int> &a, int begin, int end) {
  int mid = begin + (end - begin) / 2;
  merge_sort(&a, begin, mid);
  merge_sort(&a, mid + 1, end);
  merge(&a, begin, mid, end);
}

int main() {
  cin >> n;

  vector<int> a(n + 1);

  int count = 0;
  for (int i = 1, tmp; i <= n; i++) {
    cin >> tmp;
    a[i] = tmp;
  }
}
