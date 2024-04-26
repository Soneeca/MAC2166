#include <stdio.h>
#include <stdlib.h>

/*
  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP,
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA.
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES
  DESSE EP E QUE PORTANTO NÃO CONSTITUEM DESONESTIDADE ACADÊMICA
  OU PLÁGIO.
  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS AS CÓPIAS
  DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO E
  DESONESTIDADE ACADÊMICA SERÃO TRATADOS SEGUNDO OS CRITÉRIOS
  DIVULGADOS NA PÁGINA DA DISCIPLINA.
  ENTENDO QUE EPS SEM ASSINATURA NÃO SERÃO CORRIGIDOS E,
  AINDA ASSIM, PODERÃO SER PUNIDOS POR DESONESTIDADE ACADÊMICA.

  Nome : Pedro Ian de Almeida Soares
  NUSP : 12554327
  Turma: 03
  Prof.: Alair Pereira do Lago

  Referências: Com exceção das rotinas fornecidas no enunciado
  e em sala de aula, caso você tenha utilizado alguma refência,
  liste-as abaixo para que o seu programa não seja considerado
  plágio ou irregular.

  Exemplo:
  - O algoritmo Quicksort foi baseado em
  http://www.ime.usp.br/~pf/algoritmos/aulas/quick.html
*/

/***************************************************************/
/**                                                           **/
/**   Pedro Ian de Almeida Soares       Número USP 12554327   **/
/**   Exercício-Programa 01                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/


int main()
{
    int x;                         /** Variavel que armazena o numero que o codigo analisara quantas vezes ele esta contido em S  **/
    int S = 1;                     /** Variavel que armazena os numemeros que o codigo comparará com x                            **/
    int c = 0;                     /** Variabel que conta quantas vezes x aparece em S                                            **/

    scanf("%d", &x);               /** Scaneando o input do usuario para atribuir a x em comparar com S                           **/

    while(S != 0){                 /** While determina que os comandos continuarão até S ser igual a 0                            **/
        scanf("%d", &S);           /** Scan que enxerga numero inserido pelo usuario para ser analisado depois                    **/
        if (x == S){               /** If que determina que se x foir igual a S c aumenta uma unidade                             **/
            c = c + 1;
        }
    }

    printf("%d", c);               /** Print que imprime ao usuario quantas vezes x aparece em S                                  **/
    return 0;
}
