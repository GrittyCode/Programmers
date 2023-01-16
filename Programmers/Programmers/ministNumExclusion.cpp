#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    
    int minist = arr[0];
    int idx = 0;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (minist > arr[i])
        {
            minist = arr[i];
            idx = i;
        }
    }

    arr.erase(arr.begin() + idx);

    if (arr.empty())
        arr.push_back(-1);

    return arr;
}