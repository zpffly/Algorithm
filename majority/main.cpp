#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int majorityElement(vector<int>& nums) {
    int count = 1, i;
    int size = nums.size();
    int condidation = nums[0];
    for (i = 1; i < size; ++i)
    {
        if (nums[i] == condidation)
            ++ count;
        else if (count == 1)
            condidation = nums[i];
        else
            -- count;
    }

    count = 0;
    for (i = 0; i < size; i++)
    {
        if(nums[i] == condidation)
            ++ count;
    }

    return count > size / 2 ? condidation : -1;
}

int main() {

    vector<int> nums = {2,2,1,1,1,2,2,1,1,1,1,3,4,5,5,7};
    cout << majorityElement(nums);
    return 0;
}