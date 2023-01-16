#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    vector<int> answer;
    unordered_set<int> winNum;
    
    for (int i = 0; i < win_nums.size(); ++i)
    {
        winNum.insert(win_nums[i]);
    }


    int cnt = 0;
    int zero = 0;
    
    for (int i = 0; i < lottos.size(); ++i)
    {
        if (winNum.find(lottos[i]) != winNum.end())
            ++cnt;
        else if (lottos[i] == 0)
            ++zero;
    }

    int Best = 7 - (cnt + zero) > 6 ? 6 : 7 - (cnt + zero);
    int Worst = 7 - cnt > 6 ? 6 : 7 - cnt;

    answer.push_back(Best);
    answer.push_back(Worst);

    return answer;
}