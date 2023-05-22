/* 
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

Constraints:

    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.

Solution uses hash map, example:

s_map:
Index (ASCII value) | 97 | 98 | 99 | ... | 100 | 101 | 102 | 103 | ... | 1023 |
---------------------------------------------------------------------------------
Value (mapped char) | 0  | 0  | 0  | ... | 'd' | 'a' | 0   | 0   | ... | 0    |

t_map:
Index (ASCII value) | 97 | 98 | 99 | ... | 100 | 101 | 102 | 103 | ... | 1023 |
---------------------------------------------------------------------------------
Value (mapped char) | 'e'| 0  | 0  | ... | 'g' | 0   | 0   | 0   | ... | 0    |

 */

bool isIsomorphic(char * s, char * t)
{
	char	s_map[128] = {0};
	char	t_map[128] = {0};
	int		i = 0;

	while (i < strlen(s))
	{
		if (s_map[s[i]] == 0 && t_map[t[i]] == 0)
		{
			s_map[s[i]] = t[i];
			t_map[t[i]] = s[i];
		}
		else if (s_map[s[i]] != t[i] || t_map[t[i] != s[i]])
			return (0);
		i++;
	}
	return (1);
}