#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    //a -> 빈 병 개수 필요
    //b -> 얻는 콜라수
    //n -> 현재, 빈병 콜라
    int answer = 0, remainder = 0;
    int recycle = 0;
    while (n >= a)
    {
        //남은 병 수
        //재사용하여 얻는 몫
        recycle = n / a;
        n = n - (recycle * a) + b * recycle;
        //실제 다시 받는 콜라 수
        answer += b * recycle;
    }
  
    return answer;
}


int main(void)
{
    solution(3, 1, 20);
    return 0;
}