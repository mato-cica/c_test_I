#include <stdio.h>
#include <stdlib.h>
//#include "/home/mato_ubuntu/vcpkg/installed/x64-linux/include/cjson/cJSON.h"

int B[100000];

/*
 *  -Function extractes postive numbers from array A in array B. Array B may
 *       have 100,000 integers because of the range of N.
 *  -Arguments: array of integers A, and the range N of array
 *  -No returned value.
 */
void exstractPositiveNumbers(int A[], int N)
{
    int j = 0;
    for(int i = 0; i < N; i++)
    {
        if(A[i] > 0)
        {
           B[j + 1] = A[i];
           j++;
        }
    }
    /* First element is used for information about range of array B.
       There is no need to retrieve 100,000 elements if the range is N. */
    B[0] = j;
}

/*
 *  -Function findes the smallest number of array of positive numbers B
 *  -Arguments: array of integers A, and the range N of array
 *  -Returned value: smallest number of array of positive numbers B
 */
int findSmallestNumberOfAnArray(int A[], int N)
{
    exstractPositiveNumbers(A, N);
    int smallestNumberOfAnArray = 0;

    /* No members of array B means all members of array A are nonpositive*/
    if(B[0] == 0)
    {
        printf("All array members are nonpositive.\nsolution = 1\n");
        exit(0);
    }
    else
    {
        smallestNumberOfAnArray = B[1];
        for(int i = 1; i < B[0] + 1; i++)
            if (B[i] < smallestNumberOfAnArray)
                smallestNumberOfAnArray = B[i];
    }
    return smallestNumberOfAnArray;
}

/*
 *  -Function findes the smallest number of array of positive numbers B that
 *       does not ocuur in array
 *  -Arguments: array of integers A, and the range N of array
 *  -Returned value: smallest number of array of positive numbers B hat
 *       does not ocuur in array
 */
int findSmallestMissingNumber(int A[], int N)
{
    int smallestMissingNumber = 0, i = 0, j = 0, exit = 0;
    int smallestNumberOfAnArray = findSmallestNumberOfAnArray(A, N);
    if(smallestNumberOfAnArray > 1)
    /*If the smallest number of B is greather then 1 then the solution is 1*/
        return 1;
    else
    {
        for(j = 0; j < N; j++)
        {
            for(i = 0; i < N; i++)
            {
                if(A[i] == smallestNumberOfAnArray + j + 1)
                    break;
                else
                    if((i == N - 1) && (A[i] != smallestNumberOfAnArray + j +1))
                    {
                        smallestMissingNumber = smallestNumberOfAnArray + j + 1;
                        exit = 1;
                    }
                if(exit == 1)
                    break;
                //smallestMissingNumber = smallestNumberOfAnArray + j + 1;
            }
        }
    }
    return smallestMissingNumber;
}

/*
   -Required function
   -Returned value is required solution.
*/
int solution(int A[], int N)
{
    return findSmallestMissingNumber(A, N);
}


int main()
{

    int A[7] = {8, 2, 3, 4, 1, 6, 5};
    printf("solution = %d\n", solution(A, 7));
    return 0;
}
/* Write a function:
                      int solution(int A[], int N)
   that, given an array A of N integers, returns the smallest positive integer that does not occur in A.
   For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5,
                given A = [1, 2, 3], the function should return 4,
                given A = [-2, -3], the function should return 1.
   Write an efficient algorithm for the following assumptions:

           - N is an integer within the range [1...100,000]
           - each element of an array A is an integer within the range [-1,000,000...1,000,000]
*/
