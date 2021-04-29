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
           B[A[i]] = A[i];
           j++;
        }
    }
    /* First element is used for information about range of array B.
       If B[0] = 0 there is no positive numbers.*/
    B[0] = j;
}

/*
 *  -Function findes the smallest number of array of positive numbers B
 *  -Arguments: array of integers A, and the range N of array
 *  -Returned value: smallest number of array of positive numbers B
 */
int findSmallestMissingNumber(int A[], int N)
{
    exstractPositiveNumbers(A, N);
    int i = 0;

    /* No members of array B means all members of array A are nonpositive*/
    if(B[0] == 0)
    {
        printf("All array members are nonpositive.\nsolution = 1\n");
        exit(0);
    }
    else
    {
        for(int i = 1; i < N + 2; i++)
            if (B[i] != i)
                return i;
    }
}

/*
 *  -Required function
 *  -Arguments: array of integers A, and the range N of array
 *  -Returned value is required solution.
*/
int solution(int A[], int N)
{
    return findSmallestMissingNumber(A, N);
}


int main()
{

    int A[7] = {7, 2, 3, 3, 1, -6, -5};
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
