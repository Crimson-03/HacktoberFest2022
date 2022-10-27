#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 2147483647

int solveMem(vector<int> &nums, int x, vector<int> &dp)
{
    // base case
    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solveMem(nums, x - nums[i],dp);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    dp[x] = mini;

    return dp[x];
}

int main()
{

    vector<int> nums{1, 2, 5};
    int x = 11;

    vector<int> dp(x + 1, -1);
    int ans = solveMem(nums, x, dp);
    if (ans == INT_MAX)
        cout << "-1" << endl;
    else
        cout << ans << endl;


    return 0;
}
