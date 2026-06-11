#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> counter;
    
    for (string p : participant) {
        counter[p]++;
    }
    
    for (string c : completion) {
        counter[c]--;
        if (counter[c] == 0) counter.erase(c); 
    }
    
    return counter.begin()->first;
    
}