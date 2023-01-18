#include <string>
#include <vector>

using namespace std;




vector<string> solution(vector<string> strings, int n) 
{
    //n번째 인덱스를 기준으로 정렬해준다.
    //만약, 인덱스에 있는 철자가 같다면 사전순으로  

    vector<string> answer;
    while (!strings.empty())
    {
        int minist = strings[0][n];
        int idx = 0;

        for (int i = 0; i < strings.size(); ++i)
        {
            //가장 작은 
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