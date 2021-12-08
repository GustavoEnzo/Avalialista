#include <stdio.h>
#include <stdlib.h>

typedef struct faceUser
{
    char nome[50]; // Letra A da questào
    int id;
    int amigos[20];
    struct faceUser *prox;
} faceUser;

void printarDados(faceUser *user)
{

    while (user != NULL)
    {
        printf("%d-%s\n", user->id, user->nome);

        printf("amigos:\n");
        for (int i = 0; i < 20; i++)
        {
            if (user->amigos[i] == NULL)
            {
                break;
            }
            printf("\nID: %d", user->amigos[i]);
        }
        user = user->prox;
    }
}

faceUser *cadastrar()
{
    faceUser *novo = (faceUser *)malloc(sizeof(faceUser));
    printf("\nID:");
    scanf("%d", &novo->id);
    printf("\nNome:");
    scanf("%s", &novo->nome);
    novo->prox = NULL;

    for (int i = 0; i < 20; i++)
    {
        novo->amigos[i] = NULL;
    }

    return novo;
}

void Relaciona(int Amigo1, int Amigo2, faceUser *pFace)
{
    faceUser *user1 = NULL;
    faceUser *user2 = NULL;

    while (pFace->prox != NULL)
    {
        if (pFace->id == Amigo1)
        {
            user1 = pFace;
        }
        if (pFace->id == Amigo2)
        {
            user2 = pFace;
        }
        pFace = pFace->prox;
    }
    if (user2 == NULL)
    {
        pFace->prox = cadastrar();
        user2 = pFace->prox;
    }
    printf("-------");
    for (int i = 0; i < 20; i++)
    {
        if (user1->amigos[i] == NULL)
        {
            user1->amigos[i] = user2->id;
            break;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        if (user2->amigos[i] == NULL)
        {
            user2->amigos[i] = user1->id;
            break;
        }
    }

    /* }
     else
     {
         while (aux->prox != NULL)
         {
             aux = aux->prox;
         }

         aux->prox = malloc(sizeof(faceUser));
         *(aux->prox) = *(user2);
         aux->prox->prox = NULL;
     }

     aux = user2->amigos;
     while (aux->prox != NULL)
     {
         aux = aux->prox;
     }
     aux->prox = malloc(sizeof(faceUser));
     *(aux->prox) = *(user1);
     aux->prox->prox = NULL;*/
}

int main()
{
    faceUser *users = cadastrar();
    printf("-------");
    Relaciona(users->id, 2, users);
    printf("-------");
    printarDados(users);
}