#include "shell.h"

/**
 * print_environment - Prints all environment variables
 *
 * Return: Nothing
 */
void print_environment(void)
{
	char **e_v = environ;

	while (*e_v != NULL)
	{
		printf("%s\n", *e_v);
		e_v++;
	}
}
/**
 * fileExists - Checks if a file exists in a given directory
 * @road: The directory path
 * @file: The filename
 *
 * Return: 1 if the file exists, 0 otherwise
 */
int fileExists(const char *road, const char *file)
{
	char full_road[MAX_PATH_LENGTH];

	snprintf(full_road, sizeof(full_road), "%s/%s", road, file);
	return (access(full_road, F_OK) != -1);
}
