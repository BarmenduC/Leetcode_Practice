class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> prev;
        int sum = 0;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "+"){
                int val = prev[prev.size()-1] + prev[prev.size()-2];
                sum += val;
                prev.push_back(val);
                }
            else if(ops[i] == "C"){
                sum -= prev[prev.size()-1];
                prev.pop_back();
                }
            else if(ops[i] == "D"){
                int val = prev[prev.size()-1] * 2;
                sum += val;
                prev.push_back(val);
                }
            else{
                sum += stoi(ops[i]);
                prev.push_back(stoi(ops[i]));
                }
        }
        return sum;
    }
};