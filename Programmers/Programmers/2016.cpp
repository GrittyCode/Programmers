#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) 
{
    
    string answer = "";
    string Day[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED","THU" };
    int num[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int count = -1;
    
    for (int i = 0; i < a - 1; ++i)
        count += num[i];
    
    answer = Day[(count + b) % 7];
    
    return answer;
}