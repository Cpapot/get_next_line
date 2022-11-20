#include "../get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int i;
	int fd;
	char *line;

	fd = open("test/41_with_nl", O_RDONLY);
	i = 0;
	while (i != 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			printf("\n");
		free(line);
		printf("%s\n", "============================");
		i++;
	}
	//show_leaks();
}
