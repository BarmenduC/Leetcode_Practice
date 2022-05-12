class Solution {
public:
    void dfs_unique(int &size, unordered_map<int, int> &hash_map, vector<vector<int>> &ans, vector<int> &perm)
    {
        if (perm.size() >= size) // when size of temperory vector is equals to the size of given number
        {                        // of elements in problem, means one permutation is ready
            ans.push_back(perm);
            return;
        }

        // never forget to take reference of elements in case of updating them
        for (auto &h : hash_map)
        {
            if (h.second > 0)
            {
                perm.push_back(h.first); // push the elements one by one in temperory vector
                // std::cout << h.first << "<= Org " << h.second << std::endl;
                h.second = h.second - 1; // also decrement the qty of elements
                // std::cout << h.first << "<= Dec " << h.second << std::endl;
                dfs_unique(size, hash_map, ans, perm);
                h.second = h.second + 1; // after creating one permutatin increment it
                // std::cout << h.first << "<= Inc " << h.second << std::endl;
                perm.pop_back(); // and remove the element form temperory vector, so that
                                 // in next iteration new permutation will be generated
            }
        }
    }

vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        unordered_map<int, int> hash_map = {};
        // creating hash map for tracking duplicates of same elements
        for (auto n : nums)
            if (hash_map.count(n) >= 1) // if element is present in hash map, increment the qty
                hash_map.find(n)->second++;
            else
                hash_map.emplace(make_pair(n, 1)); // if not present, add it in hash map
        // PrintHashMap(hash_map);              // debuging function
        vector<vector<int>> ans = {};          // answer varaible
        vector<int> perm = {};                 // temperory permution variable
        int size = nums.size();                // qty of the required element in one permutation
        dfs_unique(size, hash_map, ans, perm); // backtracking for solution
        return ans;                            // return found solution
    }
};