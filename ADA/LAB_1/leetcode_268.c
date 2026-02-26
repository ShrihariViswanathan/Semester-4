int missingNumber(int* nums, int numsSize) {
    int c = numsSize;
    int total = (c*(c + 1)) / 2;
    for (int i = 0; i < numsSize; i++)
        total -= nums[i]; 
    return total;
}
