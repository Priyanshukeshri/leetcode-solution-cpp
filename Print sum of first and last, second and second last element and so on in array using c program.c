#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int arr[10], n, i,j=0,k=0,t;
    cout << "Enter the size of the array : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (i = 0,j=n-1; i < j; i++,j--)
    {
    	cout<<arr[i]+arr[j];
    	cout<<" ";
    }
    return 0;
}