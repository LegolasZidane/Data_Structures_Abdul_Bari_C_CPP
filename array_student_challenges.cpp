#include <iostream>
using namespace std;

struct Array
{
    int A[5];
    int size;
    int length;
};

void multipleMissingElementsSorted(struct Array arr)
{

    int i , j, k;
    printf("\n Missing element/s are \n");
    for( i = 0; i<arr.length - 1; i++)
    {
        k = arr.A[i+1] - arr.A[i];
        if( k != 1)
        {
            for( j = 1; j<k; j++)
                printf("%d ", arr.A[i] + j);
        }
    }

}

void multipleMissingElementsUnsorted(struct Array arr)
{

    int min = arr.A[0], max = arr.A[0], i;

    for(i = 1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
        else if(arr.A[i] < min)
            min = arr.A[i];
    }

    int length = max + 1 - min;
    
    int *H = (int *)malloc(length*sizeof(int)); // Has garbage values.

    for(i = 0; i<length; i++)
        H[i] = 0;

    for(i = 0; i<arr.length; i++)
        H[arr.A[i] - min]++;
    
    printf("\n Missing element/s are \n");

    for(i = 0; i<length; i++)
    {
        if(H[i]==0)
            printf("%d ",(i + min));
    }

}

void findingDuplicatesSorted(struct Array arr)
{

    int last_duplicate = 0, i;
    
    printf("\nDuplicates are \n");
    for( i = 0; i<arr.length - 1; i++)
    {
        if(arr.A[i] == arr.A[i+1] && last_duplicate != arr.A[i])
        {
            printf("%d ", arr.A[i]);
            last_duplicate = arr.A[i];
        }
    }

}

void countingDuplicatesUnsorted(struct Array arr)
{

    int min = arr.A[0], max = arr.A[0], i;

    for(i = 1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
        else if(arr.A[i] < min)
            min = arr.A[i];
    }

    int length = max + 1 - min;
    
    int *H = (int *)malloc(length*sizeof(int)); // Has garbage values.

    for(i = 0; i<length; i++)
        H[i] = 0;

    for(i = 0; i<arr.length; i++)
        H[arr.A[i] - min]++;
    
    printf("\n Duplicate element/s are \n");

    for(i = 0; i<length; i++)
    {
        if(H[i] > 1)
            printf("%d times %d\n", H[i],(i + min));
    }

}

void countingDuplicatesSorted(struct Array arr)
{

    int i , j;

    printf("\n Duplicate element/s are \n");

    for( i = 0; i<arr.length - 1; i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            j = i+1;
            while(arr.A[j] == arr.A[i])
                j++;
            printf("%d times %d\n", arr.A[i], j-i);
        }
    }    

}

void findSumPairUnsorted(struct Array arr, int sum)
{

    int min = arr.A[0], max = arr.A[0], i;

    for(i = 1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
        else if(arr.A[i] < min)
            min = arr.A[i];
    }

    int length = max + 1 - min;
    
    int *H = (int *)malloc(length*sizeof(int)); // Has garbage values.

    for(i = 0; i<length; i++)
        H[i] = 0;

    printf("\nPairs with sum %d are \n", sum);
    for(i = 0; i<arr.length; i++)
    {

        if(H[sum - arr.A[i] - min] == 1)
            printf("%d, %d\n", arr.A[i], sum - arr.A[i]);
        H[arr.A[i]-min]++;

    }

}

void findSumPairSorted(struct Array arr, int sum)
{

    int i = 0, j = arr.length - 1;

    printf("\nPairs with sum %d are \n", sum);
    while(i<j)
    {
        if(arr.A[i] + arr.A[j] == sum)
        {
            printf("%d, %d\n", arr.A[i], arr.A[j]);
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j] < sum)
            i++;
        else
            j--;
    }

}

void display(struct Array arr)
{
    int i;
    for( i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int main()
{
    struct Array a = {{1,2,3,4,6}, 10, 5};
    findSumPairSorted(a, 5);

    return 0;
}