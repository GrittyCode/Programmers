#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (int i = 0; i < absolutes.size(); ++i)
    {
        int offset = signs[i] ? 1 : -1;
        answer += absolutes[i] * offset;
    }
    return answer;
}