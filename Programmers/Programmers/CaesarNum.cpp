#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) 
{
    string answer = "";
    
    for (auto character : s)
    {
        if (character == ' ')
        {
            answer.push_back(character);
            continue;
        }

        if (character > 'Z')
        {
            if (character + n > 'z')
            {
                character += (n - 26);
            }
            else
                character += n;
        }
        else
        {
            if (character + n > 'Z')
            {
                character += (n - 26);
            }
            else
                character += n;
        }

        answer.push_back(character);
    }
    return answer;
}