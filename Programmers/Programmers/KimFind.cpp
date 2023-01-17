#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) 
{
    string answer = "";
    auto findKim = find(seoul.begin(), seoul.end(), "Kim");

    
    answer += "김서방은 ";

    int num = findKim - seoul.begin();
    answer += to_string(num);

    answer += "에 있다";

    return answer;
}