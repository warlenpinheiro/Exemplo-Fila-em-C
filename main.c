#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <math.h>
#include <string.h>

int main()
{
    Fila f;
    Conteudo c=NULL;
    f=new_fila();
    insercao_do_arquivo(f);
    menu(f,c);
    n_free(c);
    q_free(f);
    return 0;
}
