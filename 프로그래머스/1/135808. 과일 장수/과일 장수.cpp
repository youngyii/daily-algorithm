#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    int boxCnt = score.size() / m;
    
    int tmp = m - 1;
    for(int i = 0; i < boxCnt; i++) {
        answer += score[tmp] * m * 1;
        tmp += m;
    }
    
    return answer;
}