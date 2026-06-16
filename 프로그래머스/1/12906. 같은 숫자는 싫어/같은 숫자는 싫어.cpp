#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    stack<int> st;
    
    for (auto num : arr) st.push(num);
    
    int prev = -1;
    while (!st.empty()) {
		if (prev != st.top()) answer.push_back(st.top());
        prev = st.top();
        st.pop();
	}
    
    reverse(answer.begin(), answer.end());
    return answer;
}