#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;

int getMaxLength(vector<int>& arr)
{
    int max = arr[0];
    for(auto it = arr.begin()+1; it != arr.end(); it++)
    {
        if(max < *it)
            max = *it;
    }

    int exp = 0;
    while (max)
    {
        exp++;
        max /= 10;
    }
    return exp;
}

void sortByExp(vector<int>& arr, int exp)
{
    vector<int> res(arr.size());
    int buckets[10] = {0};
    int i;
    int size = arr.size();
    for(i = 0; i < size; i++)
    {
        buckets[(arr[i] / exp) % 10]++;
    }

    for(i = 1; i < 10; i++)
    {
        buckets[i] += buckets[i-1];
    }

    for(i = size-1; i >= 0; i--)
    {
        res[buckets[(arr[i] / exp) % 10] - 1] = arr[i];
        --buckets[(arr[i] / exp) % 10];
    }
    for(i = 0; i < size; i++)
    {
        arr[i] = res[i];
    }
}

void radixSort(vector<int>& arr)
{
    int size = arr.size();
    int maxRadix = getMaxLength(arr); //最大位数长度
    int radix = 1;
    vector<int> buckets(10,0); //桶的计数器
    vector<int> temp((unsigned) size);
    int i,j,k;
    //分别对每一位进行排序
    for(i = 0; i < maxRadix; i++)
    {
        //每次循环将桶清空
        buckets.assign(10, 0);

        for(j = 0; j < size; j++)
        {
            //得到不同位数上的数字
            k = (arr[j] / radix) % 10;
            ++buckets[k];
        }

        for(j = 1; j < 10; j++)
            buckets[j] += buckets[j-1];

        for(j = size-1; j >= 0; j--)
        {
            k = (arr[j] / radix) % 10;
            temp[buckets[k] - 1] = arr[j];
            --buckets[k];
        }
        for(j = 0; j < size; j++)
            arr[j] = temp[j];
        radix *= 10;
    }
}


int main() {
    vector<int> vector1 = {1,4,4,17,45,36,68,30,84,42424,5,5,2,6,43,4,3};
    radixSort(vector1);
    for (auto it = vector1.begin(); it != vector1.end(); it++)
        std::cout << *it << " ";
    return 0;
}