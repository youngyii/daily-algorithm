#include <string>
#include <vector>
#include <cstdio> // sscanf를 위해 필요

using namespace std;

// "mm:ss"를 초 단위 정수로 변환하는 헬퍼 함수
int to_seconds(string time_str) {
    int m, s;
    sscanf(time_str.c_str(), "%d:%d", &m, &s);
    return m * 60 + s;
}

// 초 단위 정수를 "mm:ss" 문자열로 변환하는 헬퍼 함수
string to_string_time(int total_sec) {
    char buf[6];
    sprintf(buf, "%02d:%02d", total_sec / 60, total_sec % 60);
    return string(buf);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int v_len = to_seconds(video_len);
    int curr = to_seconds(pos);
    int o_start = to_seconds(op_start);
    int o_end = to_seconds(op_end);
    
    for (const string& cmd : commands) {
        // 오프닝 건너뛰기
        if (curr >= o_start && curr <= o_end) curr = o_end;
        
        if (cmd == "next") {
            curr += 10;
            if (curr > v_len) curr = v_len;
            
        } else {
            curr -= 10;
            if (curr < 0) curr = 0;
        }
        
        // 오프닝 건너뛰기
        if (curr >= o_start && curr <= o_end) curr = o_end;
    }
    
    answer = to_string_time(curr);
    
    return answer;
}