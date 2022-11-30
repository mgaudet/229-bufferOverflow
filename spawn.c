#include <spawn.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
	if (!argv[0] || !argv[1]) {
		printf("Usage: spawn <command> <args>\n");
		return -1;
	}

	int ret;
	short ps_flags = 0;
	pid_t pid;
	posix_spawn_file_actions_t actions;
	posix_spawnattr_t attrs;

	posix_spawn_file_actions_init(&actions);
	posix_spawnattr_init(&attrs);
#ifndef _POSIX_SPAWN_DISABLE_ASLR
#	define _POSIX_SPAWN_DISABLE_ASLR 0x0100
#endif

	ps_flags |= POSIX_SPAWN_SETEXEC;
	ps_flags |= _POSIX_SPAWN_DISABLE_ASLR;
	ret = posix_spawnattr_setflags(&attrs, ps_flags);

	if (ret != 0) {
		printf("cannot set posix_spawn flags\n");
	}

	ret = posix_spawn(&pid, argv[1], &actions, &attrs, &argv[1], environ);
	if (ret != 0) {
		printf("failed to spawn %s\n", argv[1]);
		return ret;
	}

	printf("pid: %d\n", pid);
	printf("========================\n");
	return 0;
}