#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    std::cout << "I am the parent process" << std::endl;

    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();

        if (pid == 0) { // child i
            std::cout << "I am the child process " << i << std::endl;

            // Child 1 creates 1 grandchild
            if (i == 1) {
                pid_t gpid = fork();
                if (gpid == 0) { // grandchild of child 1
                    std::cout << "I am a grandchild process from child process 1" << std::endl;
                    _exit(0);
                } else {
                    wait(NULL); // child 1 waits for its grandchild
                }
            }

            // Child 3 creates 3 grandchildren
            if (i == 3) {
                for (int k = 0; k < 3; k++) {
                    pid_t gpid = fork();
                    if (gpid == 0) { // grandchild of child 3
                        std::cout << "I am a grandchild process from child process 3" << std::endl;
                        _exit(0);
                    } else {
                        wait(NULL); // child 3 waits each grandchild to keep order
                    }
                }
            }

            _exit(0); // child exits so it doesn't keep looping
        } else {
            wait(NULL); // parent waits to guarantee ordered output
        }
    }

    return 0;
}