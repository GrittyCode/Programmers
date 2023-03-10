#include <string>
#include <vector>

using namespace std;

int solution(int left, int right)
{
    int answer = 0;

    for (int i = left; i <= right; ++i)
    {
        int cnt = 0;

        for (int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                int slice = i / j;

                if (slice * slice == i)
                    ++cnt;
                else
                    cnt += 2;
            }
        }

        if (cnt % 2 || cnt < 1)
            answer -= i;
        else
            answer += i;
    }

    return answer;
}