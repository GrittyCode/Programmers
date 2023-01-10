#include <string>
#include <vector>

using namespace std;


unsigned long long Factorial(int start, int N, int check = 0)
{
    unsigned long long res = start;
    vector<bool> isCheck(check + 1, false);

    for (int i = start + 1; i <= N; ++i)
    {
        res *= i;

        for(int j = 1; j <= check; ++j)
        {
            if (res % j == 0 && !isCheck[j])
            {
                isCheck[j] = true;
                res /= j;
            }
        }      
    }

    return res;
}

int solution(int balls, int share)
{
    if (balls == share)
        return 1;

    unsigned long long answer = 0;
    unsigned long long factorial, divison;
    int start = 0, nm = balls - share, check;

    if (nm < share)
    {
        start = share + 1;
        check = nm;
        divison = Factorial(1, nm);
    }
    else
    {
        start = nm + 1;
        check = share;
        divison = Factorial(1, share);
    }

    answer = Factorial(start, balls, check);

    return answer;
}


int main(void)
{
    solution(5, 3);

}