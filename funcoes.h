#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct lista lista;
typedef struct gancho gancho;
typedef struct HEAD HEAD;
gancho *cria_cabeca(void);
HEAD *cria_head(void);
void commit(char *mensagem, gancho *cabeca, HEAD *head);
char *gera_hash(gancho *cabeca, char *hash);
int verifica_combinacao(char *string, gancho *cabeca);
void percorre_git(gancho *cabeca); 

#endif