/* 
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

Constraints:

    1 <= s.length <= 2000
    s consists of lowercase and/or uppercase English letters only.
 */
int longestPalindrome(char * s)
{
    if (strlen(s) == 1)
        return (1);
    int s_map[128] = {0};
    int s_len = strlen(s);
    int i = 0;
    int l = 0;

    while (i < s_len)
    {
        s_map[s[i]] += 1;
        if (s_map[s[i]] % 2 == 0)
            l += 2;
        i++;
    }
    if (s_len - l != 0)
        return (l + 1);
    else
        return (l);
}