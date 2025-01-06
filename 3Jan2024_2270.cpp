// Problem Link -> https://leetcode.com/problems/number-of-ways-to-split-array/?envType=daily-question&envId=2025-01-03

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int waysToSplitArray(vector<int> &nums)
{
    int n = nums.size();
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += nums[i];
    int cnt = 0;
    long long currCnt = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        currCnt += nums[i];
        if (currCnt >= sum - currCnt)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << waysToSplitArray(nums) << endl;
}
