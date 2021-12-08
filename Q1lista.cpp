#include <stdio.h>
#include <stdlib.h>

struct noDaLista
{
    char titulo[51];
    char autor[51];
    int ano;
    int quantidade;
    struct noDaLista *prox;
};
typedef struct noDaLista dados;

void printarDados(dados *cabeca)
{

    while (cabeca != NULL)
    {
        printf("%s-%s-%d-%d\n", cabeca->titulo, cabeca->autor, cabeca->ano, cabeca->quantidade);
        cabeca = cabeca->prox;
    }
}

dados *adicionarDadosini(dados *cabeca)
{
    // CRIA NOVO OBJETO
    dados *novo = malloc(sizeof(dados));
    printf("\nTitulo:");
    scanf("%s", &novo->titulo);
    printf("\nAutor:");
    scanf("%s", &novo->autor);
    printf("\nAno:");
    scanf("%d", &novo->ano);
    printf("\nQuantidade:");
    scanf("%d", &novo->quantidade);
    novo->prox = NULL;

    // SE A CABECA DA LISTA FOR NULL ATRIBUI O OBJETO NOVO
    if (cabeca == NULL)
    {
        cabeca = novo;
    }
    else
    {
        // SE NAO FOR PROCURO ULTIMO N LISTA E ATRIBUI O OBJETO NULL
        while (cabeca->prox != NULL)
        {
            cabeca = cabeca->prox;
        }
        cabeca->prox = novo;
    }

    return cabeca;
}
int totalLivros(dados *cabeca)
{
    int total = 0;
    while (cabeca != NULL)
    {
        total += cabeca->quantidade;
        cabeca = cabeca->prox;
    }
    return total;
}
void printarDadosPorAno(dados *cabeca, int ano)
{

    while (cabeca != NULL)
    {
        if (cabeca->ano == ano)
        {
            printf("%s-%s-%d-%d\n", cabeca->titulo, cabeca->autor, cabeca->ano, cabeca->quantidade);
        }

        cabeca = cabeca->prox;
    }
}

int main()
{
    dados *cabeca = NULL;
    int escolha = 1;
    while (escolha)
    {
        cabeca = adicionarDadosini(cabeca);
        printf("\nAdicionar outro?(0/1)");
        scanf("%d", &escolha);
    }

    printarDados(cabeca);
    int total = totalLivros(cabeca);
    printf("\nTotal de livro: %d", total);

    int pesquisaAno = 0;
    printf("\nProcurar por ano: ");
    scanf("%d", &pesquisaAno);
    printarDadosPorAno(cabeca, pesquisaAno);

    getch();
    return 0;
}