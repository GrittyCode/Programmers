#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int k, vector<int> score)
{
	vector<int> answer;
	vector<int> tempScore;
	for (const auto& current : score)
	{
		int minist = 2000, idx = 0;
		bool isInsert = false;

		if (tempScore.size() < k)
		{
			tempScore.push_back(current);
			isInsert = true;
		}

		//검사
		for (int i = 0; i < tempScore.size(); ++i)
		{
			minist = minist < tempScore[i] ? minist : tempScore[(idx = i)];			
		}

		if (!isInsert)
		{
			//수 교체 후, 가장 작은 값을 찾아줘야한다.
			tempScore[idx] = current;
			minist = current;
			//검사
			for (int i = 0; i < tempScore.size(); ++i)
			{
				minist = minist < tempScore[i] ? minist : tempScore[(idx = i)];
			}
		}

		answer.push_back(tempScore[idx]);
	}
	return answer;
}