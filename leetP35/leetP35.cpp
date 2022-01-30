#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int pi = 0;
        int pf = nums.size()-1;
        int ptemp = (pi+pf)/2;
        if(target <= nums[pi]){
            return 0;
        }
        else if(target >= nums[pf]){
            return pf+1;
        }

        while((pf-pi)>1){
            if(target<nums[ptemp]){
                pf = ptemp;
                ptemp = (pi+pf)/2;

            }
            else if(target == nums[ptemp]){
                return ptemp;
            }
            else{
                pi = ptemp;
                ptemp = (pi+pf)/2;

            }
        }
        return pf;
        
    }

};

int main(){
    vector<int> nums = {2,4,7,9,10};
    Solution solution;
    cout<<solution.searchInsert(nums,9)<<endl;
};