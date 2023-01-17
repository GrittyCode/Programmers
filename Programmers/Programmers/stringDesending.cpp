#include <string>
#include <vector>
#include <memory>
using namespace std;

string solution(string s) 
{
    string answer = "";
    int offset = 'z' - 'A';

    unique_ptr<int[]> arr = make_unique<int[]>(offset + 1);

    for (int i = 0; i < s.length(); ++i)
    {
        ++arr[s[i] - 'A'];
    }

    for (int i = offset; i >= 0; --i)
    {
        for(int j = 0; j < arr[i]; ++j)
            answer += 'A' + i;
    }
    return answer;
}


int main(void)
{
    solution("ZzZzZXx");
    return 0;
}