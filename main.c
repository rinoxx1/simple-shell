#include "shell.h"
/**
 * main - Entry point of the program
 *
 * Return: 0 on success, non-zero on failure
 */

int main(void)
{
	char *com = (char *)malloc(MAX_COMMAND_LENGTH * sizeof(char));
	char *space_ptr;

	while (1)
	{
		printf("#cisfun$ ");
		fgets(com, MAX_COMMAND_LENGTH, stdin);
		if (strcmp(com, "exit\n") == 0)
		{
			handleExitCommand();
			break;
		}
		else if (strcmp(com, "e_v\n") == 0)
		{
			handleEnvCommand();
		}
		else
		{
			if (strchr(com, ';') != NULL || strchr(com, '|') != NULL ||
			strchr(com, '<') != NULL || strchr(com, '>') != NULL)
			{
				handleInvalidCommand();
				continue;
			}
			space_ptr = strchr(com, ' ');
			if (space_ptr != NULL && *(space_ptr + 1) != '-')
			{
				handleWordCountError();
				continue;
			}
			com[strcspn(com, "\n")] = '\0';
			if (executeCommand(com) == 0)
			{
				continue;
			}
		}
	}
	free(com);
	return (0);
}
