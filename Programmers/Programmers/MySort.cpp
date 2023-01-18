#include <string>
#include <vector>

using namespace std;




vector<string> solution(vector<string> strings, int n) 
{
    //n��° �ε����� �������� �������ش�.
    //����, �ε����� �ִ� ö�ڰ� ���ٸ� ����������  

    vector<string> answer;
    while (!strings.empty())
    {
        int minist = strings[0][n];
        int idx = 0;

        for (int i = 0; i < strings.size(); ++i)
        {
            //���� ���� 
            if (minist > strings[i][n])
            {
                idx = i;
                minist = strings[i][n];
            }
            else if (minist == strings[i][n])
            {
                idx = strings[i] > strings[idx] ? idx : i;
            }
        }
        answer.push_back(strings[idx]);
        strings.erase(strings.begin() + idx);
    }

    return answer;

}