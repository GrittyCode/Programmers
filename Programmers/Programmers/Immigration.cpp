#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) 
{
    sort(times.begin(), times.end());
    //n명이 입국심사를 위해 기다리는 사람
    //times -> 창구에서 걸리는 시간을 담당
    long long answer = 0;
    long long min = 1;
    long long max = static_cast<long long>(times.back()) * n;
    
    //min max 엇갈리면 발견
    while (min <= max)
    {
        long long avg = (min + max) / 2;
        int idx = 0;

        for (const auto& t : times)
        {
            idx += (avg / t);
        }

        //분기 나누기
        if (n <= idx)
        {
            answer = max;
            max = avg - 1;
        }
        else
        {
            answer = min;
            min = avg + 1;
        }
    }

    return answer;


}



int main(void)
{
    solution(6, { 7,10 });
    return 0;
}