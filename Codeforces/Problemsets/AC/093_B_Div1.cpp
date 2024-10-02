/*
g++ -std=c++17 -o bin/out 093_B_Div1.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"
#define bilhao 1000000000

using namespace std;

const lli p = 31, p2 = 101;
const lli m = bilhao + 9, m2 = bilhao + 21;

vector<lli> h;
vector<lli> p_pow;

void compute_p_pow(lli up_to){
    p_pow.resize(up_to + 1, 0);
    p_pow[0] = 1;
    for (lli i = 1; i < (lli)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;
}

void compute_h(string const &t){
    lli T = t.size();

    h.resize(T + 1, 0);
    for (lli i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
}

vector<lli> rabin_karp(lli needle_size, string const& text, lli l_text, lli r_text) {
    lli S = needle_size, T = r_text;

    lli h_s = h[needle_size];

    vector<lli> occurrences;
    for (lli i = 0 + l_text; i + S - 1 < T; i++) {
        lli cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}

pair<vector<lli>, lli> prefix_function(string s, lli n) {
    lli biggest = 0;
    vector<lli> pi(n);
    for (lli i = 1; i < n; i++) {
        lli j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        if (pi[i] > biggest) biggest = pi[i];
    }
    return {pi, biggest};
}

int main(){
    string s;
    cin >> s;

    pair<vector<lli>, lli> prefix_function_result = prefix_function(s, (lli)s.length() - 1ll);
    vector<lli> prefix_values = prefix_function_result.first;
    lli longest_prefix_suffix = prefix_function_result.second;

    // cout << "string: ";
    // for (auto c : s) cout << c << " ";
    // cout << endl;
    // cout << "prefix: ";
    // for (auto c : prefix_values) cout << c << " ";
    // cout << endl;

    compute_p_pow(s.size());
    compute_h(s);

    vector<lli> matching_positions;
    for (lli candidate_length = longest_prefix_suffix; candidate_length >= 1; candidate_length--){
        matching_positions = rabin_karp(candidate_length, s, s.size() - candidate_length, s.size());
        if (matching_positions.empty()) continue;
        // cout << "prefix size " << pattern_size << " is also suffix\n";

        for (lli i = 0; i < candidate_length; i++)
            cout << s[i];
        cout << endl;
        return 0;
    }

    cout << "Just a legend" << endl;
}
