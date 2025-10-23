#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int mostFrequentElement(vector<int> &nums)
    {
        map<int, int> freq; // element -> frequency

        // Step 1: Count frequencies
        for (int num : nums)
        {
            freq[num]++;
        }

        // Step 2: Find max frequency element
        int maxFreq = 0;
        int ans = -1;

        for (auto it : freq)
        {
            int element = it.first;
            int count = it.second;

            if (count > maxFreq)
            {
                maxFreq = count;
                ans = element;
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.mostFrequentElement(nums);

    cout << "Most frequent element is: " << result << endl;
    return 0;
}
