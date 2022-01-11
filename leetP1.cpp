#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 
#include <algorithm>
using namespace std;
class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rind;
        int res = 0;     //allocate the value first will speed it up? 
        unordered_map<int, int> umapt;
        for (int i = 0; i < (nums.size()); i++) {
            res = target - nums[i];
            if (umapt.count(res) == 0) {
                umapt[nums[i]] = i;
            }
            else
            {
                rind.insert(rind.end(), { i,umapt[res] });   //umapt[res] is faster than umapt.at(res).
            }
        }
        return rind;
        }
        
//use the unordered_map(hashtable) to speed up the code. The complexity is O(n).  
//Runtime: 27 ms, faster than 43.82%  
//Memory Usage: 12.1 MB, less than 11.96% 
//The speed is fair but the memory is not that good.
//        int res;
//       unordered_map<int, int> umapt;
//        for (int i = 0; i < (nums.size()); i++) {
//            res = target - nums[i];
//            if (umapt.count(res) == 0) {
//                umapt[nums[i]] = i;
//            }
//            else
//            {
//                rind.insert(rind.end(), { i,umapt.at(res) });
//            }
//        }
 //This is the brute force method that has complexity O(n^2)    
 //       for(int i = 0;i<(nums.size()-1);i++){
 //          for(int j =i+1;j<nums.size();j++){
 //             if(nums[i]+nums[j]==target) 
 //                  rind.insert(rind.end(),{i,j});
 //                   return rind;                
        
 //         }
 //      } 

 //      return rind;
 //   }

    void print(vector <int> const &a) {
    cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++)
    cout << a.at(i) << ' ';
    }
};

int main(){

    Solution solution;
    vector<int> numbers = {2,7,11,15};
    int target  = 9;
    vector<int> indexn;
    indexn  =   solution.twoSum(numbers,target);
    solution.print(indexn);

}