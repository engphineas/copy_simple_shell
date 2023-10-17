#include "shell.h"
/**
 * main - function main
 * @void: no arguments
 * Return: void
 */

int main(void)
{
	char cmd[250];

	while (1)
	{
		our_display_prompt();
		read_cmd(cmd, sizeof(cmd));
		execute_cmd(cmd);
	}
	return (0);
}
