#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "conio2.h" 
#include "bst.h" 
#include "cmd.h" 

// prot. functions
void show_tree(); // menu >> insert(+)/remove(-)/exit(1)/show_menu()
void show_text(int n); // entradas
void show_msg(); // 

// structs
struct tm* DH;

/*
	19 de março de 2020	
    Departamento de T.I., UniProjeção (Taguatinga, Campus I)
   
    Sistemas de Informação (3º semestre)
    Autor: Yan Almeida Garcia - 2019 199 05 
    
    Disciplina: Estrutura de Dados - João Evangelista

	00) montagem >> árvore binária de busca:
		- Inserção.
		- Remoção.
		- exibição: 
			  - árvore completa - raiz, sub-arv. esquerda e sub-arv. direita;
			  - em ordem;
			  - pré-ordem;
			  - pós-ordem;					
		- Buscar elemento na árvore - mostragem de tempo de busca
		
	Referência bibliográfica:
		[01]. "Árvore Binária com a Linguagem C", disponível em: http://ninjacode.com.br/arvore-binaria-com-a-linguagem-c/
		[02]. "Programar em C/Árvores binárias de Busca", disponível em: https://pt.wikibooks.org/wiki/Programar_em_C/%C3%81rvores_bin%C3%A1rias_de_Busca
		[03]. "Árvores Binárias de Busca", disponível em: https://www.cin.ufpe.br/~dmrac/aula%20de%20arvore%20binaria%20de%20busca.pdf
*/

// global vars.
int i, j, k;
char op;

int main()
{
	system("mode 162");	// size screen >> 162px largura

	show_header();

	return 0;
}

// functions
	// menu >> insert(+)/remove(-)/exit(1)/show_menu()
