#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    set<pair<long long, long long>> s;
    
    // 모든 직선 쌍 비교
    for (int i = 0; i < line.size(); i++) {
        long long A = line[i][0];
        long long B = line[i][1];
        long long E = line[i][2];
        
        for (int j = i + 1; j < line.size(); j++) {     
            long long C = line[j][0];
            long long D = line[j][1];
            long long F = line[j][2];
        
            if (A * D - B * C == 0) continue; // 두 직선이 평행 또는 일치
            
            // 정수 교점 저장
            if ((B * F - E * D) % (A * D - B * C) == 0 
                && (E * C - A * F) % (A * D - B * C) == 0) 
            {
                long long x = (B * F - E * D) / (A * D - B * C); // 교점의 x좌표
                long long y = (E * C - A * F) / (A * D - B * C); // 교점의 y좌표
                s.insert({x, y});
            }
        }
    }
    
    // 최소/최대 좌표 구하기
    long long xMin = LLONG_MAX, xMax = LLONG_MIN;
    long long yMin = LLONG_MAX, yMax = LLONG_MIN;
    
    for (const auto& [x, y] : s) {
        xMin = min(xMin, x);
        xMax = max(xMax, x);
        yMin = min(yMin, y);
        yMax = max(yMax, y);
    }
    
    // 2차원 배열 크기 결정
    long long xSize = xMax - xMin + 1;
    long long ySize = yMax - yMin + 1;
    
    vector<string> answer(ySize, string(xSize, '.'));
    
    // y 좌표는 뒤집어서 (위에서부터)
    for (const auto& [x, y] : s) answer[yMax - y][x - xMin] = '*';
    
    return answer;
}