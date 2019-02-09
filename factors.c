#include "rsa.h"


/**
 * init - Initializes the text buffer with null char
 *
 * @buffer: Array that will hold numbers
 *
 * Return: None (void function)
 */
void init(char *buffer)
{
	int i = 0;

	for (i = 0; i < S_BUFFER; i++)
		buffer[i] = '\0';
}

/**
 * file2buffer - Reads argv[1] to buffer
 *
 * @filename: Pointer to file location
 *
 * @buffer: Array that holds the file data
 *
 * Return: None (void function)
 */
void file2buffer(char *filename, char *buffer)
{
	int opens = 0;

	opens = open(filename, O_RDONLY);
	if (opens < 0)
		exit(EXIT_FAILURE);

	if (read(opens, buffer, S_BUFFER) < 0)
	{
		close(opens);
		exit(EXIT_FAILURE);
	}
	close(opens);
}

/**
 * _atoi - ASCII -> int conversion
 *
 * @src: Input char array
 *
 * @dest: Converted data array
 *
 * Return: Number of elements copied
 */
int _atoi(char *src, int *dest)
{
	int i = 0;

	for (i = 0; src[i] && src[i] != '\n'; i++)
		dest[i] = src[i] - '0';

	return (i);
}

/**
 * _putint - General agnostic number printing function
 *
 * @dest: Array of newly converted data
 *
 * @n: Size of array (N is also the principle number in PRho)
 *
 * Return: None (void function)
 */
void _putint(int *dest, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
		putchar(dest[i] + '0');
}

/**
 * main - Entry point
 *
 * @argc: Size of argv array
 *
 * @argv: Array of CLI inputs
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char buffer[S_BUFFER]; /* original buffer */
	char *token; /* tokenized buffer */

	int number[VALUE];
	int cv = 0;

	if (argc != 2)
		return (EXIT_FAILURE);

	init(buffer);
	file2buffer(argv[1], buffer);
	token = strtok(buffer, " \n"); /* separates each number */

	while (token != NULL)
	{
		cv = _atoi(token, number); /* converted values */
		_putint(number, cv);
		putchar('\n');
		token = strtok(NULL, " \n"); /* breaks up each number */
	}
	return (EXIT_SUCCESS);
}

