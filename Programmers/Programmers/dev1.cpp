#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> quest) 
{
    int answer = 0;
    int level = 0;
    sort(quest.begin(), quest.end());

    for (const auto& curExp : quest)
    {
        if (curExp[0] <= level)
        {
            level += curExp[1];
            ++answer;
        }
    }

    return answer;
}