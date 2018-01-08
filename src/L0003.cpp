/*
3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        int left = 0;
        int right = 0;
        int re = 0;
        while (right < s.length()) {
            if (set.find(s[right]) == set.end()) {
                set.insert(s[right]);
                right++;
                re = max(re, right - left);
            } else {
                set.erase(s[left]);
                left++;
            }
        }
        return re;
    }
};
