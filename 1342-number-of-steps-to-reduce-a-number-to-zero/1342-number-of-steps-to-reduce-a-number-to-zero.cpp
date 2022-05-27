class Solution {
private:
    int actions = 0;
public:
    int numberOfSteps(int& num) {
        step(num);
        return actions;
    }
    void step(int& num){
        if(num == 0){
            return;
        }
        if(num%2 == 0){
            num /= 2;
            actions++;
            step(num);
        }else{
            num--;
            actions++;
            step(num);
        }
    }
};