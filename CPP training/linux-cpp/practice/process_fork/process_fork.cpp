/*
In Linux, a zombie process (also called a defunct process) is a child process that has finished execution 
but its parent process hasn't yet read its exit status. The child process remains in the process table as a zombie
until the parent process retrieves its exit status using the wait system call.
*/


#include <iostream>
#include <unistd.h> // For fork() and getpid()
#include<sys/wait.h>

//#define RUN_EXEC_IN_THE_CHILD_PROCESS   //Run executable of the file process2.cpp(prcs2.exe) in the child process as a seperate process.

int main()
{
  pid_t pid = fork();

  if (pid < 0)
  {
    std::cerr << "Fork failed" << std::endl;
    return 1;
  }
  else if (pid == 0)
  {
    // Child process
    std::cout << "Child process: PID = " << getpid() << std::endl;

#ifdef RUN_EXEC_IN_THE_CHILD_PROCESS

    char *args[] = {(char *)"prcs2", (char *)"", (char *)"", NULL};
    execv(args[0], args);                               // executing prcs2.exe (process2.cpp)within the same folder
    std::cout << "execvp returns failure" << std::endl; /*Will not called. any lines of code written after the execvp() function
                                                         would not be executed after successful execution.*/
#else
    exit(0);
#endif
  }
  else
  {
    // Parent process
    std::cout << "Parent process: PID = " << getpid() << ", Child PID = " << pid << std::endl;
    sleep(10); /*sleeping for 20 seconds(sleep(20)). child process will act as a zombie process since child process completed its 
    execution and parent process still sleeping(not read the return status of child process).*/
    int x = wait(0);  //reading the exit status of child process . Child process will terminate(Not a Zombie).
    std::cout << "x=" << x << std::endl;
  }


  //   pid_t pid2 = fork();
  //   if (pid2 < 0) {
  //     std::cerr << "pid2-Fork failed" << std::endl;
  //     return 1;
  //   } else if (pid2 == 0) {
  //     // Child process
  //     std::cout << "pid2 Child process: PID = " << getpid() << std::endl;
  //   } else {
  //     // Parent process
  //     std::cout << "pid2 Parent process: PID = " << getpid() << ", Child PID2 = " << pid2 << std::endl;
  //   }

  return 0;
}