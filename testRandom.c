#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int posX = 1;
	int posY = 1;

	int boucle = 0;

	for (int i = 0; i < 20; ++i)
	{
		do
		{
			if (posX == 1 && posY == 1)
			{
				posX = rand()%(3);
				posY = rand()%(3);
			}
			else
			{
				boucle = 1;
			}
		}
		while (boucle = 0);

		printf("%d %d\n", rand()%(3-0), rand()%(3-0));
	}

	return 0;
}

