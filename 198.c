// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400

//Solution : Dynamic Programming
int rob(int* nums, int numsSize) {
    if(numsSize==1)
        return nums[0];
    if(numsSize==2)
        return fmax(nums[0],nums[1]);
    int *track=(int*)malloc(sizeof(int)*numsSize);
    track[0]=nums[0];
    track[1]=nums[1];
    
    for(int i=2;i<numsSize;i++)
    {
        int max=0;
        for(int j=0;j<i-1;j++)
        {
            if(track[j]>max)
                max=track[j];
        }
        track[i]=fmax(track[i-2],nums[i]+max);
    }

    return fmax(track[numsSize-1],track[numsSize-2]) ;
}