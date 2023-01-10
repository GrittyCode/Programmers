#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;

    //약수를 구해준다.
    for (int i = 1; i <= number; ++i)
    {
        int cnt = 0;
        for (int j = 1; j * j <= i; ++j)
        {
            if (i % j != 0)
                continue;

            int share = i / j;
            if (share == j) cnt += 1;
            else cnt += 2;
        }


        if (cnt > limit)
            answer += power;
        else
            answer += cnt;
    }

    return answer;
}


int main(void)
{
    solution(10, 3, 2);
    return 0;
}