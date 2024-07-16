#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDifference(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0; // Return 0 if array is empty
    }

    int minVal = nums[0];
    int maxDiff = 0;

    for (int i = 1; i < nums.size(); ++i)
    {
        maxDiff = max(maxDiff, nums[i] - minVal);
        minVal = min(minVal, nums[i]);
    }

    return maxDiff;
}

int main()
{
    vector<int> nums = {4, 10, 15, 9, 2, 5};

    int result = maxDifference(nums);
    cout << "Maximum difference between any two elements: " << result << endl;

}
