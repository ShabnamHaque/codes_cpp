#include <bits/stdc++.h>
using namespace std;
// bool f=1;

int noofsubseqofsumk(int index, int n, int arr[], int reqsum, int s)
{
    if (s > reqsum) //if arr contains only positives .
        return 0;
    if (index == n)
    {
        if (s == reqsum)
        {
            return 1;
        }
        else  return 0;
    }
     // v.push_back(arr[index]);
    s += arr[index];

    int l = noofsubseqofsumk(index + 1, n, arr, reqsum, s); // to take into the subsequence.

    s -= arr[index];
    //  v.pop_back();

    int r = noofsubseqofsumk(index + 1, n, arr, reqsum, s); // to not take into the subsequence

    return r + l;
}

void subseqofsumk(int index, int n, int arr[], vector<int> v, int reqsum, int s)
{
    if (index == n)
    {
        if (s == reqsum)
        {
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << " | ";
        }
        if(reqsum==0){
            cout<<"{}"<<endl;
        }
        return;
    }
    v.push_back(arr[index]);
    s += arr[index];

    subseqofsumk(index + 1, n, arr, v, reqsum, s); // to take into the subsequence.

    s -= arr[index];
    v.pop_back();

    subseqofsumk(index + 1, n, arr, v, reqsum, s); // to not take into the subsequence
}

bool onesubseqofsumk(int index, int n, int arr[], vector<int> v, int reqsum, int s)
{
    if (index == n)
    {   // condition satisfied
        if (s == reqsum)
        {
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << " | ";
            return true;
        }
        else
            return false;
    }

    v.push_back(arr[index]);
    s += arr[index];

    if (onesubseqofsumk(index + 1, n, arr, v, reqsum, s) == true)
        {return true;}
    // to take into the subsequence.

    s -= arr[index];
    v.pop_back();

    if (onesubseqofsumk(index + 1, n, arr, v, reqsum, s) == true)
       { return true; }
         // to not take into the subsequence

    return false;
}

void subseq(int index, int n, int arr[], vector<int> v)
{
    if (index == n)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        
        cout << " | ";
        return;
    }

    v.push_back(arr[index]);
    subseq(index + 1, n, arr, v); // to take into the subsequence.

    v.pop_back();
    subseq(index + 1, n, arr, v); // to not take into the subsequence
}

int main()
{
    // print all subsequences

    int arr[] = {2, 3,0,4,-1};
    vector<int> v;
    int size = sizeof(arr) / sizeof(arr[0]);

    subseq(0, size, arr, v);//to print all subsequences.

    cout << endl;
    
    cout << "Subseq of sum = 3 :" << endl;

    subseqofsumk(0, size, arr, v, 3, 0);

    cout << endl
         << "only one Subseq of sum = 3 :" << endl;
    if (onesubseqofsumk(0, size, arr, v, 3, 0))
        cout << "\nYes it contains some subseq of sum 3.\n";
    else
        cout << "\nNo it doesnot contain a subseq of sum 3.\n";

if (onesubseqofsumk(0, size, arr, v, 903, 0))
        cout << "\nYes it contains some subseq of sum 903.\n";
    else
        cout << "\nNo it doesnot contain a subseq of sum 903.\n";

    cout << "Number of such subsequences is: " << noofsubseqofsumk(0, size, arr, 4, 0);
    return 0;
}

