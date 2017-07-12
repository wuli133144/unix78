

#include"../inc/common.h"

#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<errno.h>
#include<signal.h>


/*@getpgrp start@*/
pid_t Getpgrp(void){
    
    int pid;
    if((pid=getpgrp())<0){
        err_exit("getpgrp failed!");
    }
    return pid;
}

/*@Setpgrp start@*/
   
   void Setpgid(pid_t pid,pid_t pgid){
          int ret;
          if((ret=setgpid(pid,pgid))==-1){
              err_exit("setpgrp failed!");
          }
        return ret;
   }
/*@Setpgrp end@*/




/*@main start@*/
int main(int argc,char **argv){

   
     int pid=getpid();//获取进程id

     fprintf(stdout,"proc pid=%d\n",getpid()); 

     Setpgid(pid,pid);//设置当前进程id为组进程id 当前进程为组长
     fprintf(stdout,"pgrp=%d\n",Getpgrp());    

    //fork child proc
        int fd;
        fd=Fork(); 
  



    return 0;
}
/*@main end@*/