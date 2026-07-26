#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    vector<vector<int>> v(friends.size(), vector<int>(friends.size() + 1, 0));
    
    unordered_map<string, int> um;
    
    vector<int> next(friends.size(), 0);
    
    for (int i = 0; i < friends.size(); i++)
        um[friends[i]] = i;
    
    for (string g : gifts) {
        stringstream ss(g);
        string first, second;
        ss >> first >> second;
        
        int firstIdx = um[first];
        int secondIdx = um[second];
        
        // 주고받은 선물 저장
        v[firstIdx][secondIdx]++;
        
        // 선물 지수 계산
        v[firstIdx][friends.size()]++;
        v[secondIdx][friends.size()]--;
    }
    
    for (int i = 0; i < friends.size(); i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            if (v[i][j] > v[j][i])
                next[i]++;
            else if (v[i][j] == v[j][i])
                if (v[i][friends.size()] > v[j][friends.size()])
                    next[i]++;
                else if (v[i][friends.size()] < v[j][friends.size()])
                    next[j]++;
                else continue;
            else next[j]++;
        }
    }
    
    answer = -1;
    for (int n : next) {
        answer = max(answer, n);
    }
    
    return answer;
}