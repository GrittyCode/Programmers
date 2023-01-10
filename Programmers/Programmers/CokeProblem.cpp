#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    //a -> �� �� ���� �ʿ�
    //b -> ��� �ݶ��
    //n -> ����, �� �ݶ�
    int answer = 0, remainder = 0;
    int recycle = 0;
    while (n >= a)
    {
        //���� �� ��
        //�����Ͽ� ��� ��
        recycle = n / a;
        n = n - (recycle * a) + b * recycle;
        //���� �ٽ� �޴� �ݶ� ��
        answer += b * recycle;
    }
  
    return answer;
}


int main(void)
{
    solution(3, 1, 20);
    return 0;
}