class Solution {
public:
    int maxProduct(vector<string>& words) {
int h1[26];
for(int i=0;i<26;i++){
    h1[i]=0;
}
    int ans=0;
for(int i=0;i<words.size();i++){
 for(int k=0;k<words[i].size();k++){
    h1[words[i][k]-'a']++;
}   

for(int j=i+1;j<words.size();j++){
     bool bo=true;
    for(int k=0;k<words[j].size()&&bo==true;k++){
    if(h1[words[j][k]-'a']){
        bo=false;
    }
    } 

    if(bo==true){
        int temp=(words[i].length())*(words[j].length());
        ans=max(ans,temp);
    }
}
 for(int v=0;v<26;v++){
    h1[v]=0;
}
   
}
return ans;
}
};
