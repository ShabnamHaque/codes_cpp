#include <bits/stdc++.h>
using namespace std;

    //  quicksort algo

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        
          if(i<j)  swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pindex = partition(arr, low, high);
        qs(arr, low, pindex - 1);
        qs(arr, pindex + 1, high);
    }
}
vector<int> quicksort(vector<int>arr){
    int n=arr.size();
    qs(arr,0,n-1);
    return arr;
}
int main()
{
    vector<int> arr{2, 3, 4, -1, 0};
    
    arr=quicksort(arr);

    for (int i = 0; i < 5; i++)
     {   cout << arr[i] << "/";  }

    cout<<endl;
    return 0;
}
