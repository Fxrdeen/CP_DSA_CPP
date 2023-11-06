#include <iostream>
#include <stack>
using namespace std;

// Code to solve balanced paranthesis problem.

bool balancedParantheses(string s){
  stack<char> st;
  for(int i=0;i<s.size();i++){
    if (s[i]=='(' || s[i]=='{' || s[i]=='['){
      st.push(s[i]);
    } else if (s[i]==')' || s[i]=='}' || s[i]==']'){
      if (!st.empty()){
        if (st.top()=='(' and s[i]!=')')
          return false;
        else if (st.top()=='{' and s[i]!='}')
          return false;
        else if (st.top()=='[' and s[i]!=']')
          return false;
        else st.pop();
      }
    }
  }
  if (!st.empty())
    return false;
  return true;
}


int main(){
  cout << balancedParantheses("{([])") << endl;
}
