#include <stdio.h>

/**
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
**/

/***************************************************************/
/**                                                           **/
/**   Pedro Ian de Almeida Soares       Número USP 12554327   **/
/**   Exercício-Programa 02                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/

void PP( int n, int k, int N, int m, int a, int c, int r_0 )                                                     /** Função que vai fazer a Matriz igual pedido na parte 1 do ep                         **/
{

    int min;                                                                                                     /** O menor valor de f (função que sera imprimida)                                      **/
    int max;                                                                                                     /** O maior valor de f (função que sera imprimida)                                      **/
    int p;                                                                                                       /** O  valor do diametro pedido no ep                                                   **/
    int r;                                                                                                       /** O valor de r, depois de r0                                                          **/
    int f;                                                                                                       /** Função definida no ep, que usa r                                                    **/
    int contC;                                                                                                   /** Conta colunas para imprimir o numero certo delas                                    **/
    int contL;                                                                                                   /** Conta linhas para imprimir o numero certo delas                                     **/

    for (contL = 0 ; contL < N; contL++){                                                                        /** Usado para contar imprimir o numero certo de linha                                  **/

        r = ((((a)*(r_0))+ c) % m);                                                                              /** Faz o r a partir da definição dele no EP (usado só para criar max e min nessa parte)**/
        f = ((r*n)/m)+1;                                                                                         /** Faz o f a partir da definição dele no EP (usado só para criar max e min nessa parte)**/
        min = f;                                                                                                 /** Define o mínimo como sendo o primeiro f, para depois compara-los com os outros      **/
        max = f;                                                                                                 /** Define o máximo como sendo o primeiro f, para depois compara-los com os outros      **/

        for (contC = 0 ; contC < k; contC++){                                                                    /** Usado para contar imprimir o numero certo de colunas                                **/
            r = ((((a)*(r_0))+ c) % m);                                                                          /** Faz o r a partir da definição dele no EP                                            **/
            f = ((r*n)/m) + 1;                                                                                   /** Faz o f a partir da definição dele no EP                                            **/

            if (min >= f){                                                                                       /** Compara o minimo com o f se ele é maior ou igual, ou menor que ele                  **/
                min = f;                                                                                         /** Se o minimo for maior igual a f, então o f se torna o novo minimo                   **/
            }

            if (max <= f){                                                                                       /** Compara o máximo com o f se ele é menor ou igual, ou maior que ele                  **/
                max = f;                                                                                         /** Se o máximo for menor igual a f, então o f se torna o novo máximo                   **/
            }

            printf ("%5d ", f);                                                                                  /** Imprime o f na formatação pedida                                                    **/
            r_0 = r;                                                                                             /** Faz o r_0 assumir o valor de r, para assim o novo r usar o novo r_0 como base       **/

        }

        p = ((max - min) + 1);                                                                                   /** Calcula o p, ou diametro assim como pedido no EP                                    **/
        printf ("    ->");                                                                                       /** Imprime a seta até o diametro assim como pedido no EP                               **/
        printf ("%5d ", p);                                                                                      /** Imprime o Proprio P, ou dimatro, com espaçamento igual pedido **/
        printf ("\n");                                                                                           /** Imprime uma pulada de linha                                                         **/
    }
}

void ImprimeSequencia( int i, int j, int k, int s_i, int s_j, int s_k ) {                                        /** Programa dado pelo professor para organizar a impressão                             **/
    if ( i < j )
        if ( j < k )
            printf( "%d %d %d\n", s_i, s_j, s_k );
        else // k < j
            if ( i < k )
                printf( "%d %d %d\n", s_i, s_k, s_j );
            else // k < i
                printf( "%d %d %d\n", s_k, s_i, s_j );
    else // j < i
        if ( i < k )
            printf( "%d %d %d\n", s_j, s_i, s_k );
        else // i < j
            if ( j < k )
                printf( "%d %d %d\n", s_j, s_k, s_i );
            else // k < j
                printf( "%d %d %d\n", s_k, s_j, s_i );
    return;
}

int cont = 0;                                                                                                     /** Variável que guarda o numero de sequencias imprimidas para printar depois          **/

