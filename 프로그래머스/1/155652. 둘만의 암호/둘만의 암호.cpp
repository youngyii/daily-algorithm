#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++) {
        int indexCnt = 0;
        while (indexCnt != index) {
            s[i] = (s[i] == 122) ? 97 : s[i] + 1;
            int isSkip = 0;
            for (int j = 0; j < skip.size(); j++) {
                if (s[i] == skip[j]) {
                    cout << skip[j];
                    isSkip = 1;
                    break;
                }
            }
            if (isSkip == 0) indexCnt++;
        }
        answer += s[i];
    }
    return answer;
}