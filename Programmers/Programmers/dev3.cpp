#include <string>
#include <vector>
#include <cmath>
using namespace std;

constexpr double BallDiameter = 2;

bool IsCrash(vector<double> pointA, vector<double> pointB)
{
    double a = abs(pointA[0] - pointB[0]);
    double b = abs(pointA[1] - pointB[1]);

    if (a > 1 || b > 1)
        return false;

    return true;
}

int solution(vector<vector<double>> objectBallPosList, vector<double> hitVector)
{
    int answer = -1;
    vector<double> curPos = { 0.0,0.0 };

    bool isCrash = false;

    bool isPlusX = hitVector[0] >= 0;
    bool isPlusY = hitVector[1] >= 0;
    double xMax = objectBallPosList[0][0], yMax = objectBallPosList[0][1];
    
    if (isPlusX)
    {
        for (int i = 0; i < objectBallPosList.size(); ++i)
        {
            xMax = xMax > objectBallPosList[i][0] ? xMax : objectBallPosList[i][0];
            if (objectBallPosList[i][0] < 0)
            {
                objectBallPosList.erase(objectBallPosList.begin() + i);
                --i;
            }
        }
    }
    else
    {
        for (int i = 0; i < objectBallPosList.size(); ++i)
        {
            xMax = xMax > objectBallPosList[i][0] ? objectBallPosList[i][0] : xMax;
            if (objectBallPosList[i][0] > 0)
            {
                objectBallPosList.erase(objectBallPosList.begin() + i);
                --i;
            }
        }
    }


    if (isPlusY)
    {
        for (int i = 0; i < objectBallPosList.size(); ++i)
        {
            yMax = yMax > objectBallPosList[i][1] ? yMax : objectBallPosList[i][1];
            if (objectBallPosList[i][1] < 0)
            {
                objectBallPosList.erase(objectBallPosList.begin() + i);
                --i;
            }
        }
    }
    else
    {
        for (int i = 0; i < objectBallPosList.size(); ++i)
        {
            yMax = yMax > objectBallPosList[i][1] ? objectBallPosList[i][1] : yMax;
            if (objectBallPosList[i][1] > 0)
            {
                objectBallPosList.erase(objectBallPosList.begin() + i);
                --i;
            }
        }
    }

    xMax = abs(xMax);
    yMax = abs(yMax);

    while (!isCrash && !(abs(curPos[0]) > xMax || abs(curPos[1]) > yMax))
    {
        for (int i = 0; i < objectBallPosList.size(); ++i)
        {
            isCrash = IsCrash(curPos, objectBallPosList[i]);

            if (isCrash)
            {
                answer = i;
                break;
            }
        }

        curPos[0] += hitVector[0];
        curPos[1] += hitVector[1];

    }
    return answer;
}



int main(void)
{
    solution({ {5.0,5.0} ,{0.0,3.0},{1.0,1.0} }, { 1.0,1.0 });
    return 0;
}