#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    int idxA[10] = { 0, };
    int idxB[10] = { 0, };

    for (int i = 0; i < X.size(); ++i)
    {
        ++idxA[X[i] - '0'];
    }

    for (int i = 0; i < Y.size(); ++i)
    {
        ++idxB[Y[i] - '0'];
    }


    for (int i = 9; i >= 0; --i)
    {
        while (idxA[i] > 0 && idxB[i] > 0)
        {
            answer += i + '0';
            --idxA[i];
            --idxB[i];
        }
    }

    if (answer == "")
        answer = "-1";
    else if (answer[0] == '0')
        answer = "0";
    return answer;

}
