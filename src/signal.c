


#include "../inc/common.h"

typedef  void sig_handle(int);

/*@signal version 0.1@*/

  sig_handle *Signal(int sig,sig_handle *handle){
          
          if((signal(sig,handle))==SIG_ERR){
              err_exit("signal error!");
          }
  }

/*@signal end@*/



/*@handler func@*/
 
 void handler1(int dt){
      printf("handle1 usr1 msg=%d\n",dt);
      return;
 }

 void handler2(int dt){
      printf("handle2 usr2 msg=%d\n",dt);
      return;
 }


/*@handler end@*/

void hand1(int sig){
    printf("hello world!\n");
    return;
}


/*@sigemptyset start@*/
#define sigemptyset(ptr) ( *(ptr) = 0)

//nx express
#define sigfillset(ptr) ( *(ptr) = ˜(sigset_t)0, 0 )

/*@sigfillset end@*/

int main(){

  #if 0//测试成功
     Signal(SIG_USR1,handler1);
     Signal(SIG_USR2,handler2);
     
     for(EVER)
       pause();
  #endif
  #if 0
    
    for(EVER){
        sleep(1);
      //  printf(stdout,"%s \n","hello world!");
        Signal(SIGINT,hand1);
    }


  #endif
    return 0;
}