#include <iostream>
using namespace std;

int main(void)
{
    string test = "0";
    cout<<test.size()<<endl;
    test.insert(0, " ");
    cout<<test<<endl;
    return (0);
}