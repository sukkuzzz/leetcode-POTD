#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
const int M = 1e9 + 7;
// Time complexity O((words.length)^2*(words[i].length+words[j].length)) order pf 0(n^2*(m+n)) It will work because of the constraints
bool kmp(string s, string t)
{
    int i = 0, j = 1;
    vector<int> lps(s.size(), 0);
    while (i < j && j < s.size())
    {
        if (s[i] == s[j])
        {
            lps[j] = i + 1;
            i++;
        }
        else
        {
            i = 0;
        }
        j++;
    }
    i = 0;
    j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            i++;
        }
        else
        {
            i = i > 0 ? lps[i - 1] : 0;
            if (s[i] == t[j])
                i++;
        }
        j++;
    }
    if (i == s.size())
        return true;
    return false;
}

vector<string> stringMatching(vector<string> &words)
{
    int n = words.size();
    vector<string> ans;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && words[i].size() < words[j].size() && kmp(words[i], words[j]))
            {
                ans.push_back(words[i]);
                break;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i)
        cin >> words[i];
    vector<string> ans = stringMatching(words);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}