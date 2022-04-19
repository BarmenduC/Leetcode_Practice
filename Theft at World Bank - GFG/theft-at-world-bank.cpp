// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	struct items{

        long long w,p,square_root;

        long double profit_by_weight;

    };

    bool static compare(items item1,items item2){

        if(item1.profit_by_weight!=item2.profit_by_weight){

            return item1.profit_by_weight>item2.profit_by_weight;

        }

        else if(item1.w!=item2.w){

            return item1.w>item2.w;

        }

        else if(item1.p!=item2.p){

            return item1.p>item2.p;

        }

        else{

            return item1.square_root>item2.square_root;

        }

    }

    long double maximumProfit(int n, long long c, vector<long long> w, vector<long long> p){

        vector<items> item(n);

        for(int i=0;i<n;i++){

            item[i].w=w[i];

            item[i].p=p[i];

            item[i].profit_by_weight=((long double)p[i])/w[i];

        }


 

        for(int i=0;i<n;i++){

            item[i].square_root=sqrt(w[i]);

        }

 

        long double sum=0;

        sort(item.begin(),item.end(),compare);

        for(int i=0;i<n;i++){

            if(item[i].square_root*item[i].square_root!=item[i].w){

                if(c>=item[i].w){

                    c=c-item[i].w;

                    sum+=item[i].p;

                }

                else{

                    sum+=item[i].profit_by_weight*c;

                    c=0;

                    break;

                }

            }

        }

        return sum;

    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends