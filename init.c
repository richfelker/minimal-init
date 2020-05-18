#include <signal.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>

int main()
{
	if (getpid() != 1) return 1;

	sigset_t set, old;
	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, &old);

	posix_spawnattr_t attr;
	posix_spawnattr_init(&attr);
	posix_spawnattr_setsigmask(&attr, &old);
	posix_spawnattr_setflags(&attr, POSIX_SPAWN_SETSID|POSIX_SPAWN_SETSIGMASK);

	posix_spawn(0, "/etc/rc", 0, &attr,
		((char *[]){ "rc", 0 }),
		((char *[]){ 0 }));

	for (;;) wait(0);
}
