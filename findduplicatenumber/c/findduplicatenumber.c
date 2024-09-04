int findDuplicate(int* nums, int numsSize) {
    int slow = 0, fast = 0;   
    while(slow != fast || (slow == 0 && fast == 0)){
        slow = nums[slow];
        fast = nums[nums[fast]];
        printf("Value od slow is &d and %d\n", slow, fast);
    }
    slow = 0;
    while(slow != fast) {
        slow  = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

