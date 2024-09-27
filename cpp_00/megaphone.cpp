#include <iostream>
#include <cctype>


int	main(int argc , char *argv[])
{
	int	c = 1;

	if (argc > 1)
	{
		while (argc > c)
		{
			int	i = 0;
			while (argv[c][i] != '\0')
			{
				std::cout << (char)std::toupper(argv[c][i]);
				i++;
			}
			c++;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return 0;
}

