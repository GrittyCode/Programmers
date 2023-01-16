#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());

    for (const auto& tmp : d)
    {
        budget -= tmp;

        if (budget <= 0)
        {
            answer = budget == 0 ? ++answer : answer;
            break;
        }

        ++answer;
    }
    return answer;
}