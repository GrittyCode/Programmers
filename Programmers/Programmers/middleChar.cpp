#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    bool isOdd = s.length() % 2;
    
    if (isOdd)
    {
        answer.push_back(s[s.length() / 2]);
    }
    else
    {
        answer.push_back(s[s.length() / 2 - 1]);
        answer.push_back(s[s.length() / 2]);

    }
    
    return answer;
}