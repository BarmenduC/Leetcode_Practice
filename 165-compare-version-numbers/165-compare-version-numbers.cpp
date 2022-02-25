class Solution {
public:
    int compareVersion(string v1, string v2) {
	int m=v1.length(),n=v2.length(),i=0,j=0,val1,val2;
	while(i<m or j<n){
		val1=0,val2=0;
		while(i<m and v1[i]!='.'){
			val1=val1*10+(v1[i]-'0');
			i++;
		}
		while(j<n and v2[j]!='.'){
			val2=val2*10+(v2[j]-'0');
			j++;
		}
		if(val1>val2) return 1;
		else if(val1<val2) return -1;
		i++;
		j++;
	}
	return 0;
}
};