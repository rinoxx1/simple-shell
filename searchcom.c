/**
 * searchCommanInPath - searches for the command in the PATH
 * @command: the command to search for
 * @com_args: the arguments for the command
 * @road: the path to search in
 *
 * Return: 0 if command not found,otherwise the return value of executeAndAwait
 */
int searchCommanInPath(const char *command, char *com_args[], const char *road)
{
	char road_copy[MAX_PATH_LENGTH];
	char full_com[MAX_PATH_LENGTH];
	char *svstt2;
	char *token;

	strncpy(road_copy, road, MAX_PATH_LENGTH);
	token = strtok_r(road_copy, ":", &svstt2);
	while (token != NULL)
	{
	constructFullPath(token, command, full_com);
	if (access(full_com, F_OK) != -1)
	{
		return (executeAndAwait(full_com, com_args));
	}
	token = strtok_r(NULL, ":", &svstt2);
	}
	printf("Command '%s' not found\n", com_args[0]);
	return (0);
}
