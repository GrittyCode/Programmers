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

		//�˻�
		for (int i = 0; i < tempScore.size(); ++i)
		{
			minist = minist < tempScore[i] ? minist : tempScore[(idx = i)];			
		}

		if (!isInsert)
		{
			//�� ��ü ��, ���� ���� ���� ã������Ѵ�.
			tempScore[idx] = current;
			minist = current;
			//�˻�
			for (int i = 0; i < tempScore.size(); ++i)
			{
				minist = minist < tempScore[i] ? minist : tempScore[(idx = i)];
			}
		}

		answer.push_back(tempScore[idx]);
	}
	return answer;
}