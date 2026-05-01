#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> userMap;
    
    // 명령어와 아이디를 저장할 vector
    vector<pair<string, string>> logs; 
    
    // vector의 메모리 재할당을 막기 위해 미리 공간 확보
    logs.reserve(record.size()); 

    // 전체 기록을 순회하며 닉네임 최신화 및 출력할 로그 기록
    for (const string& r : record) {
        stringstream ss(r);
        string command, id, nickname;
        ss >> command >> id;
        
        if (command == "Enter") {
            ss >> nickname;
            userMap[id] = nickname;
            logs.push_back({command, id});
        } 
        else if (command == "Leave") {
            logs.push_back({command, id});
        } 
        else if (command == "Change") {
            ss >> nickname;
            userMap[id] = nickname;
        }
    }

    // 정답 vector도 미리 메모리 공간 확보
    answer.reserve(logs.size());

    // 저장된 로그를 바탕으로 최종 출력 메시지 생성
    for (const auto& log : logs) {
        if (log.first == "Enter") {
            answer.push_back(userMap[log.second] + "님이 들어왔습니다.");
        } else if (log.first == "Leave") {
            answer.push_back(userMap[log.second] + "님이 나갔습니다.");
        }
    }

    return answer;
}