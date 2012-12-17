#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_input_type(char c)
{
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return 1;

	if (c >= '0' && c <= '9')
		return 2;

	return 0;
}

int main(void)
{
	char * str = "Don't ask what your country can do for you, but ask what you can do for your country.";

	int i = 0;
	int pos = 0;
	char c;

	int state = 0;	// init state
	int input = 0;	// 0: space		1: alpha

	printf("hello, search word from string:\n");
	printf("<%s>\n", str);

	while ((c = *str++) != '\0')
	{
		char wordbuf[32];

		input = get_input_type(c);
		//printf("state = %d ", state);

		if (state == 0 && input == 1)
		{
			state = 1;
			//printf("word begin with <%c>\n", c);
			i = 0;
			wordbuf[i++] = c;
		} else if (state == 1 && input == 0)
			{
				wordbuf[i] = '\0';
				printf("find a word = <%s>\n", wordbuf);
		
				state = 0;
			} else if (state == 1 && input == 1)
					wordbuf[i++] = c;
	}

	return 0;
}
