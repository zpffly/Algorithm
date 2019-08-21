#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;


void permutation(vector<int>& nums, int m)
{
    if ( m == 0)
    {
        for(auto num : nums)
            cout << num << " ";
        cout<<endl;
    }
    else{
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = m;
                permutation(nums, m - 1);
                nums[i] = 0;
            }
        }
    }
}

void permutation(int m)
{
    vector<int> nums(m, 0);
    permutation(nums, nums.size());
}


void permutation2(vector<int>& nums, int m)
{
    if ( m == 0)
    {
        for(auto num : nums)
            cout << num << " ";
        cout<<endl;
    }
    else{
        for (int i = nums.size()-1; i >= 0; --i)
        {
            if(nums[i] == 0)
            {
                nums[i] = m;
                permutation2(nums, m - 1);
                nums[i] = 0;
            }
        }
    }
}

void permutation2(int m)
{
    vector<int> nums(m, 0);
    permutation2(nums, nums.size());
}

int main() {
    permutation(3);
    cout << "-----------------" << endl;
    permutation2(3);
    return 0;
}