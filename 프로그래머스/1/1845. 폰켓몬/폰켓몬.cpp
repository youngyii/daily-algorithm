#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    map<int, int> m;
    for (auto n : nums) m[n]++;

    answer += min(nums.size() / 2, m.size());
    
    
    return answer;
}