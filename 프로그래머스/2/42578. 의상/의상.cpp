#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> um;
    
    for(int i = 0; i < clothes.size(); i++) um[clothes[i][1]]++;
        
    for(pair<string,int> p : um) // 종류별로 경우의 수 곱하기
        answer *= p.second + 1;  // 모든 의상 + 안입는 경우

    answer--; // 아무것도 안 입는 경우 제외
    
    return answer;
}