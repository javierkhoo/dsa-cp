// LeetCode 1807 : Evaluate the Bracket Pairs of a String
// Problem Link  : https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

// Approach 1
// T.C : O(m + n)
// S.C : O(m + n)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        
        unordered_map<string, string> mp;
        for(auto& vec : knowledge) {
            mp[vec[0]] = vec[1];
        }

        string result;
        int i = 0;

        while(i < n) {
            if(isalpha(s[i])) {
                result.push_back(s[i]);
            } else if(s[i] == '(') {
                i++;
                string key;
                while(i < n && s[i] != ')') {
                    key += s[i];
                    i++;
                }
                result += (mp.count(key)) ? mp[key] : "?";
            }
            i++;
        }

        return result;
    }
};

// Approach 2 (using boolean flag)
// T.C : O(m + n)
// S.C : O(m + n)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        
        unordered_map<string, string> mp;
        for(auto& vec : knowledge) {
            mp[vec[0]] = vec[1];
        }

        string result;
        string key;
        bool bracketOpened = false;
        int i = 0;
        
        while(i < n) {
            if(s[i] == '(') {
                bracketOpened = true;
            } else if(s[i] == ')') {
                bracketOpened = false;
                result += (mp.count(key)) ? mp[key] : "?";
                key = "";
            } else if(bracketOpened) {
                key += s[i];
            } else {
                result += s[i];
            }
            i++;
        }

        return result;
    }
};

// Approach 3 (using std::find(), cleanest code)
// T.C : O(m + n)
// S.C : O(m + n)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        
        unordered_map<string, string> mp;
        for(auto& vec : knowledge) {
            mp[vec[0]] = vec[1];
        }

        string result;
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                int j = s.find(')', i+1);
                string key = s.substr(i+1, j-i-1);
                result += (mp.count(key)) ? mp[key] : "?";
                i = j;
            } else {
                result.push_back(s[i]);
            }
            i++;
        }

        return result;
    }
};
