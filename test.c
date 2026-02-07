/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

// Helper function: Print test results
void printResult(int* nums, int numsSize, int target, int* result, int returnSize) {
    printf("Input array: [");
    for (int i = 0; i < numsSize; i++) {
        printf("%d%s", nums[i], i < numsSize - 1 ? ", " : "");
    }
    printf("], Target: %d\n", target);
    
    if (returnSize == 2) {
        printf("Result: [%d, %d] (Corresponding values: %d + %d = %d)\n", 
               result[0], result[1], 
               nums[result[0]], nums[result[1]], 
               nums[result[0]] + nums[result[1]]);
    } else {
        printf("Result: Not found\n");
    }
    printf("------------------------\n");
}

int main() {
    int returnSize;
    int* result;
    
    // Test case 1: Basic scenario
    int nums1[] = {2, 7, 11, 15};
    result = twoSum(nums1, 4, 9, &returnSize);
    printResult(nums1, 4, 9, result, returnSize);
    if (result) free(result);
    
    // Test case 2: Multiple possible solutions (return the first one found)
    int nums2[] = {3, 2, 4, 3};
    result = twoSum(nums2, 4, 6, &returnSize);
    printResult(nums2, 4, 6, result, returnSize);
    if (result) free(result);
    
    // Test case 3: Negative numbers
    int nums3[] = {-1, -2, -3, -4, -5};
    result = twoSum(nums3, 5, -8, &returnSize);
    printResult(nums3, 5, -8, result, returnSize);
    if (result) free(result);
    
    // Test case 4: Contains zero
    int nums4[] = {0, 4, 3, 0};
    result = twoSum(nums4, 4, 0, &returnSize);
    printResult(nums4, 4, 0, result, returnSize);
    if (result) free(result);
    
    // Test case 5: No solution case
    int nums5[] = {1, 2, 3, 4};
    result = twoSum(nums5, 4, 10, &returnSize);
    printResult(nums5, 4, 10, result, returnSize);
    if (result) free(result);
    
    // Test case 6: Two elements
    int nums6[] = {1, 1};
    result = twoSum(nums6, 2, 2, &returnSize);
    printResult(nums6, 2, 2, result, returnSize);
    if (result) free(result);
    
    return 0;
}