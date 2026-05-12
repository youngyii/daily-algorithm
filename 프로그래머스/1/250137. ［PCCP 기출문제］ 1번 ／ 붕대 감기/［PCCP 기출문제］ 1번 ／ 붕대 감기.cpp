#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health; // 현재 체력
    
    int t = bandage[0]; // 시전 시간
    int x = bandage[1]; // 초당 회복량
    int y = bandage[2]; // 추가 회복량
    
    int lastTime = 0;   // 직전 공격이 끝난 시간
    
    for (int i = 0; i < attacks.size(); i++) {
        // 공격 사이의 시간
        int term = attacks[i][0] - lastTime - 1;
        
        if (term > 0) {
            // 연속 성공 횟수에 따른 총 회복량
            answer = min(health, answer + (term * x) + (term / t * y));
        }
        
        answer -= attacks[i][1];
        
        if (answer <= 0) return -1;
        
        lastTime = attacks[i][0];
    }
    
    return answer;
}