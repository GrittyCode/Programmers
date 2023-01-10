#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) 
{
    //For문을 통해 왼 -> 오 가며 이전 글자들을 모두 검사
    vector<int> answer;
    for (auto i = s.begin(); i < s.end(); ++i)
    {
        char tmp = *i;
        int idx = -1;
        for (auto j = i - 1; j >= s.begin(); --j)
        {
            if (tmp == *j)
            {
                idx = (i - j);
                break;
            }
        }

        answer.push_back(idx);
    }

    return answer;
}