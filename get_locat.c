#include "main.h"

/**
* check_file - check th permission of the file
* @full_path: a pointer to a path of cmmand
* Return: 0 in success or 126, 127 in failor
*/


int check_file(char *full_path)
{
struct stat sb;

if (stat(full_path, &sb) != -1)
{
if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
{
errno = 126;
return (126);
}
return (0);
}
errno = 127;
return (127);
}

/**
* get_locat - get the location of the command
* @data: a pointer to a struct array
* Return: 0 in success or 126, 127 in failor
*/

int get_locat(data_p *data)
{
char *path = NULL, *get_path = NULL, *token = NULL;
int length_p, length_arg, x = 0;

if (!data->c_name)
return (2);

if (data->c_name[0] == '/' || data->c_name[0] == '.')
return (check_file(data->c_name));

path = getenv("PATH=");
path = _strdup(path);
length_arg = _strlen(data->toke[0]);
token = strtok(path, ":");
while (token != NULL)
{
length_p = _strlen(token);
get_path = malloc(length_arg + length_p + 2);
_strcpy(get_path, token);
_strcat(get_path, "/");
_strcat(get_path, data->toke[0]);
_strcat(get_path, "\0");
x = check_file(get_path);
if (x == 0 || x == 126)
{
free(path);
free(data->toke[0]);
data->toke[0] = _strdup(get_path);
return (x); }
else
{
free(get_path);
token = strtok(NULL, ":"); }
}
free(path);
free(data->toke[0]);
data->toke[0] = NULL;
return (x);
}
