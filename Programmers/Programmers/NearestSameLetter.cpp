#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) 
{
    //For���� ���� �� -> �� ���� ���� ���ڵ��� ��� �˻�
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