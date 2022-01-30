#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int pi = 0;
        int pf = nums.size()-1;
        return BinarySearch(nums,pi,pf,target);

        
    }

    int BinarySearch(vector<int>& nums, int pi, int pf, int target){
        int ptemp;
        if(pi<=pf){
            ptemp = (pi+pf)/2;
            if (target<nums[ptemp])
            {

                return BinarySearch(nums,pi,ptemp-1,target);
            }
            else if(target>nums[ptemp]){

                return BinarySearch(nums,ptemp+1,pf,target);
            }
            else{
                return ptemp;
            }
        }
        return pi;
    }
};

int main(){
    vector<int> nums = {1,3,5,6};
    Solution solution;
    solution.searchInsert(nums,5);
    cout<<solution.searchInsert(nums,5)<<endl;
};