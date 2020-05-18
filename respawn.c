#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <spawn.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char **argv)
{
	sigset_t set, old;
	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, &old);

	posix_spawnattr_t attr;
	posix_spawnattr_init(&attr);
	posix_spawnattr_setsigmask(&attr, &old);
	posix_spawnattr_setflags(&attr, POSIX_SPAWN_SETSID|POSIX_SPAWN_SETSIGMASK);

	for (;;) {
		extern char **environ;
		pid_t pid;
		if (posix_spawn(&pid, argv[1], 0, &attr, argv+1, environ))
			nanosleep(&(struct timespec){.tv_nsec=100000000}, 0);
		waitpid(pid, 0, 0);
	}
}
