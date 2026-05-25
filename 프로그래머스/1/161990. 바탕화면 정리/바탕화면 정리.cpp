#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int xMin = 50, xMax = -1;
    int yMin = 50, yMax = -1;
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                xMin = min(xMin, i);
                xMax = max(xMax, i);
                yMin = min(yMin, j);
                yMax = max(yMax, j);
            }
        }
    }
    answer = {xMin, yMin, xMax + 1, yMax + 1};
    
    return answer;
}