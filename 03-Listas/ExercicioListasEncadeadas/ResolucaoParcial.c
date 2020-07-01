#include <stdio.h>
#include <stdlib.h>

struct ELEMENTO{
    char nome[101];
    char telefone[11];
    char endereco[101];
    unsigned int cep;
    char data[11];

    struct ELEMENTO *prox;
};

typedef struct ELEMENTO Lista;

Lista *criaElemento();
Lista *inserir(Lista *lista, Lista *novo);
void printLista(Lista *lista);
void limpar(Lista *lista);

int main()
{
    int op;
    Lista *contatos;
    Lista *novo;

    contatos = NULL;

    do{
        printf("\n\n\n1 - Inserir novo contato\n");
        printf("2 - Remover contato\n");
        printf("3 - Buscar contato\n");
        printf("4 - Listar contatos\n");
        printf("5 - Sair\n\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            novo = criaElemento();
            contatos = inserir(contatos, novo);
            break;
        case 2:
            printf("remover contato");
            break;
        case 3:
            printf("buscar contato");
            break;
        case 4:
            printLista(contatos);
            break;
        case 5:
            limpar(contatos);
            break;
        default:
            printf("Opcao invalida!\n\n");
        }
    }while(op != 5);

    return 0;
}

Lista *criaElemento()
{
    Lista *novo;

    novo = (Lista *) malloc(sizeof(Lista));

    if(novo == NULL)
        exit(-1);

    novo->prox = NULL;

    getchar();
    printf("Nome completo: ");
    scanf("%[^\n]", novo->nome);

    getchar();
    printf("Telefone: ");
    scanf("%[^\n]", novo->telefone);

    getchar();
    printf("Endereco: ");
    scanf("%[^\n]", novo->endereco);

    printf("CEP: ");
    scanf("%d", &(novo->cep));

    getchar();
    printf("Data de nascimento: ");
    scanf("%[^\n]", novo->data);

    return novo;
}

Lista *inserir(Lista *lista, Lista *novo)
{
    novo->prox = lista;

    return novo;
}

void printLista(Lista *lista)
{
    Lista *aux;

    printf("\n\nContatos:\n\n");

    for(aux = lista; aux != NULL; aux = aux->prox)
    {
        printf("Nome: %s\n", aux->nome);
        printf("Telefone: %s\n", aux->telefone);
        printf("Endereco: %s\n", aux->endereco);
        printf("CEP: %u\n", aux->cep);
        printf("Data de nascimento: %s\n\n", aux->data);
    }
}

void limpar(Lista *lista)
{
    Lista *aux = lista;

    while(lista != NULL)
    {
        aux = aux->prox;
        free(lista);
        lista = aux;
    }
}
