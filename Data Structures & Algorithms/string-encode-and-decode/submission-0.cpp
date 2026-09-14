class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs.size();i++){
            string a=strs[i];
            string x="";
            for(int j=0;j<a.length();j++){
                x+=to_string(a[j]-'a');
                x+="|";
            }
            x+="@";
            ans+=x;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string x="";
        string y="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='@'){
                ans.push_back(x);
                x="";
            }
            else if(s[i]=='|'){
                x+=stoi(y)+'a';
                y="";
            }
            else{
                y+=s[i];
            }
        }
        return ans;
    }
};
