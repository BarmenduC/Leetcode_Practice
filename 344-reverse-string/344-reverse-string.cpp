class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int front = 0; //walk front forward from first index
        int back = s.size()-1; //walk back backward from last index
        while(front < back){ //if front == back, there is no need to swap, and going past this point will just undo earlier swaps
            if(!(s[front] == s[back])){
                temp = s[front]; //use temp to support the swap
                s[front] = s[back];
                s[back] = temp;
                }
            front++; //step forward
            back--;   //step backward
        }
        return;
    }
};