#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health; // 현재 체력
    
    int t = bandage[0]; // 시전 시간
    int x = bandage[1]; // 초당 회복량
    int y = bandage[2]; // 추가 회복량
    int tCnt = 0;   // 붕대 감기 시전 시간
    int now  = 0;   // 현재 공격 순서 체크
    
    for (int i = 1; i <= attacks.back()[0]; i++) {
        if (attacks[now][0] == i) {
            answer -= attacks[now][1];
            tCnt = 0;
            now++;
            if (answer <= 0) {
                answer = -1;
                break;
            }
        } else {
            //answer = (answer + x < health) ? answer + x : health;
            answer = min(answer + x, health);
            tCnt++;
            if (tCnt == t) {
                //answer = (answer + y < health) ? answer + y : health;
                answer = min(answer + y, health);
                tCnt = 0;
            }
        }
    }
    
    return answer;
}