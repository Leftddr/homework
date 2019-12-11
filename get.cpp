#include<iostream>
#include<string>
#include<map>
using namespace std;
extern map<string,string> m;

string get(string key,int* nbytes){
    if(key.size()>20){cout<<"Key size is too large"<<endl; return "";}
    return m[key];
}