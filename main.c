#include<stdio.h>
#include<stdlib.h>
#include "funcoes.h"
#define ERRO -1
#define CORRETO 1

int main(void)
{
    gancho *cabeca = cria_cabeca();
    HEAD *head = cria_head();
    char mensagem[100];
    int op = 0;
    while (op != 3)
    {
        fflush(stdin);
        printf("Digite...\n1 - commit\n2 - ver log\n3 - Sair do programa\n");
        printf("Aguardando comando: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            fflush(stdin);
            printf("Digite: ");
            gets(mensagem);
            commit(mensagem, cabeca, head);
            break;

            case 2:
            percorre_git(cabeca);
            break;
        }
        printf("\n");
    }
}