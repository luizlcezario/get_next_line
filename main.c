#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fpointer;
	char *singleLine;
	int i;

	fpointer = open("files/43_with_nl", 256);

	// singleLine = get_next_line(fpointer);
	// printf("%s",singleLine);
	// singleLine = get_next_line(-1);
	// printf("%s",singleLine);
	for(i = 0; i <= 3; i++)
	{
		singleLine = get_next_line(fpointer);
		printf("%s",singleLine);
	}
	close(fpointer);
	return(0);
}
