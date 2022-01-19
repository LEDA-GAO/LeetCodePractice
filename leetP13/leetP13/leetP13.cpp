// leetP13.cpp : 
//

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, short int> umap = { {'I',1}, {'V',5},
    {'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
        int sum = 0;
        int nexts = umap[s[0]];
        if (s.size() > 1) {
            for (size_t i = 0, ilen = s.size() - 1; i < ilen; i++) {
                int currents = umap[s[i]];
                nexts = umap[s[i + 1]];
                if (currents >= nexts) {
                    sum += currents;

                }
                else {
                    sum -= currents;
                }
            }
            sum += nexts;
        }
        else {
            sum += nexts;
        }


        return sum;

    }
};

int main()
{
    string test = "MCMXCIV";
    Solution solution;
    cout << solution.romanToInt(test) << endl;
}


