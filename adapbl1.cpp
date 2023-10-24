
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
 
#define EMPTY_STRING ""
 

 
int main()
{
    char str[100];
    cout<< "Enter the string";
    cout<<"\n";
    cin>>str;

    build(str);
 
    return 0;
}