#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fpointer;
	char	*singleLine;
	int		i;

	fpointer = open("../files/41_with_nl", 256);
	for (i = 0; i <= 1; i++)
	{
		singleLine = get_next_line(fpointer);
		printf("%s", singleLine);
		free(singleLine);
	}
	return (0);
}
