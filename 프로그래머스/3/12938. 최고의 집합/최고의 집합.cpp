#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (s < n) answer.push_back(-1);
    else {
        for (int i = 0; i < s % n; i++)
            answer.push_back(s / n + 1);

        for (int i = 0; i < n - s % n; i++)
            answer.push_back(s / n);
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}