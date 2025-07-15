class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3){
            return false;
        }

        bool vowel = false , cons = false;
        
        for(int i=0; i<word.length(); i++){

            //check whether a given character is alphanumeric
            if(!isalnum(word[i])){
                return false;
            }

             //is used to check whether a given character is an alphabetic letter (either uppercase or lowercase)
            if(isalpha(word[i])){
                // change ch to lowercase letter
                char ch = tolower(word[i]);

                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    vowel = true;
                } else {
                    cons = true;
                }

            }
        }
        return vowel && cons;
    }
};