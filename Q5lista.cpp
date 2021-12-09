#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *prox;
} Lista;

Lista *cria_lista()
{
    return NULL;
}

Lista *lista_insere(Lista *l, int i) // variaveis para o ponteiro novo
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->num = i;
    novo->prox = l;
    return novo;
}

Lista *removeNegativo(Lista *i)
{
    Lista *ultimo = NULL;
    while (1)
    {

        if (i->num < 0)
        {
            if (ultimo == NULL)
            {
                return i->prox;
            }

            ultimo->prox = i->prox;
        }
        ultimo = i;
        i = i->prox;
        if (i == NULL)
        {
            break;
        }
    }
}

void lista_imprime(Lista *l) // loop para percorrer a lista novamente e antes da inversào
{
    Lista *p; /* variavel auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox)
        printf("num = %d\n", p->num);
}

int main(void)
{

    Lista *l;

    l = cria_lista();
    l = lista_insere(l, 19);
    l = lista_insere(l, -22);
    l = lista_insere(l, 64);
    l = lista_insere(l, 231);
    l = lista_insere(l, 987);

    removeNegativo(l);
    printf("\nLista:\n");
    lista_imprime(l);

    return 0;
}