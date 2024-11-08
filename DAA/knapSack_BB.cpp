#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int profit;
    Item(int w, int p) : weight(w), profit(p) {}
};

struct Node
{
    int level;
    int profit;
    int weight;
    int bound;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

int bound(Node u, int n, int W, vector<Item> &items)
{
    if (u.weight >= W)
        return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;

    while (j < n && total_weight + items[j].weight <= W)
    {
        total_weight += items[j].weight;
        profit_bound += items[j].profit;
        j++;
    }

    return profit_bound;
}

int knapsack(int W, vector<Item> &items)
{
    int n = items.size();
    sort(items.begin(), items.end(), cmp);

    queue<Node> Q;
    Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    u.bound = bound(u, n, W, items);
    Q.push(u);

    int maxProfit = 0;

    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        if (u.level == -1)
            v.level = 0;

        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;

        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].profit;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, items);

        if (v.bound > maxProfit)
            Q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, items);

        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

int main()
{
    int W = 50;
    vector<Item> items;
    Item item1(40, 200);
    Item item2(10, 50);
    Item item3(12, 120);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);

    cout << "Maximum profit: " << knapsack(W, items) << endl;
    return 0;
}
