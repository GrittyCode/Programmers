#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) 
{
    sort(times.begin(), times.end());
    //n���� �Ա��ɻ縦 ���� ��ٸ��� ���
    //times -> â������ �ɸ��� �ð��� ���
    long long answer = 0;
    long long min = 1;
    long long max = static_cast<long long>(times.back()) * n;
    
    //min max �������� �߰�
    while (min <= max)
    {
        long long avg = (min + max) / 2;
        int idx = 0;

        for (const auto& t : times)
        {
            idx += (avg / t);
        }

        //�б� ������
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