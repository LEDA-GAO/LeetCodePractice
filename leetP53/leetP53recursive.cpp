#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
int globalmax;
int globalstart = 0;
int globalend = 0;
int currstart = 0;
int currend = 0;

//    Kadane's Algorithm 
//    int maxSubArray(vector<int> &nums) { 
//        int globalMaxSum = nums[0], currMaxSum = nums[0];
//        for (int ind = 1; ind < nums.size(); ind++) {
//            currMaxSum = max(currMaxSum + nums[ind], nums[ind]);
//            globalMaxSum = max(globalMaxSum, currMaxSum);
//        }
//        return globalMaxSum;
//    }


    int maxSubArray(vector<int>& nums) {
        globalmax = nums[0];
        maxSubArray(nums, nums.size());
        cout<<"globalmax "<<globalmax<<endl;
        cout<<"first index= "<<globalstart<<endl;
        cout<<"second index= "<<globalend<<endl; 
        printArrayPos(nums,globalstart,globalend);  
        return globalmax;

    }
    
    int maxSubArray(vector<int>& nums, int n) {
        int currmax;
        if(n == 1){
            return nums[0]; 
        }
        else{
            if(nums[n-1]>(maxSubArray(nums,n-1)+nums[n-1])){
                currmax = nums[n-1];
                currstart = n-1;
            }
            else{
                currmax = maxSubArray(nums,n-1)+nums[n-1];
                currend = n-1;
            }
            if(globalmax < currmax){
                globalmax = currmax;
                globalstart = currstart;
                globalend =currend;               
            }   
            else if(globalmax == currmax){
                if(globalend-globalstart+1<currend-currstart+1){
                    globalstart = currstart;
                    globalend =currend;                   
                }
            }
            
        }
        return currmax;
    }

    void printArrayPos(vector<int>& nums, int lind, int hind){
        for (size_t i = 0; i < hind-lind+1; i++)            
                cout<<nums[lind+i]<<" ";
            cout<<"\n";        
    }

    
    

};


int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout<<solution.maxSubArray(nums)<<endl;

};