// Source: OBI 2014 - First Phase
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> og_queue(N); // stores the original queue, also works as pointer
                           // to the mask position

  vector<bool> queue_mask(50'001); // masks the original queue

  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    queue_mask[tmp] = true; // this person is on the queue
    og_queue[i] = tmp;      // this person is on the queue
  }

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    cin >> tmp;
    queue_mask[tmp] = false; // this person left the queue, so update the mask
  }

  for (int i = 0; i < og_queue.size(); i++) {
    // print the queue following the mask
    if (queue_mask[og_queue[i]]) {
      cout << og_queue[i] << " ";
    }
  }

  cout << endl;
}
