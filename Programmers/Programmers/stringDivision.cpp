#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    //���� �κ��� ��� �ִ� �ӽ� ���� ���� �ʿ�, ���� ���� �ε��� ����, �ٸ� ���� �ε��� ���� �ʿ�
    int answer = 0;
    char oriChar = s[0];
    int origin = 0, diff = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (origin == diff)
        {
            oriChar = s[i];
            origin = 0; diff = 0;
            ++answer;
        }


        if (oriChar == s[i])
            ++origin;
        else
            ++diff;
    }
    
    return answer;
}