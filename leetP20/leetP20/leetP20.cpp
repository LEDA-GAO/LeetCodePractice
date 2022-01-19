// leetP20.cpp : 

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        string temp;


        for (int i = 0; i < s.length(); i++) {
            if (parlr(s[i]) == 0) {
                temp.push_back(s[i]);
            }
            else {
                if (temp.length() == 0) return false;
                int j = temp.length() - 1;
                if (findpar(temp[j]) == s[i]) {
                    temp.pop_back();
                }
                else {
                    return false;
                }
            }
        }

        if (temp.length() > 0) {
            return false;
        }

        return true;



    }

    char findpar(char par) {
        switch (par) {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        };
        return 0;
    }

    int parlr(char par) {
        switch (par) {
        case '(': case '[': case '{':
            return 0;
        case ']': case '}': case ')':
            return 1;
        };

        return false;
    }

};






int main()
{
    string s = "({";
    Solution solution;
    cout << solution.isValid(s) << endl;

}


