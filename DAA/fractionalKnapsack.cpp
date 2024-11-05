#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    double weight;
    double value;

    Item(double w, double v) : weight(w), value(v) {}
};

bool compare(Item a, Item b)
{
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(double capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto &item : items)
    {
        if (item.weight <= capacity)
        {
            totalValue += item.value;
            capacity -= item.weight;
        }
        else
        {
            totalValue += item.value * (capacity / item.weight);
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n;
    double capacity;

    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items;

    for (int i = 0; i < n; i++)
    {
        double weight, value;
        cout << "Enter weight and value of item " << i + 1 << ": ";
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}

// - Time Complexity: (O(nlog n)), where ( n) is the number of items. This is due to the sorting operation.
// - Space Complexity: (O(1)) additional space, as we are sorting the items in place and only using a few extra variables.