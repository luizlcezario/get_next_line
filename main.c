#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fpointer;
	char *singleLine;
	int i;

	// singleLine = get_next_line(fpointer);
	// printf("%s",singleLine);
	// singleLine = get_next_line(-1);
	// printf("%s",singleLine);
	fpointer = open("files/43_with_nl", 256);
	for(i = 0; i <= 2; i++)
	{
		singleLine = get_next_line(fpointer);
		printf("%s",singleLine);
		free(singleLine);
		singleLine=NULL;
	}
	close(fpointer);
	return(0);
}
