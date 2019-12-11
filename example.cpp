#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,string> m;

int main(){
    string s1="a";
    string s2="a";

    m.insert(make_pair(s1,s2));

    s1="b";
    s2="b";

    m.insert(make_pair(s1,s2));

    cout<<m[s1]<<endl;


}