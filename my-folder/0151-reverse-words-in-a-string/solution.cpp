class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        for(int i=0;i<s.length();i++){
            string word = "";
            while(s[i]!=' '&& i<s.length()){
                word+=s[i];
                i++;
            }
             // Push the word onto the stack if it's not empty
            if (!word.empty()) {
                st.push(word);
            }
            // Skip spaces
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            // Adjust 'i' so it points to the next character
            i--; // Decrement i since the for loop will increment it
            word = ""; // Reset the word for the next iteration
        }
        string result="";
        while(!st.empty()){
            result+=st.top();
            if(st.size()>1){
                result +=" ";
            }
            st.pop();
        }
        return result;
    }
};
