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

Lista *juntarLista(Lista *l1, Lista *l2)
{
    Lista *aux = l1;
    while (l1->prox != NULL)
    {
        l1 = l1->prox;
    }
    l1->prox = l2;
    return aux;
}

void lista_imprime(Lista *l) // loop para percorrer a lista novamente e antes da inversào
{
    Lista *p; /* variavel auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox)
        printf("num = %d\n", p->num);
}

int main(void)
{
    Lista *l, *g, *res;

    l = cria_lista();
    l = lista_insere(l, 19);
    l = lista_insere(l, -22);
    l = lista_insere(l, 64);
    l = lista_insere(l, 231);
    l = lista_insere(l, 987);

    g = cria_lista();
    g = lista_insere(g, 21);
    g = lista_insere(g, 33);
    g = lista_insere(g, 72);
    g = lista_insere(g, 128);
    g = lista_insere(g, 571);

    res = juntarLista(l, g);
    printf("\nLista:\n");
    lista_imprime(res);

    return 0;
}