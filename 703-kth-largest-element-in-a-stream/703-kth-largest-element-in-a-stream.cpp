class KthLargest {
public:
	priority_queue<int, vector<int>, greater<int>> pq;
	int SIZE;
	KthLargest(int k, vector<int>& nums) {
		for(auto& i : nums) {
			pq.push(i);
			if(pq.size() > k) pq.pop();
		}
		SIZE = k;
	}

	int add(int val) {
		pq.push(val);
		if(pq.size() > SIZE) pq.pop();
		return pq.top();
	}
};