// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.

int removeDuplicates(int* nums, int numsSize) {
    void remove(int *arr,int *arr_size,int index)
    {
        for(int i=index;i<(*arr_size)-1;i++)
        {
            arr[i]=arr[i+1];
        }
        *arr_size=*arr_size-1;
    }
    for(int i=0;i<numsSize-1;i++)
    {
        if(nums[i]==nums[i+1])
        {
            remove(nums,&numsSize,i+1);
            i--;
        }
    }
    return numsSize;
}