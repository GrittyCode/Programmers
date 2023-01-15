#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;
    set<int> tmp;
    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            tmp.insert(numbers[i] + numbers[j]);
        }
    }
    for (const auto& temp : tmp)
    {
        answer.push_back(temp);
    }
    return answer;
}