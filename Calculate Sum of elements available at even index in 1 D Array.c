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
        if(i%2!=0)
        	{
        		k+=arr[i];
        	}
    }
    cout<<k;
    return 0;
}