#include "main.h"


/**
* free_array - free an array of string
* @array: pointer of string
*/

void free_array(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}

/**
* free_data - free array of struct
* @data: a pointer to a struct array
*/

void free_data(data_p *data)
{
	if (data->toke)
		free_array(data->toke);
	if (data->c_name)
		free(data->c_name);

	data->c_name = NULL;
	data->toke = NULL;
}
