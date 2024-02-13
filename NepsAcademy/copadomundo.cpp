#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define TEAMCOUNT 16

int main(void){
    vector<pair<int, char> > scores; // score, team

    // Read all the scores
    int a;
    for (int i = 0; i < (TEAMCOUNT - 1) * 2; i++){
        cin >> a;
        if (i < TEAMCOUNT)
            scores.push_back({a, 'A' + i});
        else
            scores.push_back({a, '?'});
    }
    
    // Compute first phase results
    for (int i = 0; i < TEAMCOUNT; i += 2){
        if (scores[i].first > scores[i+1].first){
            scores[i/2 + TEAMCOUNT].second = scores[i].second;
            continue;
        }
        scores[i/2 + TEAMCOUNT].second = scores[i+1].second;
    }

    // Compute second phase results
    int start_res_index = TEAMCOUNT + (TEAMCOUNT/2);
    int j = 0;
    for (int i = TEAMCOUNT; i < start_res_index; i += 2){
        if (scores[i].first > scores[i+1].first){
            scores[j + start_res_index].second = scores[i].second;
            j++;
            continue;
        }
        scores[j + start_res_index].second = scores[i+1].second;
        j++;
    }

    // Compute third phase results
    start_res_index = TEAMCOUNT + TEAMCOUNT/2 + TEAMCOUNT/4;
    j = 0;
    for (int i = TEAMCOUNT + TEAMCOUNT/2; i < start_res_index; i += 2){
        if (scores[i].first > scores[i+1].first){
            scores[j + start_res_index].second = scores[i].second;
            j++;
            continue;
        }
        scores[j + start_res_index].second = scores[i+1].second;
        j++;
    }


    // cout << "------Tf:" << endl;
    // for (auto s : scores){
    //     cout << s.second << ":" << s.first << " | "  << endl;
    // }
    // cout << "------" << endl;

    if (scores[(TEAMCOUNT - 1) * 2 - 1].first > scores[(TEAMCOUNT - 1) * 2 - 2].first){
        cout << scores[(TEAMCOUNT - 1) * 2 - 1].second << endl;
        return 0;
    }
    cout << scores[(TEAMCOUNT - 1) * 2 - 2].second << endl;

    return 0;
}

