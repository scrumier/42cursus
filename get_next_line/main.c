#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }
    line = get_next_line(fd);
	if (line)
    {
        printf("%s", line);
        free(line);
    }
	// get_next_line(-1);
    close(fd);
    return (0);
}