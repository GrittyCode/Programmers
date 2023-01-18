#include <string>
#include <vector>

using namespace std;

// 가우스 덧셈 구하기

long long solution(int a, int b) 
{
    long long answer = 0;
    //a에 작은수 b에 큰 수 대입
    long long max = a > b ? a : b;
    long long min = a < b ? a : b;
    
    if (max == min)
        return max;

    //숫자의 개수가 짝수 일 때,
    bool isEven = (max - min) % 2;

    //짝수개 일 때
    if (isEven)
    {
        answer += (max - min + 1) / 2 * (max + min);
    }
    //홀수개 일 떄
    else
    {
        answer += ((max - min) / 2 * (max + min)) + ((max + min) / 2);
    }

    return answer;
}