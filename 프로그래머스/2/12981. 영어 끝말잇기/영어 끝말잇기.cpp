#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_map<string,int> um;
    
    // 첫 번째 단어 삽입
    um[words[0]] = 1;
    
    for (int i = 1; i < words.size(); i++) {
        string curr = words[i];
        string prev = words[i - 1];
    
        int player = (i % n) + 1; // 탈락한 사람의 번호
        int turn = (i / n) + 1;   // 그 사람의 몇 번째 차례인지
        
        
        // 1. 끝말잇기 규칙 확인 (이전 단어 끝자리 != 현재 단어 첫자리)
        // 2. 단어 길이 확인 (1글자 여부)
        // 3. 중복 확인 (이미 um에 존재하는지)
        if (prev.back() != curr.front() || curr.size() == 1 || um.count(curr)) {
            return {player, turn};
        }
        
        // 통과했다면 맵에 추가
        um[curr] = 1;
    }
    
    // 아무도 탈락하지 않았다면
    return {0, 0};
}