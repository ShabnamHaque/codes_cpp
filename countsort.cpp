
#include <bits/stdc++.h>
using namespace std;


//tc=o(n) sc=o(n)

void countsort(vector<int> &a, int n)
{
  int m = *max_element(a.begin(),a.end());
  //m+1 is the length of the count array
  int count[m+1] = {0};
  for (int i = 0; i < n ; i++)
  {
    count[a[i]]++;
  }
  for (int i = 1; i <= m; i++)
  {
    count[i] += count[i - 1];
  }

  int tmp[n];
  for (int i = n-1; i > -1; i--)
  {
    tmp[--count[a[i]]] = a[i];
  }

  for (int i = n - 1; i > -1; i--)
  {
    a[i] = tmp[i];
  }
}

int main()
{

  vector<int> arr{3, 8, 1, 1, 0};

  countsort(arr, 5);

  for (int i = 0; i < 5; i++)
    cout << arr[i] << " ";
  return 0;
}
