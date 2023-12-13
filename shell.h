#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ; /* Expose the environment variable */
void tokenizeCommand(const char *com, char *com_args[], int *arg_count);
void constructFullPath(const char *token, const char *command, char *full_com);
int executeAndAwait(const char *full_com, char *com_args[]);
int searchCommanInPath(const char *command, char *com_args[], const char *road);
int executeCommand(const char *com);
void print_environment(void);
int fileExists(const char *road, const char *file);
void handleExitCommand(void);
void handleEnvCommand(void);
void handleInvalidCommand(void);
void handleWordCountError(void);

#define MAX_COMMAND_LENGTH 500
#define MAX_PATH_LENGTH 500

#endif
