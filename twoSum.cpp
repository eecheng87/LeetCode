/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    int i, j, a, b;
    int *ans = (int *)malloc(sizeof(int *) * 2);
    for (i = 0; i < numsSize - 1; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (target == nums[i] + nums[j])
            {
                ans[0] = i;
                ans[1] = j;
            }
        }
    }
    return ans;
}