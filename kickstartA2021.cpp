#include </Users/bits/stdc++.h>
using namespace std;

int flag = 1;

int find_palindromes_in_sub_string(const string& input, int j, int k) {
  int count = 0;
  for (; j >= 0 && k < input.length(); --j, ++k) {
    if (input[j] != input[k] && input[j]!='?' && input[k]!='?') {
      break;
    } 
    if(input.substr(j, k - j + 1).length() < 5)
        continue;
    ++count;
  }
  return count;
}

int find_all_palindrome_substrings(const string& input) {
  int count = 0;
  for (int i = 0; i < input.length(); ++i) {    
    count += find_palindromes_in_sub_string(input, i - 1, i + 1);
    count += find_palindromes_in_sub_string(input, i, i + 1);
  }
  return count;
}

void calc(string s,int x){
    if(x==s.length()){
        if (find_all_palindrome_substrings(s)==0)
            flag = 0;
        return;
    }
    if(s[x]=='0' || s[x]=='1'){
        calc(s,x+1);
        return;
    }
    calc(s.substr(0,x) + "0" + s.substr(x+1),x+1);
    calc(s.substr(0,x) + "1" + s.substr(x+1),x+1);
}

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        flag = 1;
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]!='?')
                continue;
            int c1 = find_all_palindrome_substrings(s.substr(0,i)+"0"+s.substr(i+1));
            int c2 = find_all_palindrome_substrings(s.substr(0,i)+"1"+s.substr(i+1));
            if(c1<c2)
                s = s.substr(0,i)+"0"+s.substr(i+1);
            else
                s = s.substr(0,i)+"1"+s.substr(i+1);
        }
        int count = find_all_palindrome_substrings(s);
        cout<<"Case #"<<cas<<": ";
        if(count>0)
            cout<<"IMPOSSIBLE\n";
        else
            cout<<"POSSIBLE\n";
    }
}

/*

100???001
101100101

*/