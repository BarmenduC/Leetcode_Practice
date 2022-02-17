class Solution {
public:
    void recursive(vector < int > & candidates, int target, set < vector < int >> & path, vector < int > & curr) {
  if (target == 0) {
    vector < int > temp = curr;
    sort(temp.begin(), temp.end());

    if (path.count(temp) == 0)
      path.insert(temp);

    return;
  }

  if (target < 0)
    return;

  for (int i = 0; i < candidates.size(); ++i) {
    curr.push_back(candidates[i]);
    recursive(candidates, target - candidates[i], path, curr);
    curr.pop_back();
  }
}

vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
  set < vector < int >> path;
  vector < int > curr;

  recursive(candidates, target, path, curr);

  vector < vector < int >> ans;

  for (auto a: path)
    ans.push_back(a);

  return ans;
}
};