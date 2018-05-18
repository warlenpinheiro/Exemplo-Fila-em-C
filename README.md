# Exemplo-Fila-em-C
Exercicio proposto na Universidade Federal de Ouro Preto de uma estrutura de Fila para Disciplina de AEDS:

Na Copa de Futebol que ocorrerá em 2018 na Rússia, modelaremos os times de cada país com as seguintes características
(TAD PAIS):
1. Nome do país com no máximo 12 posições
2. Grupo do país que poderá ser umas dessas letras: ’A’, ’B’, ’C’, ’D’, ’E’, ’F’ ou ’H’
3. Idioma falado no país com no máximo 11 posições
4. População do país em milhões, no formato 999.999 - com 3 casas decimais
Fazer um sistema que possua no programa principal os itens de execução na ordem abaixo (menu):

1. Ler todos os países gravados em um arquivo texto de nome “paises.txt” inserindo cada um numa estrutura do tipo Fila simples. Cada linha do arquivo contém as informações de cada um dos países da copa.
Assim, cada linha terá os seguintes campos separados por um espaço em branco:
(a) Nome do país com no máximo 12 posições
(b) Grupo do país que poderá ser uma letra: ’A’ ou ’B’ ou ’C’ ou ’D’ ou ’E’ ou ’F’ ou ’H’
(c) Idioma falado no país com no máximo 11 posições
(d) População do país em milhões, no formato 999.999 - com 3 casas decimais

A ordem de leitura de cada linha, é ordem do item que será inserido na TAD. Ou seja, o primeiro país que é lido é o primeiro elemento da fila.

2. Exibir, à partir do primeiro elemento da estrutura montada em memória, todos os países, cada um em uma linha na tela.

3. Buscar um país dentro da estrutura construída, pela população. O valor do campo será digitado pelo usuário ao
realizar a busca, note que poderão ocorrer vários países com o valor do campo digitado. Exemplo: Buscar
os países com o idioma de Inglês ou buscar os países do grupo ’A’. Uma vez digitado o valor os países
encontrados serão exibidos na tela um por linha.

4. Remover um país através da população. Por exemplo: Remover todos os países
cujo idioma foi digitado como Árabe ou remover todos os países com o nome Brazil. Caso não existir,
exibir na tela que não foi encontrado.

5. Inserir um país na estrutura montada em memória.

6. Exibir o país de maior população.

7. Calcular e exibir na tela o número de países na estrutura, a população média entre todos os países na copa, a soma da população de todos os países da copa e o idioma mais falado.

8. Encerrar o programa liberando todas as estruturas alocadas dinamicamente.
