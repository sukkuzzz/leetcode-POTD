// Problem Link-> https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    vector<int> vec(s.size() + 1, 0);
    for (int i = 0; i < shifts.size(); ++i)
    {
        int start = shifts[i][0], end = shifts[i][1], dir = shifts[i][2];
        if (dir)
        {
            vec[start]++;
            vec[end + 1]--;
        }
        else
        {
            vec[start]--;
            vec[end + 1]++;
        }
    }
    for (int i = 1; i < vec.size(); ++i)
    {
        vec[i] += vec[i - 1];
    }
    string res;
    for (int i = 0; i < s.size(); ++i)
    {
        int cnt = vec[i] % 26;
        if (cnt < 0)
            cnt += 26;
        char curr = char((s[i] - 'a' + cnt) % 26 + 97);
        res.push_back(curr);
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<int>> shifts(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> shifts[i][j];
        }
    }
    cout << shiftingLetters(s, shifts) << endl;
    return 0;
}