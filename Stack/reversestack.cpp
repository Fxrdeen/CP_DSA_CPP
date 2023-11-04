#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){

  if (st.empty()){
    st.push(ele);
    return;
  }

  int top = st.top();
  st.pop();
  insertAtBottom(st, ele);
  st.push(top);
}

void reverse(stack<int> &st){
  
  if (st.empty()){
    return ;
  }

  int el = st.top();
  st.pop();
  reverse(st);
  insertAtBottom(st,el);

}

int main(){
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  reverse(st);
  while(!st.empty()){
    cout << st.top() << ' ';
    st.pop();
  }
}
