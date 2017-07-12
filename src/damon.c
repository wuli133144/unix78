

#include"../inc/common.h"
#include<fcntl.h>


int daemon_proc(){
   
   pid_t pid;
   pid=Fork();
   if(pid!=0){
       exit(0);
   }
   setsid();//become session leader
   chdir("/");
   umask(0);
    
    return 0;
}



int main(){
    
    daemon_proc(); 
   
    return 0;
}