#include <string>
#include <vector>

using namespace std;


enum class EGroundType
{
    BASIC,
    ROCK,
    MUSHROOM
};

int CheckField(vector<vector<int>>& map, int c, int r, int farmSize)
{
    int cnt = 0;

    int colmnSize = c + farmSize;
    int rowSize = r + farmSize;

    if (colmnSize > map.size() || rowSize > map[0].size())
    {
        return -1;
    } 


    for (int col = c; col < colmnSize; ++col)
    {
        for (int row = r; row < rowSize; ++row)
        {
            if (map[col][row] == (int)EGroundType::ROCK)
                ++cnt;
            else if (map[col][row] == (int)EGroundType::MUSHROOM)
            {
                return -1;
            }
            
        }
    }
    return cnt;
}



int solution(vector<vector<int>> field, int farmSize) 
{
    //field -> 맵 배열 farmSize -> 정사각형 필드 검출
    int answer = -1;

    for (int c = 0; c < field.size(); ++c)
    {
        for (int r = 0; r < field[c].size(); ++r)
        {
            //farmSize만큼 돌아야 한다.
            int tmp = CheckField(field, c, r, farmSize);
            if (tmp >= 0)
            {
                if (answer == -1)
                    answer = tmp;
                else
                   answer = answer > tmp ? tmp : answer;
            }
        }
    }

    return answer;
}



int main(void)
{
    solution({ {0,0,1,0,0},{1,1,0,0,2},{1,0,0,0,0} }, 3);
    return 0;
}