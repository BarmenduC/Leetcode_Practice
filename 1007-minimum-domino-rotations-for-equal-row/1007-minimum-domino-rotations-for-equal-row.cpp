class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> doms {tops[0], bottoms[0]}; // need to check for these 2 dominos only
        for (int i=0; i<2; i++) {
            int d = doms[i]; // this is the domino we will check for missing count in top and bottom
            int topM = 0; int bottomM = 0;
            for (int j=0; j<tops.size(); j++) {
                if (tops[j] != d && bottoms[j] != d) { // both dominos does not contain the domino we are checking
                    break;
                }
                if (tops[j] != d) { topM++; } // missing in top
                if (bottoms[j] != d) { bottomM++; } // missing in bottom
                
                if (j == tops.size()-1) {
                    return min(topM, bottomM);
                }
            }
        }
        return -1;
        
    }
};