//https://www.jianshu.com/p/511cd8d73599
//gcc letest.c -o lt -levent -L/usr/local/lib -I/usr/local/include
#include <stdlib.h>  
#include <stdio.h>   
#include <unistd.h>
#include <event2/event.h>  

void onRead(evutil_socket_t fd, short event, void *arg)  { 
    char buf[BUFSIZ];
    read(fd,buf,BUFSIZ);
    printf("%s\n",buf);  
}   
      
int main()  {   
    // 初始化反应器   
    struct event_base* pBase = event_base_new();   

    // 创建事件  
    struct event* pEvent = NULL;
    pEvent = event_new(pBase,STDIN_FILENO,EV_READ,onRead,NULL);

    // 添加事件   
    event_add(pEvent,NULL);   
      
    // 事件循环   
    event_base_dispatch(pBase);   

    // 释放事件
    event_free(pEvent);

    // 释放反应器
    event_base_free(pBase);      
    return 0;   
}