class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, n = people.size();
		int i = 0, j = n-1;
        sort(people.begin(), people.end());
        
        while (i < j) {
            // decide if there are two people in this boat
            if (people[i] + people[j] <= limit) {
                i++;
            }
            
            res++;
            j--;
        }
        
        return (i == j) ? 1+res : res;
    }
};