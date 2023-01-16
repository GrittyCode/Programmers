#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
	
	int hashard = 0;
	int tmp = x;
	while (x > 0)
	{
		hashard += tmp % 10;
		tmp /= 10;
	}


    return answer = x % hashard == 0;
}


int main(void)
{
	solution(11);
	return 0;
}