void SubSP ( int a, int b, int c, int n, int d)                                                                   /** Função usada para fornecer as variaveis que serão impressas pelo ImprimeSequencias **/
{
    int s_a, s_b, s_k, min;                                                                                       /** Variáveis pedidas no EP para serem manipuladas                                     **/
    if (c > a && c > b){                                                                                          /** Instruções de if dadas no EP **/
            for ( min = 1 ; min <= (n - d +1) ; min ++){                                                          /** Fica variando o valor minimo da linha subindo de 1 até o maximo limitado por d     **/
                s_a = min;                                                                                        /** Atribui a s_a o valor de minimo **/
                s_b = (s_a + d - 1);                                                                              /** Calcula s_b a partir de s_a e d **/

                for (s_k = s_a ; s_k <= s_b ; s_k++){                                                             /** Fica variando os valores de s_k entre s_a e s_k igual a especificação feita no Ep  **/
                    ImprimeSequencia (a, b, c, s_a, s_b, s_k);                                                    /** Chamada da função que imprime a sequencia                                          **/
                    cont = cont + 1;                                                                              /** Aumenta a contagem por 1                                                           **/
                }
            }
    }
    else if (c < a && c < b){                                                                                     /** Instruções de if dadas no EP                                                       **/
            for ( min = 1 ; min <= (n - d +1) ; min ++){                                                          /** Fica variando o valor minimo da linha subindo de 1 até o maximo limitado por d     **/
                s_a = min;                                                                                        /** Atribui a s_a o valor de minimo                                                    **/
                s_b = (s_a + d - 1);                                                                              /** Calcula s_b a partir de s_a e d                                                    **/

                for (s_k = (s_a+1) ; s_k < s_b ; s_k++){                                                          /** Fica variando os valores de s_k entre s_a e s_k igual a especificação feita no Ep  **/
                    ImprimeSequencia (a, b, c, s_a, s_b, s_k);                                                    /** Chamada da função que imprime a sequencia                                          **/
                    cont = cont + 1;                                                                              /** Aumenta a contagem por 1                                                           **/
                }
            }
    }
    else if (c > a && c < b){                                                                                     /** Instruções de if dadas no EP                                                       **/
            for ( min = 1 ; min <= (n - d +1) ; min ++){                                                          /** Fica variando o valor minimo da linha subindo de 1 até o maximo limitado por d     **/
                s_a = min;                                                                                        /** Atribui a s_a o valor de minimo                                                    **/
                s_b = (s_a + d - 1);                                                                              /** Calcula s_b a partir de s_a e d                                                    **/

                for (s_k = s_a ; s_k < s_b ; s_k++){                                                              /** Fica variando os valores de s_k entre s_a e s_k igual a especificação feita no Ep  **/
                    ImprimeSequencia (a, b, c, s_a, s_b, s_k);                                                    /** Chamada da função que imprime a sequencia                                          **/
                    cont = cont + 1;                                                                              /** Aumenta a contagem por 1                                                           **/
                }
            }
    }
    else if (c > b && c < a){                                                                                     /** Instruções de if dadas no EP                                                       **/
            for ( min = 1 ; min <= (n - d +1) ; min ++){                                                          /** Fica variando o valor minimo da linha subindo de 1 até o maximo limitado por d     **/
                s_a = min;                                                                                        /** Atribui a s_a o valor de minimo                                                    **/
                s_b = (s_a + d - 1);                                                                              /** Calcula s_b a partir de s_a e d                                                    **/

                for (s_k = (s_a+1) ; s_k <= s_b ; s_k++){                                                         /** Fica variando os valores de s_k entre s_a e s_k igual a especificação feita no Ep  **/
                    ImprimeSequencia (a, b, c, s_a, s_b, s_k);                                                    /** Chamada da função que imprime a sequencia                                          **/
                    cont = cont + 1;                                                                              /** Aumenta a contagem por 1                                                           **/
                }
            }
    }
}

void SP (int n, int d)                                                                                            /** Definição do segundo programa                                                      **/
{
    int k = 3, a, b, c, limmin, limmax;                                                                           /** Define as variaveis que vão ser manipuladas no programa                            **/

    for (a = 1 ; a <= 3 ; a++){                                                                                   /** Definido no EP o porque fazer esse for                                             **/
            if (a == 1){                                                                                          /** Definido no EP o porque fazer esse if                                              **/
                for (b = 2 ; b <= 3 ; b++){                                                                       /** Definido no EP o porque fazer esse for                                             **/
                    if (b == 2) {                                                                                 /** Definido no EP o porque fazer esse if                                              **/
                        c = 3;                                                                                    /** Definido no EP o porque fazer                                                      **/
                        SubSP(a, b, c, n, d);                                                                     /** Chama o a Sub de SP para automatizar o processo                                    **/
                    }
                    else {                                                                                        /** Definido no EP o porque fazer esse else                                            **/
                        c = 2;                                                                                    /** Definido no EP o porque fazer                                                      **/
                        SubSP(a, b, c, n, d);                                                                     /** Chama o a Sub de SP para automatizar o processo                                    **/
                    }
                }
            }

            else if (a == 2){                                                                                     /** Definido no EP o porque fazer esse else if                                         **/
                for ( b = 1 ; b <= 3; b += 2){                                                                    /** Definido no EP o porque fazer esse for                                             **/
                    if (b == 1) {                                                                                 /** Definido no EP o porque fazer esse if                                              **/
                        c = 3;                                                                                    /** Definido no EP o porque fazer                                                      **/
                        SubSP(a, b, c, n, d);                                                                     /** Chama o a Sub de SP para automatizar o processo                                    **/
                        }
                    else {                                                                                        /** Definido no EP o porque fazer esse else                                            **/
                        c = 1;                                                                                    /** Definido no EP o porque fazer                                                      **/
                        SubSP(a, b, c, n, d);                                                                     /** Chama o a Sub de SP para automatizar o processo                                    **/
                    }
                }
            }

            else if (a == 3){                                                                                     /** Definido no EP o porque fazer esse else if                                         **/
                for ( b = 1 ; b <= 2 ; b++ ){                                                                     /** Definido no EP o porque fazer esse for                                             **/
                    if (b == 1) {                                                                                 /** Definido no EP o porque fazer esse if                                              **/
                        c = 2;                                                                                    /** Definido no EP o porque fazer                                                      **/
                        SubSP(a, b, c, n, d);                                                                     /** Chama o a Sub de SP para automatizar o processo                                    **/
                    }
                    else {                                                                                        /** Definido no EP o porque fazer esse else                                            **/
                        c = 1;                                                                                    /** Definido no EP o porque fazer                                                      **/
                        SubSP(a, b, c, n, d);                                                                     /** Chama o a Sub de SP para automatizar o processo                                    **/
                    }
                }
            }
    }
    limmin = 3*2*(d-2)*(n-d+1);                                                                                   /** Calcula o limite minimo com a forma dada no EP                                     **/
    limmax = 3*3*d*n;                                                                                             /** Calcula o limite maximo com a forma dada no EP                                     **/
    printf ("Total de %d sequencias.", cont);                                                                     /** Imprime o total de sequencias contada pela variavel cont                           **/
    printf ("\n");                                                                                                /** Imprime uma pulada de linha                                                        **/
    printf ("Limites: %d e %d", limmin, limmax);                                                                  /** Imprime os limites maximos e minimos calculados anteriormente                      **/
}

