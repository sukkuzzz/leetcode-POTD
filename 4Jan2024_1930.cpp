// Problem link-> https: // leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int countPalindromicSubsequence(string s)
{
    int n = s.size();
    vector<vector<int>> vec(26, vector<int>(2, -1));
    for (int i = 0; i < n; ++i)
    {
        if (vec[s[i] - 'a'][0] == -1)
        {
            vec[s[i] - 'a'][0] = i;
        }
        else
        {
            vec[s[i] - 'a'][1] = i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (vec[i][0] != -1 && vec[i][1] != -1)
        {
            set<char> st;
            for (int j = vec[i][0] + 1; j < vec[i][1]; ++j)
            {
                st.insert(s[j]);
            }
            cnt += st.size();
        }
    }
    return cnt;
}
int main()
{
    string s;
    cin >> s;
    cout << countPalindromicSubsequence(s) << endl;
}