/*
159.Longest Substring with At Most Two Distinct Characters
Given a string S, find the length of the longest substring T that contains at most two distinct characters.
For example,
Given S = “eceba”,
T is “ece” which its length is 3.
 */
#include <string>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0;
        int right = 0;
        int re = 0;
        unordered_map<char, int> map;
        while (right < s.length()) {
            if (map.count(s[right])) {
                right++;
                re = max(re, right - left);
            } else {
                if (map.size() < 2) {
                    map[s[right]] = 1;
                    right++;
                    re = max(re, right - left);
                } else {
                    int a = map[s[left]];
                    if (a == 1) {
                        map.erase(s[left]);
                    } else {
                        map[s[left]] = a - 1;
                    }
                    left++;
                }
            }
        }
        return re;
    }
};