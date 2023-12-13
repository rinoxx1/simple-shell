/**
 * constructFullPath - Function to construct the full command path
 * @token: The token
 * @command: The command
 * @full_com: The full command
 */
void constructFullPath(const char *token, const char *command, char *full_com)
{
	snprintf(full_com, MAX_PATH_LENGTH, "%s/%s", token, command);
}

/**
 * executeAndAwait - Function to execute command and wait for the child process
 * @full_com: The full command
 * @com_args: The command arguments
 *
 * Return: 1 if error, 0 otherwise
 */
int executeAndAwait(const char *full_com, char *com_args[])
{
	pid_t vod = fork();

	if (vod == -1)
	{
		perror("fork");
		return (1);
	}

	if (vod == 0)
	{
		if (execvp(full_com, com_args) == -1)
		{
			perror(full_com);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(vod, &status, 0);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status) == 0 ? 0 : 1);
		}
		else
		{
			perror("Child process did not exit successfully");
			return (1);
		}
	}
	return (1);
}
