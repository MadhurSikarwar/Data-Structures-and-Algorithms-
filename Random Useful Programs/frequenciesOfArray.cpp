#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    //below is a function which returns a 2D vector for the mapped outcomes of the hashed table
    //takes input of the array address so that no copy is sent to the function 
    vector<vector<int>> countFrequencies(vector<int> &nums)
    {
        unordered_map<int, int> freq; // to store element -> frequency

        // Count frequencies
        //nums -> name of the vector 
        //iterator num in the vector nums
        //here num is vector[i] which is stored in the map named freq
        for (int num : nums)
        {
            freq[num]++;
        }
        // Build the result
        //here making a 2D vector array to return it from the class Solution
        vector<vector<int>> result;
        for (auto it : freq)
        {
            //pushed two elements in the vector it.first and it.second
            //here it again is the iterator in the map 
            result.push_back({it.first, it.second});
        }

        return result;
    }
};

int main() {
    Solution sol; //creating an object of the class Solution 
    vector<int> nums = {1,2,2,1,3}; //static vector created 
    vector<vector<int>> ans = sol.countFrequencies(nums); //returning the mapped frequencies using the double vector here
    for (auto v : ans) {
        cout << "[" << v[0] << ", " << v[1] << "] ";
    }
}

