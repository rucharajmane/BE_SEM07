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
        // Move `i` to the right until we find an element greater than the pivot
        do
        {
            i++;
        } while (arr[i] <= pivot && i < high);

        // Move `j` to the left until we find an element less than or equal to the pivot
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]); // Swap elements to ensure they are on the correct side of the pivot
    }

    swap(arr[low], arr[j]); // Place the pivot in its correct position
    return j;               // Return the partition point
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
        // Choose a random pivot and swap with the first element
        int random = low + rand() % (high - low);
        swap(arr[random], arr[low]);
        int p = partition(arr, low, high); // Get the partition index
        QuickSortR(arr, low, p);           // Recursively sort elements before partition
        QuickSortR(arr, p + 1, high);      // Recursively sort elements after partition
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
