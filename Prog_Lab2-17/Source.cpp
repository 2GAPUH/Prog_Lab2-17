#include <stdlib.h>
#include <stdio.h>
#include "Ring.h"

//N ребят располагаются по кругу.Начав отсчет от первого,
//удаляют каждого k - го, смыкая при этом круг.Определить порядок
//удаления ребят из круга.


void MainLoop()
{
	int userChoice = 0;
	int tmpValue = 0, tmpIndex = 0;
	bool loop = true;
	ring array = { NULL };

	printf_s("1 - Add new next element \n2 - Add new prev element \n3 - Get with removing \n4 - Get without removing \n5 - Clear \n6 - Move right \n7 - Move left \n8 - Find element \n9 - Get count of elements \n10 - Task \n0 - Exit \n");

	while (loop)
	{
		printf_s("Your choice: ");
		scanf_s("%d", &userChoice);

		switch (userChoice)
		{
		case 1:
			printf_s("Enter your element: ");
			scanf_s("%d", &tmpValue);
			PushNextRing(&array, tmpValue);
			break;

		case 2:
			printf_s("Enter your element: ");
			scanf_s("%d", &tmpValue);
			PushPrevRing(&array, tmpValue);
			break;

		case 3:
			if ((tmpValue = PopRing(&array)) != INT_MAX)
				printf_s("Your element: %d\n", tmpValue);
			else
				printf_s("Your ring is empty.\n");
			break;

		case 4:
			if ((tmpValue = PeekRing(&array)) != INT_MAX)
				printf_s("Your element: %d\n", tmpValue);
			else
				printf_s("Your ring is empty.\n");
			break;

		case 5:
			DestroyRing(&array);
			break;

		case 6:
			GoNextRing(&array);
			break;

		case 7:
			GoPrevRing(&array);
			break;

		case 8:
			printf_s("Enter value: ");
			scanf_s("%d", &tmpValue);
			
			if (FindInRing(&array, tmpValue))
				printf_s("%d in ring\n", tmpValue);
			else
				printf_s("%d not in ring\n", tmpValue);
			break;

		case 9:
			printf_s("Elements int ring: %d\n", GetSizeRing(&array));
			break;

		case 10:
			while (true)
			{
				printf_s("Enter k: ");
				scanf_s("%d", &tmpValue);
				if (tmpValue > 0)
					break;
				printf_s("Invalid value!");
			}
			DeleteK_Element(&array, tmpValue);
			break;

		case 0:
			loop = 0;
			break;

		default:

			break;
		}

		PrintRing(&array);
	}

	DestroyRing(&array);
}


int main()
{
	MainLoop();

	return 0;
}