void main (){                                                                                                     /** Define a função main como uma void, ou seja, não precisa de return em seu final    **/

    int QP;                                                                                                       /** Define a variavel QP que funciona para que o usuario escolha QP                    **/
    printf ("\n");                                                                                                /** Imprime uma pulada de linha                                                        **/
    printf ("Digite a parte desejada: 1 para primeira; 2 para segunda.");                                         /** Imprime na tela uma pergunta de qual parte o usuario deseja                        **/
    printf ("\n");                                                                                                /** Imprime uma pulada de linha                                                        **/
    scanf ("%d", &QP);                                                                                            /** Guarda a variavel do input do usuario                                              **/
    if (QP == 1){                                                                                                 /** Se essa variavel for 1 ele faz o caminho para executar a Primeira Parte ou PP      **/
            int n, k, N, m, a, c, r_0;                                                                            /** Define as variaveis que depois serão inseridas pelo usuário                        **/
            printf ("Digite parametros n, k, N, m, a, c, r_0:");                                                  /** Pede os parametros ao usuário                                                      **/
            printf ("\n");                                                                                        /** Imprime uma pulada de linha                                                        **/
            scanf ("%d %d %d %d %d %d %d", &n, &k, &N, &m, &a, &c, &r_0);                                         /** Guarda os parametros pedidos ao usuário em variaveis                               **/
            printf ("Recorrencia r <-- ( r x %d + %d ) mod %d a partir da semente %d.", a, c, m, r_0);            /** Imprime o texto assim como pedido no EP usando as variavéis                        **/
            printf ("\n");                                                                                        /** Imprime uma pulada de linha                                                        **/
            printf ("As %d sequencias de %d sorteios (com repeticao) em [ 1 .. %d ] e seus diametros:", N, k, n); /** Imprime o texto assim como pedido no EP usando as variavéi                         **/
            printf ("\n");                                                                                        /** Imprime uma pulada de linha                                                        **/
            PP(n, k, N, m, a, c, r_0);                                                                            /** Executa a função PP ou Primeira Parte definida anteriormente                       **/

    }
    if (QP == 2){                                                                                                 /** Se a variavel QP for 2 ele faz o caminha para executar a Segunda Parte ou SP       **/
            int n, k = 3, d, casod1 = 1;                                                                          /** Define as variveis utilizadas se o usuario escolher a parte 2                      **/
            printf ("Digite parametros n, d:");                                                                   /** Pede ao usuario os parametros                                                      **/
            printf ("\n");                                                                                        /** Imprime uma pulada de linha                                                        **/
            scanf ("%d %d", &n, &d);                                                                              /** Atribui os valores inseridos pelos usarios em variaveis                            **/
            printf ("Listagem das sequencias de S( %d , %d , %d ) (com repeticao):", n, k, d);                    /** Imprime o texto assim como pedido no EP usando as variavéi                         **/
            printf ("\n");                                                                                        /** Imprime uma pulada de linha                                                        **/
            if (d == 1){                                                                                          /** Se o diametro for igual a 1 o programa entra em um caso excepcional                **/
                for ( casod1 = 1 ; casod1 <= n ; casod1 ++ ){                                                     /** Faz a variavel casod1 ir de 1 até n em uma unidade por unidade para fazer a matriz **/
                    printf ("%d %d %d\n", casod1, casod1, casod1);                                                /** Printa uma linha da matriz pedida quando diametro é 1                              **/
                }
                printf ("Total de %d sequencias.", n);                                                            /** Imprime o numero total de sequencias assim como mostrado na correção automática    **/
            }
            else SP (n, d);                                                                                       /** Executa SP ou Segunda Parte se o diametro é diferente de 1                         **/
    }

}
