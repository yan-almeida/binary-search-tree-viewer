// structs
	// elemento 
struct item
{
	int cod;
};
typedef struct item Item;
	// arvore
struct node
{
	Item item;

	struct node * left;
	struct node * right;
};
typedef struct node Node;

// prot. functions 
Node* tree_initialize(); // inicia a arvore
Item created_item(int cod);	// cria um item

Node* tree_inserts(Node* root, Item x);	// insere na arvore >> created_item
void tree_prints(Node* root, int x, int y, int desloc);	// imprime arvore >> recursividade na impressão
void tree_free(Node* root);	// libera o espaço alocado >> free
Node* tree_min(Node* root);	// menor elemento >> função remover
Node* tree_removes(Node* root, int cod); // remove item
Node* tree_searchs(Node* root, int cod); // busca itme

void print_preOrder(Node* root); // imprime arvore >> pré ordem
void print_inOrder(Node* root); // imprime arvore >> em ordem
void print_postOrder(Node* root); // imprime arvore >> pós ordem

void print_min(Node* root); // imprime elemento >> minimo
void print_max(Node* root); // imprime elemento >> maximo

void fwrite_preOrder(Node *root); // backup de processos >> pré ordem
void fwrite_inOrder(Node *root); // backup de processos >> em ordem
void fwrite_postOrder(Node *root); // backup de processos >> pós ordem

char txt[] = "files//fwrite.txt";
FILE *arq = NULL;

// functions
	// inicia arvore
Node* tree_initialize()
{
	return NULL;
}
	// cria um item >> dado
Item created_item(int cod)
{
	Item item;
	item.cod = cod;

	return item;
}
	// cria um item aleatorio

	// insere na arvore
Node* tree_inserts(Node* root, Item x)
{
	if (root == NULL)
	{
		Node *aux = (Node*) malloc(sizeof(Node));
		aux->item = x;
		aux->left = NULL;
		aux->right = NULL;

		return aux;
	}
	else
	{
		if (x.cod > root->item.cod)
		{
			root->right = tree_inserts(root->right, x);
		}
		else if (x.cod < root->item.cod)
		{
			root->left = tree_inserts(root->left, x);
		}
	}

	return root;
}
	// imprime arvore
void tree_prints(Node *root, int x, int y, int desloc)
{
	if (root != NULL)
	{
		gotoxy(x, y);
		printf("[%d]", root->item.cod);	
		
		if (root->left != NULL)
		{
			tree_prints(root->left, x - desloc, y + 2, desloc / 2 + 1);
		}
		if (root->right != NULL)
		{
			tree_prints(root->right, x + desloc, y + 2, desloc / 2 + 1);
		}
	}
}
	// libera a memoria alocada
void tree_free(Node *root)
{
	if (root != NULL)
	{
		tree_free(root->left);
		tree_free(root->right);
		free(root);
	}
}
	// nó com o valor minimo
Node* tree_min(Node *root)
{
	if (root != NULL)
	{
		Node *aux = root;
		
		while (aux->left != NULL)
		{
			aux = aux->left;
		}
		
		return aux;
	}

	return NULL;	
}
	// remove da arvore
Node* tree_removes(Node *root, int cod)
{
	if (root != NULL)
	{
		if (cod > root->item.cod)
		{
			root->right = tree_removes(root->right, cod);
		}
		else if (cod < root->item.cod)
		{
			root->left = tree_removes(root->left, cod);
		}
		else	// dado encontrado
		{
			if (root->left == NULL && root->right == NULL)
			{
				free(root);

				return NULL;
			}
			else if (root->left == NULL && root->right != NULL)
			{
				Node *aux = root->right;
				free(root);

				return aux;	// ponte entre o elemento removido e o ultimo elemento do nó da esquerda			
			}
			else if (root->left != NULL && root->right == NULL)
			{
				Node *aux = root->left;
				free(root);

				return aux;	// ponte entre o elemento removido e o ultimo elemento do nó da direita		 					
			}
			else
			{
				Node *aux = tree_min(root->right);	// elemento minimo da minha maior sub-arvore
				Item itemAux = aux->item;

				root = tree_removes(root, itemAux.cod);
				root->item = itemAux;
			}
		}

		return root; // retorna o elemento pra raiz >> no caso de remoção do dado da raiz
	}

	return NULL;
}
	// imprime arvore >> pré ordem
void print_preOrder(Node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->item.cod);
		print_preOrder(root->left);	
		print_preOrder(root->right);	
	}
}
	// imprime arvore >> em ordem
void print_inOrder(Node *root)
{
	if (root != NULL)
	{
		print_inOrder(root->left);	
		printf("%d ", root->item.cod);
		print_inOrder(root->right);	
	}
}
	// imprime arvore >> pós ordem
void print_postOrder(Node *root)
{
	if (root != NULL)
	{
		print_postOrder(root->left);	
		print_postOrder(root->right);
		printf("%d ", root->item.cod);			
	}
}
	// busca item
Node* tree_searchs(Node* root, int cod)
{
	if (root != NULL)
	{
		if (root->item.cod == cod)
		{
			return root;	
		}
		else
		{
			if (cod > root->item.cod)
			{
				return tree_searchs(root->right, cod);
			}
			else 
			{
				return tree_searchs(root->left, cod);
			}
		}	
	}

	return NULL;
}
	// imprime elemento >> minimo
void print_min(Node* root)
{
	if (root->left == NULL)
	{
		printf("%d", root->item.cod);
	}
	else
	{
		print_min(root->left);
	}
}
	// imprime elemento >> maximo
void print_max(Node* root)
{
	if (root->right == NULL)
	{
		printf("%d", root->item.cod);
	}
	else 
	{
		print_max(root->right);	
	}
}
	// backup de processos >> pré ordem 	
void fwrite_preOrder(Node *root)
{  	
	if (root != NULL)
	{
		fprintf(arq, "[%d] ", root->item.cod);
		
		fwrite_preOrder(root->left);
		fwrite_preOrder(root->right);
	}
}
	// backup de processos >> em ordem	
void fwrite_inOrder(Node *root)
{	  			
	if (root != NULL)
	{
		fwrite_inOrder(root->left);
		fprintf(arq, "[%d] ", root->item.cod);
		fwrite_inOrder(root->right);
	}
}
	// backup de processos >> pós ordem 	
void fwrite_postOrder(Node *root)
{
	if (root != NULL)
	{
		fwrite_postOrder(root->left);
		fwrite_postOrder(root->right);
		fprintf(arq, "[%d] ", root->item.cod);
	}
}

