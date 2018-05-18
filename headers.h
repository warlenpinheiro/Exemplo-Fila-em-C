#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct conteudo{
    char nome_pais[13];
    char grupo;
    char idioma[12];
    float populacao;
    struct conteudo *prox;
};
typedef struct conteudo *Conteudo;

struct fila{
    int size;
    struct conteudo *tail;
    struct conteudo *head;
};

typedef struct fila *Fila;


/*Criando a fila */
Fila new_fila();

/*Inserindo na fila */
void inserir(Fila f,Conteudo C);

/*Tentando inserir o arquivo*/
void insercao_do_arquivo(Fila f);

/*Busca um no da fila levando como paramentro a população*/
void buscar(Fila f,float populacao); //Implementar

/*retorna 1 se a fila esta vazia ou retorna 0 se a fila contem elementos*/
int verifica_vazia(Fila f);

/*Retorna o tamanho da fila*/
int verifica_tamanho(Fila f);

/*mostra os dados de todos os paises que estão na fila*/
void exibir(Fila f);

/*Tem como finalidade remover um nó do final da fila levando como consideração a população*/
void remover(Fila f,int recebe);

/*Menu para interação com o usuário*/
void menu_esboco(Fila f,Conteudo C);

/*População Média*/
float pop_media(Fila f);

/*Somatorio da população*/
float soma_pop(Fila f);

/*Idioma mais falado*/
void id_mais_falado(Fila f);

/*Verifica pais mais populoso*/
void pais_mais_p(Fila f);

void menu(Fila f, Conteudo c);

//Remove um elemento da fila
void remover_elemento(Fila f,float populacao);

//Função para buscar um pais por sua população
int procurar_populacao(Fila f,float populacao);

//Libera as memorias e encerra a fila
void n_free(Conteudo c);
void q_free(Fila f);
#endif // MAIN_H_INCLUDED
