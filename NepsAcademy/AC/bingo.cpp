// Source: OBI 2020 - First Phase - A
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// compare by value
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  int N; // Ammount of cards
  int K; // Numbers per card
  int U; // Largest natural that can occur on a card.

  cin >> N >> K >> U;

  vector<unordered_set<int>> cards(N + 1);
  vector<pair<int, int>> scores(N + 1); // pair <score, index>

  int tmp;
  for (int i = 1; i <= N; i++) {
    for (int little_k = 1; little_k <= K; little_k++) {
      cin >> tmp;
      cards[i].insert(tmp);
    }
  }

  bool done = false;
  for (int i = 1; i <= U; i++) {
    cin >> tmp;
    if (done)
      break;
    for (int j = 1; j < cards.size(); j++) {
      if (cards[j].find(tmp) != cards[j].end()) {
        scores[j] = {scores[j].first + 1, j};
        if (scores[j].first == K)
          done = true;
      }
    }
  }

  sort(scores.begin(), scores.end(), compare);

  for (int i = 1; i < scores.size(); i++) {
    if (scores[i].first == K) {
      cout << scores[i].second << " ";
    }
    // cout << "[i" << scores[i].second << "," << scores[i].first << "]"
    //      << " ";
  }
  cout << endl;
}
