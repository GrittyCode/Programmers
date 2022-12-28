#include <vector>
#include <iostream>
using namespace std;


void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void QuickSort(vector<int>& arr, int start, int end)
{
	//원소가 하나 뿐이라면 종료
	if (start >= end)
		return;

	int pivot = start;
	int i = start + 1;
	int j = end;

	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
		{
			++i;
		}

		while (j > start && arr[j] >= arr[pivot])
		{
			--j;
		}

		//교차된다면? j의 위치가 pivot의 위치에 맞는것.
		if (i > j)
		{
			Swap(arr[j], arr[pivot]);
		}
		else
		{
			Swap(arr[i], arr[j]);
		}
	}

	QuickSort(arr, start, j - 1);
	QuickSort(arr, j + 1, end);

}

