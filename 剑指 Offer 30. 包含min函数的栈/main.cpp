#include"Solution.h"
#include"iostream"

int main()
{
    MinStack m;
    m.push(0);
    m.push(1);
    m.push(0);
    cout<<m.min()<<endl;
    m.pop();
    cout<<m.min()<<endl;

    
}