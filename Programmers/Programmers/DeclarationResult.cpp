#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

struct idDataBase
{
    int reportCnt = 0;
    int mailCnt = 0;
    unordered_set<string> banList;

}typedef id_DataBase;


vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    // 신고 게시판 알고리즘 -> 동일한 사람이 신고 한 경우 1번으로 취급
    // 공백을 기준으로 신고자 -> 피신고자로 구분

    unordered_map <string, id_DataBase> dataBase;

    for (const auto& key : id_list)
    {
        dataBase.insert({key, id_DataBase()});
    }

    vector<int> answer;

    //신고 처리 구문
    for (const auto& text : report)
    {
        size_t idx = 0;
        size_t current;
        //공백 찾기
        current = text.find(' ');
        string reporter = text.substr(0, current);
        string accused = text.substr(current + 1, text.length());

        //신고자 키 중복 점검
        //피신고자 카운터 + 1
        if (dataBase[reporter].banList.find(accused) == dataBase[reporter].banList.end())
        {
            dataBase[reporter].banList.insert(accused);
            ++dataBase[accused].reportCnt;        
        }

    }

    //벤 리스트 처리
    for (auto& data : dataBase)
    {
        //신고된 사람이라면
        if (data.second.reportCnt >= k)
        {
            //데이터베이스 검색
            for (auto& reporter : dataBase)
            {
                //신고한 자라면
                if (reporter.second.banList.find(data.first) != reporter.second.banList.end())
                {
                    ++reporter.second.mailCnt;
                }
            }
        }
    }

    for (const auto& id : id_list)
    {
        answer.push_back(dataBase[id].mailCnt);
    }

    return answer;
}