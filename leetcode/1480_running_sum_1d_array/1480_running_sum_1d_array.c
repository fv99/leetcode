/* 
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]

Constraints:
    1 <= nums.length <= 1000
    -10^6 <= nums[i] <= 10^6

 */

#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	int	*arr;
	int	i = 1;

	arr = malloc(sizeof(int) * numsSize);
	arr[0] = nums[0];
	while (i < numsSize)
	{
		arr[i] = nums[i] + arr[i - 1];
		i++;
	}
	return(arr);
}

int main() {
    int nums1[] = {1,2,3,4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    int* result1 = runningSum(nums1, size1, &returnSize1);
    printf("Running sum of array 1: ");
    for(int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1);

    int nums2[] = {1,1,1,1,1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    int* result2 = runningSum(nums2, size2, &returnSize2);
    printf("Running sum of array 2: ");
    for(int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2);

    int nums3[] = {3,1,2,10,1};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int returnSize3;
    int* result3 = runningSum(nums3, size3, &returnSize3);
    printf("Running sum of array 3: ");
    for(int i = 0; i < returnSize3; i++) {
        printf("%d ", result3[i]);
    }
    printf("\n");
    free(result3);

    return 0;
}
