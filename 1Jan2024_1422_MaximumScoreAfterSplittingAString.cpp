// Problem link:- https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/




#include<bits/stdc++.h>

using namespace std;
int maxScore(string s) {
    int ones = 0;
    int zeros = 0;
    int bestScore = INT_MIN;

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '1') {
            ones++;
        } else {
            zeros++;
        }

        bestScore = max(bestScore, zeros - ones);
    }

    if (s[s.size() - 1] == '1') {
        ones++;
    }

    return bestScore + ones;

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << "Maximum score for the string " <<"'"<<s<<"'"<<" : " << maxScore(s) << endl;
    }
    return 0;

}
