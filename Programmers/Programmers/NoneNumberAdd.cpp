#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) 
{
    int answer = 45;
    bool isExist[10] = { false, };
    
    for (const auto& num : numbers)
    {
        if (!isExist[num])
        {
            answer -= num;
            continue;
        }

        isExist[num] = true;
    }

    return answer;
}