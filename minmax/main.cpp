#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using std::max;
using std::min;
using std::vector;

/**
 *
 * @param mm 存储最大最小值，初始化容量为2, mm[0] 为最大值， mm[1] 为最小值
 * @param nums 输出数组
 * @param left 左边界
 * @param right 右边界
 */
void minmax(vector<int>& mm, vector<int>& nums, int left, int right)
{
    if (left == right)
    {
        if (nums[left] > mm[0])
            mm[0] = nums[left];
        if (nums[left] < mm[1])
            mm[1] = nums[left];
        return;
    }

    int mid = (left + right) / 2;
    minmax(mm, nums, left, mid);
    minmax(mm, nums, mid+1, right);
}


void minmax2(vector<int>& mm, vector<int>& nums, int left, int right)
{
    if (left == right)
        mm[0] = mm[1] = nums[left];
    else if (left + 1 == right)
    {
        if (nums[left] > nums[right])
        {
            mm[0] = nums[left];
            mm[1] = nums[right];
        }else{
            mm[0] = nums[right];
            mm[1] = nums[left];
        }
    }
    else
    {
        int mid = (left + right) / 2;
        minmax2(mm, nums, left, mid);
        minmax2(mm, nums, mid+1, right);
    }
}


void maxmin(int i,int j,int A[],int& fmax,int& fmin){
    //int i=0;
    //int j=n-1;
    int max1,max2,min1,min2;
    int mid=(i+j)/2;
    if(i==j) {fmax=A[i];fmin=A[i];}
    else if(i==j-1){
        if(A[i]<=A[j]){fmin=A[i];fmax=A[j]; }
        else {fmin=A[i];fmax=A[j];}
    }
    else {
        maxmin(mid+1,j,A,max1,min1);
        maxmin(i,mid,A,max2,min2);
        fmax=max(max1,max2);
        fmin=min(min1,min2);
    }


}



int main() {

    vector<int> mm = {INT_MIN, INT_MAX};
    vector<int> mm1(2);
    vector<int> nums = {2,5,2,4};
    minmax2(mm1, nums, 0, nums.size()-1);
    std::cout << "max: " << mm1[0] << std::endl;
    std::cout << "min: " << mm1[1] << std::endl;
    int A[]={2,5,2,4};
    int max,min;
    maxmin(0,4,A,max,min);
    std::cout<<max<<" "<<min<<std::endl;
    return 0;
}