#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool Solution(string str)
{
	if (str.empty())
		return false;

	stack<char> data;

	for (auto iter = str.begin(); iter != str.end(); ++iter)
	{
		if (*iter == '(')
		{
			data.push(*iter);
		}
		else if (*iter == ')')
		{
			if (data.empty())
				return false;
			data.pop();
		}
	}

	if (!data.empty())
		return false;
	else
		return true;

}
