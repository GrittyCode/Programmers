#include <string>
#include <vector>

using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
	int score[10] = { 0, };


	while (n > 0)
	{
		int tmp = n % 10;
		score[tmp]++;
		n /= 10;
	}


	for (int i = 9; i >= 0; --i)
	{
		while (score[i] > 0)
		{
			answer += i;
			answer *= 10;		
			--score[i];
		}
	}

    return answer / 10;
}