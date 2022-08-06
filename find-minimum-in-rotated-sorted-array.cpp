class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            //element must be less than both of its neighbouring elements
            if ((mid - 1 < 0 || nums[mid] < nums[mid - 1]) && (mid + 1 >= nums.size() || nums[mid] < nums[mid + 1]))
                return nums[mid];
            
            //if left side is sorted
            else if (nums[low] <= nums[mid]) {
                //shift to smaller side
                if (nums[low] > nums[high])
                    low = mid + 1;
                else 
                    high = mid - 1;
            }
            
            //if right side is sorted
            else {
                //shift ot smaller side
                if (nums[high] > nums[low])
                    low = mid + 1;
                else 
                    high = mid - 1;
            }
        }
        
        return -1;
    }
};
