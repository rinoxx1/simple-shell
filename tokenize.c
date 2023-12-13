/**
 * tokenizeCommand - Function to tokenize a command into arguments
 * @com: The command
 * @com_args: The command arguments
 * @arg_count: The argument count
 */
void tokenizeCommand(const char *com, char *com_args[], int *arg_count)
{
	char *token;
	char *svstt1;
	int i = 0;

	token = strtok_r((char *)com, " ", &svstt1);
	while (token != NULL)
	{
		com_args[i++] = token;
		token = strtok_r(NULL, " ", &svstt1);
	}
	com_args[i] = NULL;
	*arg_count = i;
}
