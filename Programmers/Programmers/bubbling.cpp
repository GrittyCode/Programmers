#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) 
{
    int answer = 0;

    for (const auto& word : babbling)
    {
        bool isWord = true; 
        char flag = 0;
        for (int i = 0; i < word.length(); )
        {
            //substr -> ù��° �Ű����� ���� �ε���, �ι�° �Ű����� �ڸ� ����
            if (word.substr(i, 3) == "aya" && flag != 1) { i += 3; flag = 1; }
            else if (word.substr(i, 2) == "ye" && flag != 2) { i += 2; flag = 2;}
            else if (word.substr(i, 3) == "woo" && flag != 3) { i += 3; flag = 3; }
            else if (word.substr(i, 2) == "ma" && flag != 4) { i += 2; flag = 4; }
            else { isWord = false; break; }
        }

        if (isWord)
            ++answer;
    }

    return answer;
}