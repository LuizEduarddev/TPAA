#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<conio.h>
#include "funcoes.h"
#define ERRO -1
#define CORRETO 1

struct lista
{
    char text[100];
    lista *proximo;
    char hash[10];
};

struct gancho
{
    lista *primeiro;
};

struct HEAD
{
    lista *repositorio;
};

gancho *cria_cabeca(void)
{
    gancho *cabeca = (gancho *)malloc(sizeof(gancho));
    cabeca->primeiro =  NULL;
    return cabeca;
}

HEAD *cria_head(void)
{
    HEAD *atual = (HEAD *)malloc(sizeof(HEAD));
    atual->repositorio =  NULL;
    return atual;
}

void commit(char *mensagem, gancho *cabeca, HEAD *head)
{
    lista *novo = (lista *)malloc(sizeof(lista));
    if (cabeca->primeiro == NULL)
    {
        strcpy(novo->hash, gera_hash(cabeca, novo->hash));
        cabeca->primeiro = novo;
        strcpy(novo->text, mensagem);
        novo->proximo = NULL;
        head->repositorio = novo;
    }
    else
    {
        head->repositorio->proximo = novo;
        head->repositorio = novo;
        strcpy(novo->text, mensagem);
        novo->proximo = NULL;
        strcpy(novo->hash, gera_hash(cabeca, novo->hash));
    }
}

char *gera_hash(gancho *cabeca, char *hash)
{
    char string[50];
    int resultado = 0;
    for (int i=0; i < 5; i++)
    {
        string[2 * i] = 48 + (rand() % 9);
        string[2 * i + 1] = 65 + (rand() % 26);
    }
    resultado = verifica_combinacao(string, cabeca);
    if (resultado == ERRO)
        hash = gera_hash(cabeca, hash);
    else
    {
        strcpy(hash, string);
        return hash;
    }
}

int verifica_combinacao(char *string, gancho *cabeca)
{
    lista *atual = cabeca->primeiro;
    int resultado = 0;
    if (cabeca->primeiro == NULL)
    {
        return CORRETO;
    }
    else
    {
        while (atual != NULL)
        {
            resultado = strcmp(atual->hash, string);
            if (resultado == 0)
            {
                return ERRO;
            }
            atual = atual->proximo;
        }
        return CORRETO;
    }
}

void percorre_git(gancho *cabeca)
{
    lista *atual = cabeca->primeiro;
    int list = 1;
    while (atual != NULL)
    {
        printf("%d commit\n", list);
        printf("commit: %s\n", atual->text);
        printf("Hash: %s\n", atual->hash);
        atual = atual->proximo;
        list++;
    }
}
