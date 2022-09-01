#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int std[30] = {0};
    //잃어버린 학생 번호에 -1
    for (int i = 0; i < lost.size(); i++)
    {
        int temp;
        temp = lost[i];
        std[temp] -= 1;
    }
    //여분가져온 학생에다 +1
    for (int i = 0; i < reserve.size(); i++)
    {
        int temp;
        temp = reserve[i];
        std[temp] += 1;
    }
    //여기까지 오면 1이면 여분가지고있음 0이면 자기꺼만있음 -1이면 도난당함

    // -1찾기
    for (int i = 1; i <= n; i++)
    {
        //잃어버렷으면
        if (std[i] == -1)
        {
            //전번호가 여분이 있으면
            if (std[i - 1] == 1)
            {
                std[i - 1] = 0;
                std[i] = 0;
            }
            //앞번호가 여분이 있으면
            else if (std[i + 1] == 1)
            {
                std[i + 1] = 0;
                std[i] = 0;
            }
        }
    }
    //-1아닌친구만 정답에 더해주기
    for (int i = 1; i <= n; i++)
    {
        if (std[i] != -1)
        {
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    int n = 5;
    vector<int> lost = {2,4};
    vector<int> reserve = { 1,3,5 };
    solution(n, lost, reserve);
}
