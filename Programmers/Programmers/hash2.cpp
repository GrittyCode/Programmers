#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct cmp
{
    bool operator () (vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
};



int solution(vector<vector<int>> jobs) 
{
    //���� �ð� ���� ����
    sort(jobs.begin(), jobs.end());
    

    //���� �ð��� ���� �Ѵٸ�, �켱 �켱���� ť�� ������ ���ش�.
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int answer = 0, idx = 0, time = 0;

    //�ε����� �Ѿ�� �ʰ�, �켱���� ť�� ������� ���� ���� �ݺ��Ѵ�.
    while (idx < jobs.size() || !pq.empty()) 
    {
        if (jobs.size() > idx && time >= jobs[idx][0]) 
        {
            pq.push(jobs[idx++]);
            continue;
        }

        if (!pq.empty()) 
        {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
            time = jobs[idx][0];
    }
    
    return answer / jobs.size();
}


int main(void)
{
    cout << solution({ {0,3},{1,9},{2,6} });
    return 0;
}