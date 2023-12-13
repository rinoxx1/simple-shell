#include"shell.h"
/**
 * executeCommand - Main function to execute a command
 * @com: The command to execute
 *
 * Return: 0 if no command specified,otherwise it returns searchCommanInPath
 */
int executeCommand(const char *com)
{
	char *road = getenv("PATH");
	char *com_args[MAX_COMMAND_LENGTH];
	int arg_count;

	tokenizeCommand(com, com_args, &arg_count);

	if (arg_count == 0)
	{
		printf("No command specified\n");
		return (0);
	}

	return (searchCommanInPath(com_args[0], com_args, road));
}
