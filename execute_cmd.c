#include "shell.h"
/**
 * execute_cmd - function that executes the prompt
 * @cmd: The command input
 * Return: 0 on success, -1 on failure.
 */


void execute_cmd(const char *cmd)
{
	pid_t pid_child = fork();

	if (pid_child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid_child == 0)
	{
		char *chars[250];
		int count = 0;
		char *tokenized;

		tokenized = strtok((char *)cmd, " ");
		for (; (tokenized = strtok(NULL, " ")) != NULL; count++)
		{
			chars[count] = tokenized;
		}
		chars[count] = NULL;
		execvp(chars[0], chars);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
