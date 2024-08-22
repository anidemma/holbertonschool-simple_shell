#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_LEN 100
#define PROMPT ">> "
#define PATH "PATH="

void execute (char **args, char *path);
void split_newline(char *commands, char **commands_arr);
void split(char *command, char **args);
void handle_commands_arr(char **commands_arr);
void handle_command(char *command);
void handle_path(char **args, char **path, char **path_environ, int *flag);
void set_env(char **path_env, char **path);
void print_environ(void);
#endif