void show_tree()
{
	int a = 2, b = 63, bb = b + 21, c = 7, d = 36, e = 4, k;
	int inserts, removes, search, rnd = 0;
	clock_t t;
		
	arq = fopen(txt, "a");

	system("title Binary Search Tree Viewer - /bin_");
	system("COLOR 07");
	
	Node *root = tree_initialize();
		
	do {
		system("cls");

		textcolor(WHITE);
		borders(41, 151, 4, a);
		show_text(2);
		 
			// exibir >> ordens e max/min		
		if (root != NULL)
		{
			textbackground(CYAN);
			tree_prints(root, 79, 4, 18);
			
			textbackground(BLACK);
			movexy(c, 40, "Pre Order:  ");
			print_preOrder(root);	
			movexy(c, 41, "in Order:   ");
			print_inOrder(root);
			movexy(c, 42, "Post Order: ");
			print_postOrder(root);
				// elemento max. e min. da árvore
			movexy(146, 40, "Max: ");
			print_max(root);
			movexy(146, 42, "Min: ");
			print_min(root);
		}
		else
		{
			textcolor(WHITE);
			textbackground(GREEN);
			movexy(73, 4, " TREE IS EMPTY. ");
			movexy(72, 5, " INSERT SOMETHING ");
		}

		gotoxy(160, 45);
		op = toupper(getch());

		switch (op)
		{
				// insere elemento aleatorio
			case 'M':
				if (root == NULL)
				{
					srand(time(NULL));

					for (i = 0; i < 18; i++)
					{
					    rnd = ((double) rand() / ((double) RAND_MAX + 1) * 99) - 30;
					    root = tree_inserts(root, created_item(rnd));
					}
						
					textbackground(BLACK);
				}
				else
				{
					textcolor(WHITE);
					textbackground(BLUE);
					movexy(71, d, " TREE IS NOT VOID ");
					movexy(67, d + 1, " R TO RESET AND TRY AGAIN ");
					
					getch();
					textbackground(BLACK);
				}
   
				textbackground(BLACK);
			break;
				// insere elemento	
			case '+':
				system("title Binary Search Tree Viewer - Inserts ");
				
				textbackground(GREEN);
				movexy(b, a, " Inserts < + > ");
				tree_prints(root, 79, 4, 13);
				
				show_text(0); // green color

				movexy(c - 1, e, " Insert something: ");
				scanf(" %d", &inserts);
				fflush(stdin);
				
				root = tree_inserts(root, created_item(inserts));
			break;
				// remove elemento
			case '-':
				system("title Binary Search Tree Viewer - Removes ");

				if (root != NULL)
				{
					textbackground(RED);
					movexy(bb, a, " Removes < - > ");
					tree_prints(root, 79, 4, 13);
					
					show_text(1); // green color
			
					movexy(c - 1, e, " Remove something: ");
					scanf(" %d", &removes);
					fflush(stdin);
					
					root = tree_removes(root, removes);
				}
				else  
				{
					show_msg();
				}		
			break;
				// limpa a arvore
			case 'R':
				tree_free(root);
				show_tree();
			break;
				// backup da árvore >> exit(2)	
			case 'B':
				system("title Binary Search Tree Viewer - Backup ");
				textbackground(BLACK);
				
				if (root != NULL)
				{
					time_t segundos;
					time(&segundos);   
				  	DH = localtime(&segundos);
				  	
					if (arq != NULL)
					{
						textcolor(WHITE);
						textbackground(BLUE);
						movexy(65, d, " BACKUP PERFORMED SUCCESSFULLY! ");
						movexy(69, d + 1, " THE PROGRAM WILL ENDED ");
						
						fprintf(arq, "%.2d/%.2d/%.4d ", DH->tm_mday, DH->tm_mon + 1, DH->tm_year + 1900); 
	 					fprintf(arq, "- %.2d:%.2d:%.2d", DH->tm_hour, DH->tm_min, DH->tm_sec);    
	 					
						fprintf(arq, "\nPre order:  ");
						fwrite_preOrder(root);
						
						fprintf(arq, "\nIn order:   ");
						fwrite_inOrder(root);
						
						fprintf(arq, "\nPost order: ");
						fwrite_postOrder(root);
						fprintf(arq, "\n\n");
						
						fclose(arq);
						tree_free(root);
						
						textbackground(BLACK);
						getch();
						system("cls");
						exit(2);
					}
					else
					{
						textcolor(WHITE);
						textbackground(BLUE);
						movexy(70, d, " DIRECTORY NOT FOUND! ");
						movexy(67, d + 1, " MAKE A NEW FOLDER: 'files' ");
						
						textbackground(BLACK);
						getch();
					}	
				}
				else
				{
					show_msg();
				}
			break;
				// procura elemento	
			case 'S':
				system("title Binary Search Tree Viewer - Search ");
				
				if (root != NULL)
				{
					textbackground(BLACK);
					movexy(c - 1, e, " Search something: ");
					scanf(" %d", &search);
					fflush(stdin);
					
				 	t = clock(); //armazena tempo
					
					Node* tmp = tree_searchs(root, search);
					
					if (tmp != NULL)
					{
						movexy(c, e + 2, "Found element");
					}
					else 
					{
						movexy(c, e + 2, "Not found element");
					}	
	
					t = clock() - t;
					gotoxy(c, e + 3);
					printf("Runtime: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));	
	
					getch();
				}
				else
				{
					show_msg();
				}
			break;
									
			default:
				textbackground(BLACK);
			break;	
		}
	} while (op != 27);
		
	tree_free(root);

	system("cls");
	system("title Binary Search Tree Viewer - Yan Almeida Garcia (2019 199 05)");
	system("color 0f");

	exit(1);
}
	// entrada de textos
void show_text(int n)
{
	int a = 2, b = 63, bb = b + 21, d = 44;
	
	if (n == 0) 
	{	
		textbackground(BLACK);
		movexy(bb, a, " Removes < - > ");
		movexy(139, a, " Exit < esc > ");
		movexy(8, d, " Random Inserts < m > ");
		movexy(b + 2, d, " Reset < r > ");
		movexy(bb, d, " Search < s > ");
		movexy(139, d, " Backup < b > ");
	} 
	else if (n == 1)
	{			
		textbackground(BLACK);
		movexy(b, a, " Inserts < + > ");
		movexy(139, a, " Exit < esc > ");
		movexy(8, d, " Random Inserts < m > ");
		movexy(b + 2, d, " Reset < r > ");
		movexy(bb, d, " Search < s > ");
		movexy(139, d, " Backup < b > ");
	}
	else if (n == 2)
	{
		movexy(b, a, " Inserts < + > ");
		movexy(bb, a, " Removes < - > ");
		movexy(139, a, " Exit < esc > ");
		movexy(8, d, " Random Inserts < m > ");
		movexy(b + 2, d, " Reset < r > ");
		movexy(bb, d, " Search < s > ");
		movexy(139, d, " Backup < b > ");
	}	
}
	//
void show_msg()
{
	int d = 36;
	
	system("title Binary Search Tree Viewer - Add Something ");
	
	textcolor(WHITE);
	textbackground(BLUE);
	movexy(73, d - 1, " Inserts < + > ");
	movexy(78, d + 0, " or ");
	movexy(70, d + 1, " Random Inserts < m > ");
		
	getch();
	textbackground(BLACK);
}

