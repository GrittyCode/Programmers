#include <string>
#include <vector>

using namespace std;


string ToBinaryNumber(int n, int num)
{
    string numString;
    for (int i = 0; i < n; ++i)
    {
        numString += ' ';
    }


    while (num > 0)
    {
        --n;
        char tmp = num % 2 + '0';
        tmp = (tmp == '1') ? '#' : ' ';
        numString[n] = tmp;
        num /= 2;
    }

    return numString;
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    //arr1 ÇØµ¶
    for (const auto& num : arr1)
    {
        answer.push_back(ToBinaryNumber(n,num));
    }

    for (int i = 0; i < arr2.size(); ++i)
    {
        string tmp = ToBinaryNumber(n, arr2[i]);
        for (int j = 0; j < tmp.length(); ++j)
        {
            if (tmp[j] == '#')
                answer[i][j] = '#';
        }
    }
    return answer;
}


int main(void)
{
    solution(6, { 46,33,33,22,31,50 }, { 27,56,19,14,14,10 });
    return 0;
}