#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define tamUsu 200
#define tamLiv 200
#define arquivoUsuario "usuario.dat"
#define arquivoLivros "livros.dat"
#define arqLista

void statusLivro(void);
void cadastrarLivro(void);
void consultaLivro(void);
void consultaLivroCodigo(void);
void consultaLivroTitulo(void);
void cadastraUsuario(void);
void consultarUsuario (void);
void consultarUsuarioNome(void);
void consultarUsuarioCarteirinha(void);

typedef struct {
   int dia;
   int mes;
   int ano;
}dt;

typedef struct {       
   int codigo;       
   char titulo[30];       
   char genero[50];        
   int paginas[5];    
}livros;

typedef struct {        
   char nome[30];       
   int carteirinha;    
}usuario;

int main(){

    int opcao;
    do {
        printf("\n");
        printf("Sistema de controle de biblioteca\n");
        printf("=================================\n");
        printf("\n");

        printf("0 - Listar todos os livros da biblioteca.\n");
        printf("1 - Listar livros de uma categoria.\n");
        printf("2 - Reservar um livro. \n");
        printf("3 - Devolver livro. \n");
        printf("4 - Doar livro. \n");
        printf("5 - Cadastrar Usuario. \n");
        printf("6 - Consultar usuario por Nome. \n");
        printf("7 - Consultar usuario por numero da carteirinha. \n");
        printf("8 - Mostrar todos os usuarios cadastrados. \n");
        printf("9 - Cadastrar livro. \n");
        printf("10 - Consultar livro por titulo. \n");
        printf("11 - Consultar livro por código. \n");
        printf("12 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        		switch(opcao){
		    case 1:
			 	system ("cls");
			 	statusLivro();
		        break;
		    case 2:
				system ("cls");
				cadastraLivro();
		        break;
		    case 3:
				system ("cls");
				consultaLivro();
		        break;
		    case 4:
				system ("cls");
				consultaLivroCodigo();
		        break;
		    case 5:
				system ("cls");
				consultaLivroTitulo();
		        break;
		    case 6:
				system ("cls");
				cadastrarUsuario();
		        break;
		    case 7:
				system ("cls");
				consultarUsuario();
		        break;
		    case 8:
				system ("cls");
				consultarUsuarioNome();
		        break;
            case 9:
                system("cls");
                consultarUsuarioCarteirinha();
                break;
		    case 0:
				system ("cls");
				break;
			default:
				printf("\n\tOpcao invalida!\n\n");
			    system("pause");
                break;
        }
	}while(opcao != 0);
    return 0;
}

void cadastrarUsuario(void) {
    FILE * arq;
    usuario x;
    char aux[15];
    char aux2[15];
    int carteirinha;
    int i=0,j=0;
    int a = 0, num=0;
    do{
		do{
		   printf("\n\n\t     Cadastro de Novo Usuario\n\n");
		   if ((arq = fopen(arquivoUsuario, "a+b")) == NULL) {
			    fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoUsuario);
		    }
		   fseek(arq, 0, SEEK_SET);
		   a=0;
		   printf("\nCarteirinha: ");
		   fflush(stdin);
		   gets(carteirinha);
		   while(fread(&x, sizeof(usuario), 1, arq) > 0) {
			    if(strncmp(carteirinha,x.carteirinha, strlen(carteirinha)) == 0){
			        a=a+1;
		        }
	        }
		    if(a > 0){
			    printf("\n\n\tJa existe um usuario cadastrado com esse cpf: %s\n\n",carteirinha);
			    printf("\n\tCarteirinha Invalido !!!\n\n");
		    }
		}while(a > 0);
	        fseek(arq, 0, SEEK_END);
		    x.carteirinha= ftell(arq) / sizeof(usuario) + 1;
		    printf("\tCodigo do Usuario: %d\n\n", x.carteirinha);
		    printf("\n\nCarteirinha: %s \n",carteirinha);
	        strcpy(x.carteirinha,carteirinha);
		    printf("\nNome: ");
		    fflush(stdin);
		    gets(x.nome);

		while(num < 0 || num > 2){
			system ("cls");
			printf("\n\tOpcao Invalida!!\n\n");
            printf("\n\tDeseja Cadastrar outro Cliente ?\n\n");
            printf("\n\tDigite novamente:\n\n\n\t\t1 - Sim\n\n\t\t2 - Nao\n");
  			scanf("%d", &num);
			system("cls");
	    }
	}while(num==1);
}

void cadastrarLivro(void) {
    FILE * arq;
    livros x;
    int num=0;
	do{
		printf("\n\n\t     Cadastro de novo DVD \n\n");
		if ((arq = fopen(arquivoLivros, "ab")) == NULL) {
			fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoLivros);
		}
		fseek(arq, 0, SEEK_END);
		x.codigo = ftell(arq) / sizeof(livros) + 1;
	    system("cls");
	    printf("Cadastro de Livros\n\n");
	    printf("Codigo: %d\n\n", x.codigo);
	    printf("\nTitulo: ");
	    fflush(stdin);
		gets(x.titulo);
	    printf("\nGenero: ");
	    gets(x.genero);
	    printf("\nDuracao: ");
	    gets(x.paginas);
		fwrite(&x, sizeof(livros), 1, arq);
    	system("cls");
		printf("\n\n\tLivro Cadastrado Com Sucesso!\n\n");
		fclose(arq);
		printf("\n\tDeseja Cadastrar outro Livro ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num);
		while(num < 0 || num > 2){
  			system ("cls");
			printf("\n\tOpcao Invalida!!\n\n\tDigite novamente:\n\n\t\t1-Sim\n\n\t\t2- Nao\n");
		    scanf("%d", &num);
        }
	}while(num==1);  
}
