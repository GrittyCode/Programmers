#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) 
{
    int answer = 0;
    //number -> ���ѻ� 3�� ������ ���� 0�� �� �� answer + 1
    //1,2,3,4,5... -> 123�����˻�
    for (int i = 0; i < number.size() - 2; ++i)
    {
        int res = number[i];

        for (int j = i + 1; j < number.size() - 1; ++j)
        {
            res += number[j];
            for (int k = j + 1; k < number.size(); ++k)
            {
                res += number[k];
                if (res == 0)
                    ++answer;
                res -= number[k];
            }
            res -= number[j];
        }
    }

    return answer;
}