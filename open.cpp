#include<iostream>
#include<string>
#include<map>
using namespace std;
extern map<string,string> m;
int put(string key, string value, int nbytes){
    if(key.size()>20 || value.size()>99){cout<<"Size is too Large!!"<<endl; return 1;}
    m.insert(make_pair(key,value));
    return 0;
}