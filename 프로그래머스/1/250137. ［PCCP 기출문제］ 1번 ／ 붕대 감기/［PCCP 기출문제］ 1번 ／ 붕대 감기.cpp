#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int last_atk = attacks.size();
    int maxtime = attacks[last_atk - 1][0];
    int seqheal = 0;
    int atk = 0;
    int heart = health;
    
    for(int i = 1; i <= maxtime; i++){
        if(attacks[atk][0] == i){
            heart -=attacks[atk][1];
            seqheal = 0;
            atk++;
            if(heart <= 0) return -1;
        }else {
            seqheal++;
            heart += bandage[1];
            if(seqheal == bandage[0]){
                heart += bandage[2];
                seqheal = 0;
            }
            if(heart > health) heart = health;
        }
    }
    return heart;
}