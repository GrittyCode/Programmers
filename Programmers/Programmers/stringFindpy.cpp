#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int pIdx = 0, yIdx = 0;

    for (const auto& tmp : s)
    {
        if (tmp == 'p' || tmp == 'P')
            ++pIdx;
        else if (tmp == 'y' || tmp == 'Y')
            ++yIdx;
    }

    return pIdx == yIdx;
}