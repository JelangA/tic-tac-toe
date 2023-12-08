int opponent;

int chooseOpponent()
{
	do
	{
		printf("Choose your opponent : \n1. 2 Player\n2. BOT\nChoose : ");
		scanf("%d", &opponent);
		if (opponent != 1 && opponent != 2)
		{
			printf("Invalid Choice Please choose just two if them.\n");
		}
	} while (opponent == 1 && opponent == 2);
	system("CLS");
}