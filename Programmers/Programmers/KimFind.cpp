#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) 
{
    string answer = "";
    auto findKim = find(seoul.begin(), seoul.end(), "Kim");

    
    answer += "�輭���� ";

    int num = findKim - seoul.begin();
    answer += to_string(num);

    answer += "�� �ִ�";

    return answer;
}