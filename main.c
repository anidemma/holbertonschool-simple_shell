#include "main.h"
/**
 * main - main function
 * Return: int
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    char *command;
    char *argv[2];

    while (1)
    {
        printf("#cisfun$ ");
        nread = getline(&line, &len, stdin);

        if(nread == -1)
        {
                printf("\n");
                break;
        }

        line[strcspn(line, "\n")] = '\0';

        command  = strtok(line, " ");

        if (command == NULL)
        {
                continue;
        }

        argv[0] = command;
        argv[1] = NULL;

        pid = fork();
        if (pid == -1)
        {
                perror("fork");
                continue;
        }
        else if (pid == 0)
        {
                if (execve(command, argv, environ) == -1)
                {
                        perror(command);
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                wait(NULL);
        }
    }

        free(line);
    return (0);
}
