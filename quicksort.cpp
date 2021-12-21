#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high + 1;

    while (i < j)
    {
        // increment i till when we don't find a greater element then pivot
        do
        {
            i++;
        } while (arr[i] <= pivot);
        // Decrement j till when we don't get a smaller element then pivot;
        do
        {
            j--;
        } while (arr[j] > pivot);

        // swap element at index i and j if and only if i<j
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    clock_t st, et, total_time;
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        // cin>>arr[i];
        arr[i] = rand();
    }

    st = clock();
    quickSort(arr, 0, n - 1);
    et = clock();
    // cout<<CLOCKS_PER_SEC<<endl;
    // cout<<et-st<<endl;
    cout << (float)(et - st) / CLOCKS_PER_SEC << endl;
    // total_time=(float)(et-st)/CLOCKS_PER_SEC;
    // cout<<total_time;
    // for(int i = 0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }

    return 0;
}
