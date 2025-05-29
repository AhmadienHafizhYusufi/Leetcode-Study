#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string operation : operations){
                if(operation=="+"){
                    int top = st.top();
                    st.pop();
                    int topButOne = st.top();
                    //st.push(topButOne);
                    st.push(top);
                    st.push(topButOne + top);
                }
                else if(operation=="D"){
                    st.push(st.top()*2);
                }
                else if(operation=="C"){
                    st.pop();
                }        
                else{
                    st.push(stoi(operation));
                }   
        }
        int ans =0;
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        return ans;
    }   
};