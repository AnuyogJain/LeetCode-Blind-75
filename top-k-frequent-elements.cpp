class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> ans;
        
        for (int it: nums) {
            m[it]++;
        }
        
        //adding elements to bucket, bucket[i] = vector of all elements of count i
        for (auto it: m) {
            bucket[it.second].push_back(it.first);
        }
        
        for (int i = bucket.size() - 1; i >= 0; i--) {
            if (ans.size() >= k)
                break;
            
            //inserting all bucket elements to ans
            if (!bucket[i].empty()) {
                ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        
        return ans;
    }
};
