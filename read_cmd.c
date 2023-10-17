#include "shell.h"
/**
 * read_cmd - function to read the commands.
 * @cmd: Command input
 * @cmd_size: size
 */
void read_cmd(char *cmd, size_t cmd_size)
{
	if (fgets(cmd, cmd_size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			our_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			our_print("Reading error.\n");
			exit(EXIT_FAILURE);
		}
	}
	cmd[strcspn(cmd, "\n")] = '\0';
}
