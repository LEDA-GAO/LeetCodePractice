#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rind;
        for(int i = 0;i<(nums.size()-1);i++){
           for(int j =i+1;j<nums.size();j++){
              if(nums[i]+nums[j]==target) 
                   rind.insert(rind.end(),{i,j});
                    return rind;                
        
          }
       } 
       return rind;
    }

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