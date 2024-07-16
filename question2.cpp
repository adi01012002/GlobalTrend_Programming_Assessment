#include <iostream>
#include <unordered_set>
using namespace std;

int Substring(string s)
{
    int n = s.length();
    unordered_set<char> set;
    int maxLen = 0;
    int i = 0, j = 0;

    while (j < n)
    {
        char currentChar = s[j];
        if (set.find(currentChar) == set.end())
        {
            set.insert(currentChar);
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else
        {
            set.erase(s[i]);
            i++;
        }
    }

    return maxLen;
}

int main()
{
    string input = "abcddabbgfhcbb";

    int result = Substring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
}
