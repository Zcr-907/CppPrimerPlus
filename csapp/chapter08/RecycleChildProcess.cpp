#include <stdlib.h>
#include <unistd.h>
#include <cstdio>

int main() {
    int status;
    pid_t fork_pid = fork();
    if (fork_pid == 0) {
        printf("[child] pid = %d\n", getpid());
        _exit(2);
    }
    /**
     * arg1: pid ＞ 0,那么等待集合就是一个单独的子进程，它的进程ID等于pid
     *       pid = -1,那么等待集合就是由父进程所有的子进程组成的
     *
     * arg2: 对应终止进程的相关状态信息,见CSAPP
     *
     * arg3: WNOHANG > 如果等待集合中的任何子进程都还没有终止,那么就立即返回0
     *                 如果pid进程已经终止,返回pid
     *       WUNTRACED > 阻塞等待 等待集合中至少一个进程变成已终止或已停止
     *       WCONTINUED > TODO: 与 WUNTRACED有相似之处,但是其他功能还不确定
     */
    pid_t wait_pid = waitpid(fork_pid, &status, WUNTRACED);
    printf("[parent] wait_pid = %d\n", wait_pid);

    // 如果wait_pid是_exit或者正常return结束的则为true
    printf("[parent] WIFEXITED = %d\n", WIFEXITED(status));

    // 返回一个正常终止的子进程的退出状态。只有在WIFEXITED()返回为真时,才会定义这个状态
    printf("[parent] WEXITSTATUS  = %d\n", WEXITSTATUS (status));

}
