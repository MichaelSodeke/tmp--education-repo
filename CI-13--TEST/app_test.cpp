// [ file: app_test.cpp                ]
// ====================================[ sec-1: primer       ]
// - description  :: ..                :
//     L1: copy this file to [ /CI-12--SRC-TREE/app/src/test/cpp/ ] for
//	   L2: gradle to work.
// -------------------------------------
// - explanation  :: ..                :
//	   L1: the purpose of this program is to test the all features of the [blah.h] class.
//	   L2: ..
// ====================================[ sec-2: import tools ]
	// < >: includes standard library header files
	#include <sys/wait.h>
	#include <sys/utsname.h>
	#include <sched.h>
	#include <string.h>
	#include <stdint.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/mman.h>

	// " ": includes programmer-defined header files
	// #include "../headers/tools.h"
	// #include "../headers/object.h"

	// text macro replacements
	#define errExit(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0);

	// Stack size for cloned child
	#define STACK_SIZE (1024 * 1024)
// ====================================[ sec-3: prototypes   ]
	static int childFunc(const char *arg){
		/* - [ prologue                          ]
        =====================================================================
        GOAL   : ...
        INPUT  : ...
        OUTPUT : ...
        T(n)   : f(n) ∈ Ω(n) | f(n) ∈ Θ(n) | f(n) ∈ Ο(n)
        =====================================================================
        */

        // - [ sec-1: define & assign            ]
	    const char *new_name = "Data Science";
	    char *args[] = {(char *)"/bin/sh", (char *)"--"};
	    struct utsname uts;

	    // - [ sec-2: syntax algorithm           ]
	    // - change hostname in UTS namespace of child.
	    clearenv();

	    if (sethostname(new_name, strlen(new_name)) == -1)
	        errExit("sethostname");

	    // - retrieve and display hostname.
	    if (uname(&uts) == -1)
	        errExit("uname");
	    printf("uts.nodename in child:  %s\n", uts.nodename);

	    // - specify environment variables for the child
	    if (setenv("SYSTEMD_OFFLINE", "0", 1) == -1)
	        errExit("setenv");
	    if (setenv("MANPATH", "/usr/share/man:/usr/local/man", 1) == -1)
	        errExit("setenv");
	    if (setenv("HOSTTYPE", "x86_64", 1) == -1)
	        errExit("setenv");
	    if (setenv("TERM", "xterm-256color", 1) == -1)
	        errExit("setenv");
	    if (setenv("PROMPT", "$'\n%{\x1B[31m%} [ Δ : %i ] [ %m ] [ %{\x1B[6m%} >< %{\x1B[25m%} ]%{\x1B[0m%} '", 1) == -1)
	        errExit("setenv");
	    if (setenv("RPROMPT", "$'[ %C | ${vcs_info_msg_0_} ] [ %D | %T ]'", 1) == -1)
	        errExit("setenv");

	    // - setup new root directory
	    chroot("../dsci");
	    if(chdir("/") == -1)
	        errExit("chroot ../dsci");

	    // - [ sec-3: return value or VOID       ]
	    // - load the [shell] child process, then terminate.
	    return execvp((const char*)arg, args);
	}
// ====================================[ sec-4: main program ]
	int main(int argc, char** argv){
		/* [ prologue                            ]
		=======================================================================================
		GOAL   : ...
		INPUT  : ...

		sec.1: functionality & available commands:
			- program description: N/A
			- commands           : N/A
		sec.2: hardware used, input-output form, data size, user type & population, ...:
			- hardware version   : N/A
			- software version   : N/A
			- input type         : N/A
			- output type        : N/A
			- max data size      : N/A
			- users              : N/A
			- number of users    : N/A
		sec.3: updates on software, hardware, & user-interface:
			- hardware updates   : N/A
			- software updates   : N/A
			- ui updates         : N/A
		sec.4: documentation format requirements based on type of user:
			- data input         : N/A
			- commands           : N/A
		=======================================================================================
		*/

		// - [ sec-1: define & assign            ]
	    // - Start and End of stack buffer, respectively
	    char *stack; char *stackTop;

	    pid_t pid;
	    struct utsname uts;

	    /*if (argc < 2) {
	       fprintf(stderr, "Usage: %s <child-hostname>\n", argv[0]);
	       exit(EXIT_SUCCESS);
	    }*/

	    /* Allocate memory to be used for the stack of the child.
	       - [ https://stackoverflow.com/a/23258542/11492382 ]
	    */
	    stack = (char*)mmap(NULL, STACK_SIZE, PROT_READ | PROT_WRITE,
	             MAP_PRIVATE | MAP_ANONYMOUS | MAP_STACK, -1, 0);

	    if (stack == MAP_FAILED){
	       errExit("mmap");
	    }

	    // - Assume stack grows downward
	    stackTop = stack + STACK_SIZE;

	    // - [ sec-2: start demo: BLACK BOX TEST ]
	    /* Create child that has its own UTS namespace;
	       child commences execution in childFunc().
	    */
	    pid = clone((int (*)(void*))childFunc, stackTop,
	                 CLONE_NEWNS | CLONE_NEWPID | CLONE_NEWUTS | SIGCHLD, (void*)"/bin/sh");
	    if (pid == -1){
	       errExit("clone");
	    }
	    printf("clone() returned %jd\n", (intmax_t) pid);

	    /* parent falls through to here;
	       give child time to change its hostname
	    */
	    sleep(1);

	    /*Display hostname in parent's UTS namespace. This will be
	      different from hostname in child's UTS namespace.
	    if (uname(&uts) == -1){
	       errExit("uname");
	    }
	    printf("uts.nodename in parent: %s\n", uts.nodename);*/

	    // - Wait for child
	    if (waitpid(pid, NULL, 0) == -1){
	       errExit("waitpid");
	    }
	    printf("child has terminated\n");

	    // - [ sec-3: return VOID                ]
	    exit(EXIT_SUCCESS);
	}
// ====================================[ sec-4: END          ]
