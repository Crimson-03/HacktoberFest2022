#include <iostream>
#include <vector>
using namespace std;

int solveMem(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }

    if (dp[index][maxWeight] != -1)
        return dp[index][maxWeight];

    int include = 0;
    if (weight[index] <= maxWeight)
        include = value[index] + solveMem(weight, value, index - 1, maxWeight - weight[index], dp);

    int exclude = 0 + solveMem(weight, value, index - 1, maxWeight, dp);
    dp[index][maxWeight] = max(exclude, include);
    return dp[index][maxWeight];
}

int main()
{
    int n = 4, maxWeight = 5;
    vector<int> weigth = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    cout << solveMem(weigth, value, n - 1, maxWeight, dp)<<endl;

    return 0;
}
