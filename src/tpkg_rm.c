#include <stdlib.h>
#include <stdio.h>
#include <minicli.h>
#include <config.h>

const char *prg_name;

void
version(void)
{
	printf("%s version %s\n", prg_name, PACKAGE_VERSION);
	exit(0);
}

void
usage(int retval)
{
	if (retval == EXIT_FAILURE)
	{
		fprintf(stderr, "Try '%s -h' for more information.\n", prg_name);
	}
	else
	{
		printf("Usage: %s [OPTION...] [PACKAGES...]\n", prg_name);
		printf("remove software packages\n\n");
		printf("\t-h\tDisplay this menu and exit.\n");
		printf("\t-V\tDisplay version information.\n");
		printf("\nReport bugs to <%s>\n", PACKAGE_BUGREPORT);
	}

	exit(retval);
}

int
main(int argc, char **argv)
{
	prg_name = argv[0];

	if (argc < 2)
	{
		usage(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
