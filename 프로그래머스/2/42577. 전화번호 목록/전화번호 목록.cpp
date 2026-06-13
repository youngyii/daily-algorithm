#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++) {
        string findNum = phone_book[i];
        string otherNum = phone_book[i + 1];
            
        hash<string> h;
            
        string tempNum = otherNum.substr(0, findNum.size());
        if (h(tempNum) == h(findNum)) {
            if (tempNum == findNum) 
                return false;
        }
    }
    
    return answer;
}