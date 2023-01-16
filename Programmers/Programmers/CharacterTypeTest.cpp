#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    //survey���� ù ö�� -> 1,2,3 -> 3, 2, 1 ���� �ο� �ι� ° ö�� -> 5,6,7 -> 1,2,3 ���� �ο�
    //������ ���ٸ� ���� ������ �ο�
    string answer = "";
    
    //��ǥ�� ���� ���� ������ ��� ���� ����
    int characterScore[4] = { 0, };

    // ���� Ÿ��    1   2   3   4   1   2   3   4
    char characterType[8] = { 'R','C','J','A','T','F','M','N' };


    for (int i = 0; i < survey.size(); ++i)
    {
        char first  = survey[i][0];
        int  idx = 0;

        //���� ���� ��ǥ ����
        for (int j = 0; j < 8; ++j)
        {
            if (first == characterType[j])
            {
                idx = j;
                break;
            }
        }

        int minus = idx < 4 ? 1 : -1;
        characterScore[idx % 4] += minus * (choices[i] - 4);
    }

    for (int i = 0; i < 4; ++i)
    {
        if (characterScore[i] > 0)
        {
            answer += characterType[i + 4];
        }
        else 
        {
            if (characterScore[i] == 0)
            {
                char realChar = characterType[i] < characterType[i + 4] ? characterType[i] : characterType[i + 4];
                answer += realChar;
                continue;
            }

            answer += characterType[i];
        }
    }


    return answer;
}


int main(void)
{

    solution({ "AN", "CF", "MJ", "RT", "NA" }, { 5, 3, 2, 7, 5 });
    return 0;
}