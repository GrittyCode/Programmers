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
    // �Ű� �Խ��� �˰��� -> ������ ����� �Ű� �� ��� 1������ ���
    // ������ �������� �Ű��� -> �ǽŰ��ڷ� ����

    unordered_map <string, id_DataBase> dataBase;

    for (const auto& key : id_list)
    {
        dataBase.insert({key, id_DataBase()});
    }

    vector<int> answer;

    //�Ű� ó�� ����
    for (const auto& text : report)
    {
        size_t idx = 0;
        size_t current;
        //���� ã��
        current = text.find(' ');
        string reporter = text.substr(0, current);
        string accused = text.substr(current + 1, text.length());

        //�Ű��� Ű �ߺ� ����
        //�ǽŰ��� ī���� + 1
        if (dataBase[reporter].banList.find(accused) == dataBase[reporter].banList.end())
        {
            dataBase[reporter].banList.insert(accused);
            ++dataBase[accused].reportCnt;        
        }

    }

    //�� ����Ʈ ó��
    for (auto& data : dataBase)
    {
        //�Ű�� ����̶��
        if (data.second.reportCnt >= k)
        {
            //�����ͺ��̽� �˻�
            for (auto& reporter : dataBase)
            {
                //�Ű��� �ڶ��
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