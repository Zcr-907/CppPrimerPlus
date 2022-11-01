#include <unistd.h>
#include <cstdio>
#include <stdlib.h>

/**
 * 异常控制流:
 *  异步 中断 来自IO设备,并不是程序导致的异常(网络设备请求到达)
 *  同步 陷阱 0X80,系统调用陷入内核
 *  同步 故障 程序执行指令导致的异常(存在修复可能),比如缺页异常(第一次获取数据时数据未存在页表中,加载之后继续执行当前指令)
 *  同步 终止 程序遇到不可修复的错误,或者硬件错误
 * @return
 */
int main() {
    /**
     * fork(): 一次调用两次返回
     *      返回给父进程: 子进程的PID
     *      返回给子进程: 0
     * int x=1: 父子进程拥有在fork前x=1的值
     *          在这之后父子进程各自对x的修改不会影响到对方的数据副本
     *          通过copy_on_write: 直到其中一方修改数据之前,读取的都是一个副本的数据,发生写操作时,才进行虚拟内存复制
     *          这个写时复制并不是在同一个虚拟内存地址上进行空间拓展,而是先开拓子进程的虚拟内存空间,然后各自在自己的虚拟内存上读写
     *          对于虚拟内存地址,内存地址看起来是相同的,因为并不是实际的物理内存地址
     *          所以输出如下
     *              parent : x=0
     *              child  : x=2
     * sleep(1): 防止当前main线程过早消亡,然后child被init线程托管
     * _exit(0): 终止进程
     */
    pid_t fork_id = fork();
    int x = 1;
    if (fork_id == 0) {
        pid_t pid = getpid();
        pid_t ppid = getppid();
        printf("[child]  fork_id = %d, pid = %d,  ppid = %d, x = %d \n", fork_id, pid, ppid, ++x);
        _exit(0);
    }
    pid_t pid = getpid();
    sleep(1);
    printf("[parent] fork_id = %d, pid = %d,  x = %d \n", fork_id, pid, --x);
}

