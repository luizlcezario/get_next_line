#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fpointer;
	char *singleLine;
	int i;

	fpointer = open("../files/41_with_nl", 256);
	for(i = 0; i <= 2; i++)
	{
		singleLine = get_next_line(fpointer);
		printf("%s",singleLine);
	}
	return(0);
}
