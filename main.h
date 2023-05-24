#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>

extern char **environ;

/**
 * struct info - informations
 * @toke: token
 * @env: enviroment
 * @name: name
 * @c_name: c_name
 * Description: informations for simple shell
*/
typedef struct info
{
	char **toke;
	char **env;
	char *name;
	char *c_name;
} data_p;

/**
 * struct builtin - builtin
 * @env: env
 * @exit: exit
 * Description: builtin struct for simple shell
*/
typedef struct builtin
{
	char *env;
	char *exit;
} builtin;

void s_handler(int s);
void set_data(data_p *data, char *agv[]);
int _execute(data_p *data);
void shell_loop(data_p *data, char *prompt);
int get_locat(data_p *data);
void free_data(data_p *data);
void free_array(char **array);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int handl_builtin(data_p *data);
int _strcmp(char *s1, char *s2);
int _print_error(int error, data_p *data);
int _print(char *str);

#endif
