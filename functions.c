#include "headers.h"
#include <string.h>

/*Criando a fila */
Fila new_fila(){
    Fila aux;
    aux=(Fila)malloc(sizeof(struct fila));
    aux->size=0;
    aux->tail=NULL;
    aux->head=NULL;
    return aux;
}

void insercao_do_arquivo(Fila f){
    FILE *arquivo;
    Conteudo c;
    arquivo=fopen("paises.txt","r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    do{
        c=(Conteudo)malloc(sizeof(struct conteudo));
        if(fscanf(arquivo,"%s %s %c %f",c->nome_pais,c->idioma,&c->grupo,&c->populacao)!=EOF)
            inserir(f,c);
        else
            break;
        fflush(stdin);
    }while(1);
}

/*Inserindo na fila*/
void inserir(Fila f,Conteudo C){
    Conteudo aux;
    aux=(Conteudo)malloc(sizeof(struct conteudo));
    aux=C;
    aux->prox=NULL;
        if(verifica_vazia(f)){
            f->head=aux;
            f->tail=aux;
        }
        else{
            f->tail->prox=aux;
            f->tail=aux;
        }
        f->size++;
}
/*Buscando uma populacao na fila*/
void buscar(Fila f,float populacao){
    Conteudo aux;
    int cont=0;
    for(aux=f->head;aux!=NULL;aux=aux->prox){
        if(populacao==aux->populacao){
            printf("Pais encontrado: \n\n");
            printf("  Nome:%s",aux->nome_pais);
            printf("  Grupo:%c",aux->grupo);
            printf("  Populacao:%0.3f",aux->populacao);
            printf("  Idioma:%s\n\n",aux->idioma);
            cont++;
        }
    }
    if(cont==0){
        printf("Não existe um país com essa populacao nos dados atuais\n");
    }
}

//retorna 1 se a fila esta vazia ou retorna 0 se a fila contem elementos*/
int verifica_vazia(Fila f){
    if(f->size==0){
        return 1; //não contem elementos
    }
    else{
        return 0; //contem elementos
    }
}
/*Retorna o tamanho da fila*/
int verifica_tamanho(Fila f){
    return f->size;
}

//Exibi os elementos presentes na fila
void exibir(Fila f){
    Conteudo aux;
    aux=f->head;
    printf("                  Dados a serem exibidos \n\n");
    while(aux != NULL){
        printf("  Nome: %s", aux->nome_pais);
        printf("  Grupo: %c",aux->grupo);
        printf("  Populacao: %0.3f",aux->populacao);
        printf("  Idioma: %s\n\n",aux->idioma);
        aux=aux->prox;
    }
}
/*Tem como finalidade encontrar a posicao em que o as populacoes são iguais*/
int procurar_populacao(Fila f,float populacao){
    Conteudo aux;
    int posicao=0;
    for(aux=f->head;aux!=NULL;aux=aux->prox){
        if(populacao==aux->populacao){
            return posicao;
            break;
        }
        posicao++;
    }
    return -1;
}
void remover_elemento(Fila f,float populacao){
    int posicao,i=1;
    posicao=procurar_populacao(f,populacao);
    if(posicao < 0 || posicao >= f->size){
        printf("Erro ao obter a posicao\n");
        return;
    }
    Conteudo aux1;
    Conteudo aux2;
    aux1 = f->head;
    f->size--;
    if(posicao == 0) {
        aux1 = f->head->prox;
        free(f->head);
        f->head = aux1;
        return;
    }
    while(i < posicao) {
        aux1 = aux1->prox;
        i++;
    }
    aux2 = aux1->prox;
    aux1->prox = aux2->prox;
    if(aux2->prox != NULL){
        aux2->prox = aux1;
    }
    free(aux2);
}

//Calculando a população média
float pop_media(Fila f){
    Conteudo aux;
    float contador=0;
    aux=f->head;
    while(aux != NULL){
        contador = contador + aux->populacao;
        aux=aux->prox;
    }

    contador = contador/f->size;

    return contador;
}

//Somando a população de todos os paises
float soma_pop(Fila f){
    Conteudo aux;
    float contador=0;
    aux=f->head;
    while(aux != NULL){
        contador = contador + aux->populacao;
        aux=aux->prox;
    }

    return contador;
}

//Buscando idioma mais falado
void id_mais_falado(Fila f){
    Conteudo aux, aux2;
    char idioma_f[30];
    int contador = 0, contador2=0;
    aux = f->head;
    aux2 = f->head;
    while(aux!=NULL){
        while(aux2!=NULL){
            if(strcmp(aux->idioma, aux2->idioma) == 0){
                contador++;
            }
            aux2=aux2->prox;
        }
        if(contador>contador2){
            strcpy(idioma_f, aux->idioma);
            contador2=contador;
        }
        contador=0;
        aux=aux->prox;
        aux2=f->head;
    }

    printf("O idioma mais falado eh: %s\n\n", idioma_f);
}

