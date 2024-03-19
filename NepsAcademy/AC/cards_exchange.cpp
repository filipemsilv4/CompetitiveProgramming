//AC
#include <iostream>
#include <vector>

using namespace std;

int main(){
    /*The first line contains two integers A and B, 
    separated by a blank space, indicating respectively 
    the number of cards Alice and Beatriz have*/
    int A, B;
    cin >> A >> B;

    // 10ˆ5
    int vecSize = 1'000'000;

    vector<int> cardsA(vecSize);
    vector<int> cardsB(vecSize);

    int card;
    for (int i = 1; i <= A; i++){
        cin >> card;
        cardsA[card] = 1;
    }

    for (int i = 1; i <= B; i++){
        cin >> card;
        cardsB[card] = 1;
    }

    int cntA = 0;
    int cntB = 0;
    for (int i = 1; i < vecSize; i++){
        if (cardsA[i] == 1 && cardsB[i] == 0) cntA++;
        else if (cardsB[i] == 1 && cardsA[i] == 0) cntB++;
    }

   cntA < cntB ? cout << cntA << endl : cout << cntB << endl;
}