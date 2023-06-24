#include <iostream>
using namespace std;

#include "thirdlib/log/tlog.h"

int main()
{
    cout<<"hello world"<<endl;
    tlog_init("broker.log",1024*1024,10,0,TLOG_SCREEN);
    
    return 0;
}