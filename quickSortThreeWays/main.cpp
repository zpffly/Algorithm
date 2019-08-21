#include <iostream>
#include <vector>
#include <random>
#include <windows.h>
using std::vector;
using std::cout;

void quickSortThreeWays(vector<int>& nums, int left, int right)
{
    if ( left >= right )
        return;
    int lt = left;
    int curIndex = left + 1;
    int gt = right + 1;
    int condition = nums[left];

    while (curIndex < gt)
    {
        if ( nums[curIndex] == condition )
            ++ curIndex;
        else if ( nums[curIndex] < condition )
            std::swap(nums[curIndex++], nums[++lt]);
        else
            std::swap(nums[curIndex], nums[--gt]);
    }
    std::swap(nums[left], nums[lt]);
    quickSortThreeWays(nums, left, lt - 1);
    quickSortThreeWays(nums, gt, right);
}

void quickSort(vector<int>& nums, int left, int right)
{
    if (left >= right)
        return;
    int l = left;
    int r = right;
    //int mid = (left + right) / 2;
    int pivot = nums[left];

    while (l < r)
    {
        while (l < r && nums[r] >= pivot) --r;
        nums[l] = nums[r];
        while (l < r && nums[l] <= pivot) ++l;
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    quickSort(nums, left, l-1);
    quickSort(nums, l+1, right);
}


int main() {

    vector<int> nums = {3,5,6,7,4,4,9078,67,7,854,2344};
    std::uniform_int_distribution<unsigned> u(0,500);
    std::default_random_engine e;
    for (int i = 0; i < 1000000; ++i) {
        nums.push_back(u(e));
    }
    vector<int> nums1(nums.begin(), nums.end());
    DWORD start_time = GetTickCount();
    quickSortThreeWays(nums1, 0, nums1.size()-1);
    DWORD end_time = GetTickCount();
    cout << "three ways :" << (end_time - start_time) << "ms" <<std::endl;


    start_time = GetTickCount();
    quickSort(nums, 0, nums.size()-1);
    end_time = GetTickCount();
    cout << "quick sort :" << (end_time - start_time) << "ms" <<std::endl;
//    for(int i = 0; i < nums.size()-1; i++)
//        if(nums[i] > nums[i+1])
//        {
//            cout << "error" << std::endl;
//            break;
//        }

    return 0;
}