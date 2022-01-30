#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int sizen = needle.length();
        if(needle.empty()){
            return 0;
        }
        if(needle.length()>haystack.length()){
            return -1;
        }
        unordered_map<string, int> umap;
        for(int j = 0;j<=haystack.length()-sizen;j++){
            umap[haystack.substr(j,sizen)] = j;
            if(umap.count(needle) != 0){
            return umap[needle];
            }
            
        }

        return -1;     
                
    }
};

int main(){

    string haystack;
    haystack = "hello";
    string needle = "lo";
    Solution solution;
    int i = solution.strStr(haystack,needle);
    cout<<i<<endl;
}