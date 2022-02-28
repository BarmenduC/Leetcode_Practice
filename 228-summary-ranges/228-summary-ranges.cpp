class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums)
{
    string res = "";
    vector<string> range;
    int start = 0, end = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (start == nums.size() - 1)
        {
            res = to_string(nums[i]);
            range.push_back(res);
            return range;
        }
        if (i == nums.size() - 1 || nums[i + 1] != nums[i] + 1)
        {
            end = i;
            if (start == end)
            {
                res = to_string(nums[i]);
                range.push_back(res);
            }
            else
            {
                res = to_string(nums[start]) + "->" + to_string(nums[end]);
                range.push_back(res);
            }
            start = i + 1;
            res = "";
        }
    }
    return range;
}
};