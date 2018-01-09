/*
28. Implement strStr()
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
 */
#include <string>

using namespace std;

class Solution {
public:
    bool fmin(int a, int b) {
        bool c = a < b;
        return c;
    }

    int strStr(string haystack, string needle) {
        if (haystack == needle || needle.length() == 0) {
            return 0;
        }
        if (haystack.length() == 0 || haystack.length() < needle.length()) {
            return -1;
        }
        int i = 0;
        int j = 0;
        int *next = getNext(needle);
        while (i < haystack.length() && fmin(j, needle.length())) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == needle.length()) {
            return i - needle.length();
        } else {
            return -1;
        }
    }

    int *getNext(string s) {
        int j = 0;
        int k = -1;
        int *next = new int[s.length()];
        next[0] = -1;
        while (j < s.length() - 1) {
            if (k == -1 || s[j] == s[k]) {
                k++;
                j++;
                if (s[j] != s[k]) {
                    next[j] = k;
                } else {
                    next[j] = next[k];
                }
            } else {
                k = next[k];
            }
        }
        return next;
    }
};