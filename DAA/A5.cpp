#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // Pivot element
    int i = low;
    int j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot && i < high);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high); // Get the partition index
        QuickSort(arr, low, p);            // Recursively sort elements before partition
        QuickSort(arr, p + 1, high);       // Recursively sort elements after partition
    }
}

void QuickSortR(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int random = low + rand() % (high - low);
        swap(arr[random], arr[low]);
        int p = partition(arr, low, high);
        QuickSortR(arr, low, p);
        QuickSortR(arr, p + 1, high);
    }
}

int main()
{
    vector<int> x = {10, 12, 15, 20, 1, 4, 17, 16, 11};
    int low = 0;
    int high = x.size(); // No sentinel value is needed here

    // Regular QuickSort
    QuickSort(x, low, high);
    for (auto i : x)
        cout << i << " ";
    cout << endl;

    x = {10, 12, 15, 20, 1, 4, 17, 16, 11};
    QuickSortR(x, low, high);
    for (auto i : x)
        cout << i << " ";
    cout << endl;

    return 0;
}
