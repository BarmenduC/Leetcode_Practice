// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {

//creating a vector arr and copying all elements of array a.

vector<int> arr(a,a+n);

//converting all elements to negative in order to sort the array later.
for(int i=0;i<n;i++){
   arr[i]=-arr[i];
}

//sorting the array.

sort(arr.begin(), arr.end());

//converting all elements back to positive.

for(int i=0;i<n;i++){
   arr[i]=-arr[i];
}

int j=0;
for(int i=0;i<n;i=i+2){
   a[i]=arr[j];
   j++;
}

//inserting smallest elements in the even positions in the answer array.
j=n-1;
for(int i=1;i<n;i=i+2){
   a[i]=arr[j];
   j--;
}

//copying all  elements of answer array to vector array and checking if at any instance sum is 0 or less than 0.
vector<int> brr(a,a+n);
int sum=0;
for(int i=1;i<n;i=i+2){
   sum+=brr[i-1]-brr[i];

//if sum is less than 0 or 0 then first element of answer array will be 0 and the size of answer array will be 1 only. (Refer to driver code for this). This step is taken so that if sum becomes zero or less the compiler will output not possible.
if(sum<=0){
   brr[0]=-1;
   for(int i=1;i<n;i++){
       brr.pop_back();
   }
}
}
return brr;
}