#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int arr[10], n, i,j,k,t;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the elements of the array : ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cin>>k;
    for(j=1;j<=k;j++)
    {
    	t=arr[0];
    	for(i=0;i<n-1;i++)
    	{
    		arr[i]=arr[i+1];
    	}
    	arr[i]=t;
    }
    for (i = 0; i < n; i++)
        cout<< arr[i]<<"\t";
    return 0;
}