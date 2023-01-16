#include <string>
#include <vector>

using namespace std;

int solution(int num) 
{
    int answer = 0;
	unsigned long long num2 = num;
	while (num2 != 1 && answer <= 500)
	{
		if (num2 % 2)
		{
			num2 = num2 * 3 + 1;
		}
		else
		{
			num2 /= 2;
		}
		
		++answer;

	}

    return answer > 500 ? -1  : answer;
}


int main(void)
{
	solution(5);
}