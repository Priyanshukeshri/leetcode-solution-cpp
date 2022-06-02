#include <bits/stdc++.h>
using namespace std;
bool isPrime(int number){
     if (number < 2) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i=3; (i*i) <= number; i+=2) {
        if (number % i == 0 ) return false;
    }
    return true;
}
int maxDifference(int startVal, int endVal) {
    int min=0,max=0,diff=0;
    int i,j,r=startVal,s=endVal;
    for(i=r;i<=s;i++)
        if(isPrime(i)){
            min=i;
            break;
        }
        for(i=s;i>=r;i--)
        {if(isPrime(i))
            if(i>max){max=i;break;
        }}
    if(min ==0 && max==0)
        return -1;
    diff=max-min;
    return diff;
    
    
}

int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int startVal;
        int endVal;
        cin >> startVal >> endVal;
        int result = maxDifference(startVal, endVal);
        cout << result << endl;
    }
    return 0;
}