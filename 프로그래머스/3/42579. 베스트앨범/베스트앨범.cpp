#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 장르 정렬 (총 재생횟수 내림차순)
bool gcmp(const pair<string,long>& a, const pair<string,long>& b) {
	return a.second > b.second;
}

// 노래 정렬 (재생횟수 내림차순)
bool pcmp(const pair<int,long>& a, const pair<int,long>& b) {
    if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string,long> gmap; // key: 장르, value: 총 재생횟수
    unordered_map<string,vector<pair<int,long>>> pmap; // key: 장르, value: {고유번호, 재생횟수}
    
    for (int i = 0; i < genres.size(); i++) {
        gmap[genres[i]] += plays[i]; // 장르별 재생 횟수 누적
        pmap[genres[i]].push_back(make_pair(i, plays[i]));
    }
    
    // 장르 정렬
    vector<pair<string, long>> gvec(gmap.begin(), gmap.end());
	sort(gvec.begin(), gvec.end(), gcmp);

    // 장르별 노래 정렬
    for (int i = 0; i < gvec.size(); i++) {
        string genre = gvec[i].first;
        vector<pair<int,long>> pvec(pmap[genre].begin(), pmap[genre].end());
        sort(pvec.begin(), pvec.end(), pcmp);
        
        if (pvec.size() == 1) answer.push_back(pvec[0].first);
        else {
            answer.push_back(pvec[0].first);
            answer.push_back(pvec[1].first);
        }
    }
    
    return answer;
}