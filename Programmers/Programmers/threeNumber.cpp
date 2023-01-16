#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    string threeNum = "";

    while (n > 0)
    {
        threeNum += n % 3 + '0';
        n /= 3;
    }

    for (int i = 0; i < threeNum.length(); ++i)
    {
        if (threeNum[i] == 0)
            continue;

        int mul = 1;
        for (int j = threeNum.length() - 1; j > i; --j)
        {
            mul *= 3;
        }
        answer += (threeNum[i] - '0') * mul;
    }

    return answer;
}

int main(void)
{
    solution(45);
    return 0;
}