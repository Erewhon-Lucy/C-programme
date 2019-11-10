#include<stdio.h>

int main()
{
    #define N 10
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int low = 0, high = N - 1, mid;
    int key;

    scanf("%d", &key);

    while (low <= high)
    {
        mid = ((low + high)/2);
        if (a[mid] == key)
        {
            printf("%d\n", mid);
            break;/* find */
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (low > high) printf("Not found\n"); 
    
    return 0;
}