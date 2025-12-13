class Solution {
private: 
    bool isValidCode(const string &s){
        if(s.empty()) return false;
        for(char c: s){
            if(!isalnum(c) && c != '_'){    // alphanumeric character --> a-z, A-Z, 0-9
                return false;
            }
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        unordered_map<string, int> blso = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> valid;

        for(int i=0; i<n; i++){        // if both return true --> it means exist in blso
            if(isActive[i] && blso.count(businessLine[i]) && isValidCode(code[i])) {
                valid.push_back({blso[businessLine[i]], code[i] });
            }
        }

        sort(valid.begin(), valid.end());

        vector<string> result;

        for(auto &s : valid){
            result.push_back(s.second);
        }

        return result;
    }
};