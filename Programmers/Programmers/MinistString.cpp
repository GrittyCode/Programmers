#include <string>
#include <vector>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;
    int length = p.length();
    // -> 0번째에서부터 쭉 검사
    for (int i = 0; i <= t.length() - length; ++i)
    {
        string tmp;
        tmp = t.substr(i, length);   
        if (tmp <= p)
            ++answer;
    }

    return answer;
}


int main(void)
{
    solution("10203", "15");
    return 0;
}