#include<iostream>
#include"kvs.h"
#include<dlfcn.h>

int main(int argc, char *argv[]){
    if(argc<4){cout<<"Input three argv"<<endl;}
    void *handle;
    int (*put)(string,string,int);
    string (*get)(string,int*);
    char *error;

    handle=dlopen("./libmap.so",RTLD_LAZY);
    if(!handle){
        fprintf(stderr,"%s\n",dlerror());
        return 0;
    }

    put=(int(*)(string,string,int))dlsym(handle,"put");
    if((error=dlerror())==NULL){
        fprintf(stderr,"%s\n",error);
        return 0;
    }
    get=(string(*)(string,int*))dlsym(handle,"get");
    if((error=dlerror())==NULL){
        fprintf(stderr,"%s\n",error);
        return 0;
    }

    ifstream in(argv[1]);
    if(!in.is_open()){
        cout<<"Cannot Open file"<<endl;
    }

    char read[128];
    string key="";
    string value="";

    while(!in.eof()){
        in.getline(read,128);
        int len=0;

        for(int i=0;i<strlen(read);i++){
            if(read[i]==' '){len=i;break;}
        }

        for(int i=0;i<len;i++)
            key+=read[i];
        for(int i=len+1;i<strlen(read);i++)
            value+=read[i];
        
        if(put(key,value,20)){
            cout<<"Cannot Input(Size Error)"<<endl;
        }
        key="";
        value="";
    }
    in.close();

    ifstream in2(argv[2]);
    ofstream out(argv[3]);

    if(!in2.is_open()){
        cout<<"Cannot Open file"<<endl;
    }
    if(!out.is_open()){
        cout<<"Cannot Open file"<<endl;
    }

    while(!in2.eof()){
        in2.getline(read,128);
        int len=strlen(read);
        for(int i=0;i<len;i++){
            key+=read[i];
        }
        value=get(key,0);
        out<<value<<endl;
        key="";
    }
    in2.close();
    out.close();

    if(dlclose(handle)<0){
        fprintf(stderr,"%s\n",dlerror());
        return 0;
    }
    return 0;
}