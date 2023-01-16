#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) 
{
    unordered_map<string, int> DataBase;

    DataBase.insert({ "zero",0 });
    DataBase.insert({ "one",1 });
    DataBase.insert({ "two",2 });
    DataBase.insert({ "three",3 });
    DataBase.insert({ "four",4 });
    DataBase.insert({ "five",5 });
    DataBase.insert({ "six",6 });
    DataBase.insert({ "seven",7 });
    DataBase.insert({ "eight",8 });
    DataBase.insert({ "nine",9 });


    string tmp;
    for (int i = 0; i < s.length();)
    {
        if (s[i] > 9 + '0')
        {
            tmp += s[i];
            s.erase(s.begin() + i);
        }
        else
            ++i;

        auto iter = DataBase.find(tmp);
        if (iter != DataBase.end())
        {
            s.insert(s.begin() + i, (*iter).second + '0');
            tmp = "";
        }

    }



    int answer = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        int num = s[i] - '0';
        for (int j = 0; j < s.length() - i - 1; ++j)
        {
            num *= 10;
        }

        answer += num;
    }

    return answer;
}
