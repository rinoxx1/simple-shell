/**
 * handleExitCommand - Function to handle exit command
 */
void handleExitCommand(void)
{
	printf("Departing from the shell interface. Farewell\n");
}

/**
 * handleEnvCommand - Function to handle environment command
 */
void handleEnvCommand(void)
{
	print_environment();
}

/**
 * handleInvalidCommand - Function to handle invalid command
 */
void handleInvalidCommand(void)
{
	printf("Caution: Command has advanced features.\n");
}

/**
 * handleWordCountError - Function to handle word count error
 */
void handleWordCountError(void)
{
	printf("Caution: The Command should be only one word.\n");
}
