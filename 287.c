// turn this problem to the problem "142. Linked List Cycle II"
// Given a linked list with a circle, return the node where the cycle begins.

int findDuplicate(int* nums, int numsSize)
{
    int slow = 0, fast = 0;
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
