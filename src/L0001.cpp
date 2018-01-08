/*
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include<tr1/unordered_map>
#include <vector>

using namespace std;
using namespace tr1;

class IllegalArgumentException {
};

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        vector<int> re;
        for (int i = 0; i < nums.size(); ++i) {
            if (!map.count(nums[i])) {
                map[nums[i]] = i;
            }
            int a = target - nums[i];
            if (map.count(a) && map[a] != i) {
                re.push_back(i);
                re.push_back(map[a]);
                return re;
            }
        }
        throw IllegalArgumentException();
    }
};
