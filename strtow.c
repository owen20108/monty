#include "monty.h"
#include "lists.h"

/**
 * counter_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int counter_word(char *s)
{
	int flags, cr, wr;

	flags = 0;
	wr = 0;

	for (cr = 0; s[cr] != '\0'; cr++)
	{
		if (s[cr] == ' ')
			flags = 0;
		else if (flags == 0)
		{
			flags = 1;
			wr++;
		}
	}

	return (wr);
}
/**
 * **stratow - devide string into words
 * @str: string to devide
 *
 * Return: pointer for  array of strings (Success)
 * or NULL (Error)
 */
char **stratow(char *str)
{
	char **matrx, *tmpo;
	int i, k = 0, lenght = 0, words, c = 0, start, end;

	lenght = strlen(str);
	words = counter_word(str);
	if (words == 0)
		return (NULL);

	matrx = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrx == NULL)
		return (NULL);

	for (i = 0; i <= lenght; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (cr)
			{
				end = i;
				tmpo = (char *) malloc(sizeof(char) * (cr + 1));
				if (tmpo == NULL)
					return (NULL);
				while (start < end)
					*tmpo++ = str[start++];
				*tmpo = '\0';
				matrx[k] = tmpo - cr;
				k++;
				cr = 0;
			}
		}
		else if (cr++ == 0)
			start = i;
	}

	matrx[k] = NULL;

	return (matrx);
}

/**
 * free_everything - frees arrays of strings
 * @args: array of strings to free
 */
void free_everything(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}
