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
    //시작 시간 별로 정렬
    sort(jobs.begin(), jobs.end());
    

    //시작 시간에 부합 한다면, 우선 우선순위 큐에 대입을 해준다.
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int answer = 0, idx = 0, time = 0;

    //인덱스가 넘어가지 않고, 우선순위 큐가 비어있지 않을 동안 반복한다.
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