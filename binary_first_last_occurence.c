#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int x;
    scanf("%d",&x);
    int low = 0, high = n - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (x == arr[mid])
        {
            result = mid;
            high = mid - 1;
        }
        else if (x < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if (result != -1)
    {
        printf("The first occurrence of element %d is located at index %d",x, result+1);
    }
    else {
        printf("Element not found in the array");
    }
    return 0;
}