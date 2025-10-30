#include<iostream>
#include<stack>

int main()
{
    std::string st="abcdefghijk";
    std::stack<char> stk;
    for(auto i:st)
    {
        stk.push(i);
    }
    st.clear();
    while(!stk.empty())
    {
        st.push_back(stk.top());
        stk.pop();
    }
    std::cout<<st;
    return 0;
}