//Buscando o pais mais populoso
void pais_mais_p(Fila f){
    Conteudo aux;
    char pais[30];
    float contador = 0;
    aux = f->head;
    while(aux!=NULL){
        if(aux->populacao>contador){
            strcpy(pais, aux->nome_pais);
            contador=aux->populacao;
        }
        aux=aux->prox;
    }

    printf("O pais mais populoso eh: %s\tCom %0.2f Milhoes de Habitantes\n\n", pais, contador);

}

void n_free(Conteudo C){
    if(C==NULL){
        return;
    }
    n_free(C->prox);
    free(C);
}

void q_free(Fila f){
    n_free(f->head);
    free(f);
}

void menu(Fila f, Conteudo c){
    int opcao;
    printf("***********Bem vindo Visitante**********\n\n\n");
    printf("----------------------------------------\n\n\n");
    printf("Digite a opcao desejada:\n\n\n");
    printf("Digite 1 para a primeira parte do trabalho\n");
    printf("Digite 2 para a segunda parte do trabalho\n");
    printf("Digite 3 para a terceira parte do trabalho\n");
    printf("Digite 4 caso deseje encerrar\n");
    printf("ENTRADA: ");
    scanf("%d", &opcao);
    if(opcao==1){
        system("cls");
        menu_esboco(f, c);
    }
    else if(opcao==2){
        system("cls");
        printf("Em construcao!\n\n");
        menu(f, c);
    }
    else if(opcao==3){
        system("cls");
        printf("Em construcao!\n\n");
        menu(f, c);
    }
    else if(opcao==4){
        exit(1);
    }
    else{
        system("cls");
        printf("Voce digitou uma opcao invalida\n\n");
        menu(f, c);
    }
}



void menu_esboco(Fila f,Conteudo c){
    printf("***************Trabalho Prático - Parte 1 - Turma 33 - Grupo 6 - SI02***************\n");
    printf("--------------------------------------------------------------------------------\n");
    int opcao,i;
    printf("                           Programa fila simples \n\n");
    do{
        printf("Digite 1 para inserir\n");
        printf("Digite 2 para mostrar\n");
        printf("Digite 3 para buscar por populacao\n");
        printf("Digite 4 para verificar o numero de paises\n");
        printf("Digite 5 para verificar se a fila esta vazia\n");
        printf("Digite 6 para verificar o pais mais populoso\n");
        printf("Digite 7 para saber a populacao media, idioma mais falado e soma da populacao de todos os paises\n");
        printf("Digite 8 para voltar ao menu anterior\n");
        printf("Digite 9 para remover um pais por sua populacao\n");
        printf("Digite 0 para liberar a memoria utilizada e sair\n");
        printf("ENTRADA: ");

        scanf("%d",&opcao);
        fflush(stdin);
        printf("--------------------------------------------------------------------------------\n");
        if(opcao==1){
            system("cls");
            c=(Conteudo)malloc(sizeof(struct conteudo));
            printf("Digite o nome do pais: ");
            fgets(c->nome_pais,30,stdin);
            fflush(stdin);
            for(i=0;c->nome_pais[i] != '\n';i++);
            c->nome_pais[i] = '\0';
            printf("Digite o grupo do país: ");
            scanf("%c",&c->grupo);
            fflush(stdin);
            printf("Digite o idioma do país: ");
            fgets(c->idioma,30,stdin);
            printf("Digite a população do pais: ");
            scanf("%f",&c->populacao);
            fflush(stdin);
            inserir(f,c);
            printf("\n");
        }
        else if(opcao==2){
            system("cls");
            exibir(f);
        }
        else if(opcao==3){
            system("cls");
            float populacao;
            printf("Digite o tamanho da populacao do pais que voce deseja buscar: ");
            scanf("%f",&populacao);
            fflush(stdin);
            buscar(f,populacao);
        }
        else if(opcao==4){
             system("cls");
             printf("O numero de paises na copa eh: %d\n\n",verifica_tamanho(f));
        }
        else if(opcao==5){
            system("cls");
            if(verifica_vazia(f)==1){
                printf("A fila esta vazia\n\n");
            }
            else{
                printf("A fila esta com elementos\n\n");
            }
        }
        else if(opcao==6){
            system("cls");
            pais_mais_p(f);
        }
        else if(opcao==7){
            system("cls");
            printf("A populacao media nessa copa eh de: %0.2f\n\n", pop_media(f));
            id_mais_falado(f);
            printf("A soma de toda a populacao dos paises da copa eh: %0.2f\n\n", soma_pop(f));
        }
        else if(opcao==8){
            system("cls");
            menu(f,c);
        }
        else if(opcao==9){
            float populacao;
            printf("Digite a populacao que voce deseja remover: ");
            scanf("%f",&populacao);
            remover_elemento(f,populacao);
        }
        else if(opcao==0){
            exit(1);
        }
        else{
            printf("Voce nao digitou uma opcao valida!\n\n");
        }

    }while(opcao!=0);
}
