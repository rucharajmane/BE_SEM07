#include <iostream>
#include <vector>
using namespace std;

int knapsack(int index, int current_weight, const vector<int> &weights, const vector<int> &values, const int &n, const int &max_capacity, vector<vector<int> > &dp)
{
    if (index >= n)
        return 0;

    if (dp[index][current_weight] != -1)
        return dp[index][current_weight];

    int notPick = knapsack(index + 1, current_weight, weights, values, n, max_capacity, dp);
    int pick = 0;

    if (max_capacity >= current_weight + weights[index])
        pick = values[index] + knapsack(index + 1, current_weight + weights[index], weights, values, n, max_capacity, dp);

    return dp[index][current_weight] = max(pick, notPick);
}

int main()
{
    vector<int> weights;
    weights.push_back(95);
    weights.push_back(4);
    weights.push_back(60);
    weights.push_back(32);
    weights.push_back(23);
    weights.push_back(72);
    weights.push_back(80);
    weights.push_back(62);
    weights.push_back(65);
    weights.push_back(46);

    vector<int> values;
    values.push_back(55);
    values.push_back(10);
    values.push_back(47);
    values.push_back(5);
    values.push_back(4);
    values.push_back(50);
    values.push_back(8);
    values.push_back(61);
    values.push_back(85);
    values.push_back(87);

    int n = 10;
    int capacity = 269;

    vector<vector<int> > dp(n, vector<int>(capacity, -1));

    cout << "Max Profit " << knapsack(0, 0, weights, values, n, capacity, dp) << endl;
    return 0;
}