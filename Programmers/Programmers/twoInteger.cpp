#include <string>
#include <vector>

using namespace std;

// ���콺 ���� ���ϱ�

long long solution(int a, int b) 
{
    long long answer = 0;
    //a�� ������ b�� ū �� ����
    long long max = a > b ? a : b;
    long long min = a < b ? a : b;
    
    if (max == min)
        return max;

    //������ ������ ¦�� �� ��,
    bool isEven = (max - min) % 2;

    //¦���� �� ��
    if (isEven)
    {
        answer += (max - min + 1) / 2 * (max + min);
    }
    //Ȧ���� �� ��
    else
    {
        answer += ((max - min) / 2 * (max + min)) + ((max + min) / 2);
    }

    return answer;
}