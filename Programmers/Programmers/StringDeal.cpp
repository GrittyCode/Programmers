#include <string>
#include <vector>

using namespace std;

bool solution(string s) 
{
    bool answer = true;

    if (!(s.length() == 4|| s.length() == 6))
    {
        return false;
    }

    for (const auto& tmp : s)
    {
        if (!(tmp >= '0' && tmp <= '9'))
            return false;
    }

    return answer;
}