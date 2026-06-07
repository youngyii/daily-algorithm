#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> player_indices;
        
    for (int i = 0; i < players.size(); i++) {
         player_indices[players[i]] = i;
    }
    
    for (int i = 0; i < callings.size(); i++) {
        int index = player_indices[callings[i]];
        
        player_indices[players[index]]--;
        player_indices[players[index - 1]]++;
        
        swap(players[index], players[index - 1]);
    }
    
    return players;
}