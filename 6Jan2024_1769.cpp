// Problem Link-> https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// //O(n^2) TC -> this solution will also work becoz boxes length is of 2*10^3 and n^2 is less than 4*10^6 which will work in 1 sec
// vector<int> minOperations(string boxes)
// {
//     int n = boxes.size();
//     vector<int> vec(n, 0);
//     for (int i = 0; i < n; ++i)
//     {
//         int cnt = 0;
//         for (int j = 0; j < n; ++j)
//         {
//             if (boxes[j] == '1' && i != j)
//             {
//                 cnt += abs(i - j);
//             }
//         }
//         vec[i] = cnt;
//     }
//     return vec;
// }

vector<int> minOperations(string boxes)
{
    int n = boxes.size();
    int sum = 0, left = 0, right = 0, prefix = 0;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (boxes[i] == '1')
        {
            right++;
            sum += i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int moves = sum + prefix;
        ans[i] = moves;
        if (boxes[i] == '1')
        {
            left++;
            right--;
        }
        sum -= right;
        prefix += left;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<int> vec = minOperations(s);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}