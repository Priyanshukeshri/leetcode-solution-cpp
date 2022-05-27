#include <bits/stdc++.h> 
using namespace std; 
int main()
{
    int a,b,n,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        for (int i=0;i<=n;i++) 
        { 
    		if ((n -(i*a))%b==0) 
    		{ 
    			cout <<"Yes\n";
    			break;
    		} 
    		cout << "No\n"; break;
    	} 
    } 
    return 0;
}