#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";
    int gap = 'a' - 'A';
    
    int digit = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ')
        {
            digit = 0;
            continue;
        }

        bool isOdd = digit % 2;

        if (isOdd)
        {
            if (s[i] <= 'Z')
            {
                s[i] += gap;
            }
        }
        else
        {
            if (s[i] >= 'a')
            {
                s[i] -= gap;
            }
        }

        ++digit;
    }

    return s;
    
}