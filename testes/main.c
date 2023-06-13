#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

char *dizionario42[][100];

int main(int argc, char *argv[])
{
   if (argc < 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }


	int indexHB = (atoi(argv[1]) / 100000000000) % 10;
	int indexDB = (atoi(argv[1]) / 10000000000) % 10;
	int indexB = (atoi(argv[1]) / 1000000000) % 10;
	int indexHM = (atoi(argv[1]) / 100000000) % 10;
	int indexDM = (atoi(argv[1]) / 10000000) % 10;
	int indexM = (atoi(argv[1]) / 1000000) % 10;
	int indexHT = (atoi(argv[1]) / 100000) % 10;
	int indexDT = (atoi(argv[1]) / 10000) % 10;
	int indexT = (atoi(argv[1]) / 1000) % 10;
	int indexH = (atoi(argv[1]) / (100)) % 10;
	int indexD = (atoi(argv[1]) / (10)) %10;
	int indexU = atoi(argv[1]) % 10;
	int indexUDa = indexD * 10 + indexU;
	



	printf( "indexHB  vale %i\n", indexHB );
	printf( "indexDB  vale %i\n", indexDB );
	printf( "indexB  vale %i\n", indexB );
	printf( "indexHM  vale %i\n", indexHM );
	printf( "indexDM  vale %i\n", indexDM );
	printf( "indexM  vale %i\n", indexM );
	printf( "indexHT  vale %i\n", indexHT );
	printf("indexDT  vale %i\n", indexDT);
	printf("indexT  vale %i\n", indexT);
	printf("indexH  vale %i\n", indexH);
	 printf("indexD vale %i\n", indexD);
	printf("indexU vale %i\n", indexU);
	printf("indexUDa vale %i\n", indexUDa);

	char *strH = dizionario42[0][indexH];
	char *strHsn = dizionario42[0][28];
	char *strUDa = dizionario42[0][indexUDa];
	char *strD = dizionario42[0][(indexD)+18];
	char *strU = dizionario42[0][indexU];
   
	if(indexH > 0)
	{
	write(1, strH, strlen(strH));
	write(1, strHsn, strlen(strHsn));
	
	}
	if (indexUDa <= 20 && indexUDa != 0)
	{
		write(1, strUDa, strlen(strUDa));
		write(1, "\n", 1);
	}
	if( indexUDa >= 20)
	{
	write(1, strD, strlen(strD));
	}
	if( indexU > 0)
	{
	write(1, strU, strlen(strU));
	}
	write(1, "\n", 1);
	
	
	return 0;
}



char *dizionario42[][100]=
{
"zero",
"one",
"two",
"three",
"four",
"five",
"six",
"seven",
"eight",
"nine",
"ten",
"eleven",
"twelve",
"thirteen",
"fourteen",
"fifteen",
"sixteen",
"seventeen",
"eighteen",
"nineteen",
"twenty",
"thirty",
"forty",
"fifty",
"sixty",
"seventy",
"eighty",
"ninety",
"hundred",
"thousand",
"million",
"billion"
};

