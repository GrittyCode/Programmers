#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    bool flag = false;
    int i = 0;

    if (s[0] == '-')
    {
        flag = true;
        i = 1;
    }    
    else if (s[0] == '+')
    {
        i = 1;
    }


    for (; i < s.length(); ++i)
    {
        answer += s[i] - '0';
        answer *= 10;
    }
    
    answer /= 10;

    return flag ? -1 * answer : answer;
}