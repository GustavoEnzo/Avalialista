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

void lista_imprime(Lista *l) // loop para percorrer a lista novamente e antes da inversào
{
    Lista *p; /* variavel auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox)
        printf("num = %d\n", p->num);
}

Lista *inverte(Lista *l)
{

    Lista *nova = cria_lista();
    Lista *p;

    for (p = l; p; p = p->prox)
        nova = lista_insere(nova, p->num);
    return nova;
}

int main(void)
{
    Lista *l;

    l = cria_lista();
    l = lista_insere(l, 19);
    l = lista_insere(l, 37);
    l = lista_insere(l, 64);
    l = lista_insere(l, 231);
    l = lista_insere(l, 987);

    printf("\nLista:\n");
    lista_imprime(l);

    Lista *invertida = inverte(l);
    printf("\nLista depois da invercao:\n");

    lista_imprime(invertida);

    free(invertida);
    return 0;
}