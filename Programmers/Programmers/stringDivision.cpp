#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    //시작 부분을 담고 있는 임시 문자 영역 필요, 시작 문자 인덱스 영역, 다른 문자 인덱스 영역 필요
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