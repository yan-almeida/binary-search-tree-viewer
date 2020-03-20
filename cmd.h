#define L 50

// prot. functions
void show_help(); // cabeçalho >> help
void show_header();	// command-line

// funcitons
	// menu >> help
void show_help()
{
	textcolor(WHITE);
	printf("\t\t\t\t\t\t\t\t\t\t Options include: \n");
	printf("\t\t\t\t\t\t\t\t\t\t    >> /help      'this command shows included command options.' \n");
	printf("\t\t\t\t\t\t\t\t\t\t    >> /+         'this command adds an element.' \n");
	printf("\t\t\t\t\t\t\t\t\t\t    >> /-         'this command removes an element.' \n");
	printf("\t\t\t\t\t\t\t\t\t\t    >> /esc       'this command ends the process.' \n");
	printf("\t\t\t\t\t\t\t\t\t\t    >> /main      'this command starts program execution - main/bin_tree.' ");
	textcolor(LIGHT_GRAY);
}
	// command-line
void show_header()
{
	int a = 8, aa = a + 5, b = 6, k;
	int cmp, st, cmd; // comparadores
	char command[L], help[L], comm[L];

	system("title Binary Search Tree Viewer - Command-Line");
	system("COLOR 37");
	
	textcolor(WHITE);
	movexy(a, b - 3, " Binary Search Tree Viewer[version 1.0.10]   ");
	movexy(a, b - 2, " (c) 2020 Keys Deserves. All rights reserved. ");

	strcpy(command, "/main");	// C:\Users\bin_tree>./main
	strcpy(help, "/help");	// C:\Users\bin_tree>./help

	k = 1;
	do {	
		movexy(a, b + k, " C:\\Users\\bin_tree>");
		textcolor(YELLOW);
		gets(comm);
		fflush(stdin);

		if (strcmp(comm, command) == 0)
		{
			show_tree();	
		} 
		else if (strcmp(comm, help) == 0)
		{
			show_help();

			k += 2;
		}
		else if (strcmp(comm, "/+") == 0)
		{
			// comandos (-)/(+)/(M)
			textcolor(LIGHT_GRAY);
			printf("\t '%s' element inserted into the node. ", comm);

			k += 3;
		}
		else if (strcmp(comm, "/-") == 0)
		{
			textcolor(LIGHT_GRAY);
			printf("\t '%s' element removed from the node. ", comm);

			k += 3;
		}
		else if (strcmp(comm, "/esc") == 0)
		{
			textcolor(LIGHT_GRAY);
			printf("\t '%s' ended the process. ", comm);

			k += 3;
		}
		else
		{
			textcolor(LIGHT_GRAY);
			printf("\t '%s' it is not recognized as an internal or external command. \n\t Try '/help' to help you. ", comm);

			k += 4;
		}

		textcolor(WHITE);
	} while (1);
}

