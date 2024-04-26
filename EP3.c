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
/**   Exercício-Programa 03                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/

int tam (int n)                                                                  /** Parte do código responsável por contar o tamanho de um numero                                                  **/
{
    int contagem = 0;                                                            /** Variavel que armazena a quantidade de digitos                                                                  **/
    int contador = 10;                                                           /** Variavel que é usada pra saber quantos digitos tem a partir da divisão                                         **/
    int resultado = 1;                                                           /** Numero inicial dividido pela variavel que tira os ultimos digitos                                              **/

    while (resultado != 0)                                                       /** While para contar o numero de digitos enquanto for diferente de 0                                              **/
    {
        contagem = (contagem+1);                                                 /** Sobe 1 unidade a contagem                                                                                      **/
        resultado = (n/contador);                                                /** Resultado vira n sem as unidades, e posteriormente sem as dezenas e etc                                        **/
        contador = (10*contador);                                                /** Contador fica 10 vezes mais alto para tirar mais numeros do n e armazenar em resultado                         **/
    }
    if (contagem > 2020)                                                         /** Define o tamanho maximo do vetor que vai ser criado                                                            **/
    {
        contagem = 2020;                                                         /** Deixa o tamanho máximo como 2020, já que todo vetor tem uma casa a mais que o tamanho do numero                **/
    }
return (contagem);                                                               /** Retorna o numero de unidades no numero n                                                                       **/
}

void imprimeNumerao(int num[], int tamNum)                                       /** Função que imprime um vetor ao receber o vetor e a quantidade de unidades nele                                 **/
{
    int a;                                                                       /** Variável usada pra manipular outros numeros                                                                    **/

    while (num[tamNum] == 0)                                                     /** While para tirar os 0 do final do numero, que não representam nada                                             **/
    {
        tamNum = (tamNum - 1);                                                   /** Diminui o tamanho que sera lido do vetor                                                                       **/
        if (tamNum == -1)                                                        /** Caso o tamanho que do numero seja -1                                                                           **/
        {
            break;                                                               /** Para o While                                                                                                   **/
        }
    }

    if (tamNum != -1)                                                            /** Se o tamanho for maior que 1                                                                                   **/
    {
        if (num[0] == 1)                                                         /** Se o primeiro digito do vetor for 1                                                                            **/
        {
            num[tamNum] = -num[tamNum];                                          /** A ultima unidade vira ela negativa                                                                             **/
            num[0] = 0;                                                          /** Troca o primeiro digito para 0                                                                                 **/
        }

        for (a = tamNum; a >= 1; a--)                                            /** Faz um a(variavel) que passa pelo final do tamanho do vetor                                                    **/
        {
            printf ("%d", num[a]);                                               /** Imprime o numero selecionado por a                                                                             **/
        }
    }
    else{                                                                        /** Caso o tamanho seja -1                                                                                         **/
        printf ("0");                                                            /** Imprime o numero 0                                                                                             **/
    }
}

int criaNumerao(int n, int vetorn[])                                             /** Cria um vetor a partir de um numero n                                                                          **/
{
    int separador;                                                               /** Variavel usada para percorrer todos os numeros do vetor                                                        **/
    int num0 = 0;                                                                /** Variavel que armazena o numero calculado anteriormente em n1                                                   **/
    int num1 = 0;                                                                /** Variavel que armazena os ultimos x numeros de n                                                                **/
    int nfinal;                                                                  /** Variavel que armazena o numero que sera colocado no vetor                                                      **/
    int mdez = 10;                                                               /** Variavel que vai extrair a parte do numero para n1                                                             **/
    int contagem = tam(n);                                                       /** Guarda o tamanho do numero                                                                                     **/

    if (n < 0)                                                                   /** Se n for negativo                                                                                              **/
    {
        n = -n;                                                                  /** N vira positivo                                                                                                **/
        vetorn[0] = 1;                                                           /** E o primeiro numero do vetor vira 1                                                                            **/
    }
    else{                                                                        /** Se n for positivo ou igual a zero                                                                              **/
        vetorn[0] = 0;                                                           /** O primeiro elemento vira zero                                                                                  **/
    }

    for (separador = 1; separador <= contagem; separador++){                     /** Faz separador ir de 1 até o tamanho de n                                                                       **/
            num1 = (n % mdez);                                                   /** Pega as ultimas unidades de n                                                                                  **/
            nfinal = ((num1 - num0) / (mdez/10));                                /** Pega n1 e tira n0 dele, depois divide por 1/10 de mdez                                                         **/
            num0 = num1;                                                         /** Pega o valor anterior de n1                                                                                    **/
            vetorn[separador] = nfinal;                                          /** Atribui o valor de n final a casa separador do vetor                                                           **/
            mdez = mdez*10;                                                      /** Aumenta a variavel em 10x                                                                                      **/
    }
    return (contagem);                                                           /** Retorna o tamanho de n                                                                                         **/
}

void imprimeVetor (int num[], int tamNum)                                        /** Função que arruma numeros maiores que 10 em vetor                                                              **/
{
    int a;                                                                       /** Variavel feita pra percorrer o vetor                                                                           **/
    int dezena;                                                                  /** Variavel que guarda as dezenas do numero                                                                       **/
    int unidade;                                                                 /** Variavel que guarda as unidade do numero                                                                       **/

    for (a = 1; a < tamNum; a++)                                                 /** A variando de 1 até menos que tamanho do numero                                                                **/
    {
        if (num[a] >= 10 || num[a] <= -10)                                       /** Se o modulo do numero for maior que 10                                                                         **/
        {
            dezena = (num[a]/10);                                                /** Calcula a dezena para ser passado para o proximo numero do vetor como unidade                                  **/
            unidade = (num[a]%10);                                               /** Calcula a unidade que será mantida no vetor                                                                    **/
            num[a] = unidade;                                                    /** Troca o numero de posição a do vetor pela unidade                                                              **/
            num[(a+1)] = (num[(a+1)] + dezena);                                  /** Variavel usada para percorrer os vetores                                                                       **/
        }
    }
    for (a = 1; a < tamNum; a++)                                                 /** A variando de 1 até menos que tamanho do numero                                                                **/
    {
        if (num[a] < 0)                                                          /** Se o numero for menor que 0                                                                                    **/
        {
            num[(a+1)] = (num[(a+1)] - 1);                                       /** É subtraido 1 do numero da frente                                                                              **/
            num[a] = (num[a] + 10);                                              /** O numero é adicionado 10 unidades                                                                              **/
        }
    }

}

void soma(int a[], int tamA, int b[], int tamB)                                  /** Função soma de dois vetores                                                                                    **/
{
    int *menor;                                                                  /** Ponteiro que aponta para o menor vetor                                                                         **/
    int *maior;                                                                  /** Ponteiro que aponta para o maior veto                                                                          **/
    int Tmaior = tamB;                                                           /** Guarda o tamanho do maior valor, que inicialmente é B                                                          **/
    int Tmenor = tamB;                                                           /** Guarda o tamanho do menor valor, que inicialmente é B                                                          **/
    int passo;                                                                   /** Variavel usada pra contar o passo do andamento do vetor                                                        **/
    int d;                                                                       /** Variavel usada pra manipular os vetores a e b                                                                  **/

    maior = &b;                                                                  /** Aponta os ponteiros de maior e menor para b                                                                    **/
    menor = &b;                                                                  /** Aponta os ponteiros de maior e menor para b                                                                    **/

    if (tamA >= tamB)                                                            /** Se tamanho de A maior que B                                                                                    **/
    {
        if (tamA == tamB)                                                        /** Se tamanho de A igual de B                                                                                     **/
        {
            for (passo = tamA; passo > 0; passo--)                               /** Para o passo igual a tamanho de a, indo até 1                                                                  **/
            {
                if (a[passo] > b[passo])                                         /** Caso o algorismo passo do vetor a for maior que o de b                                                         **/
                {
                    maior = &a;                                                  /** Faz o ponteiro maior receber o vetor a                                                                         **/
                    Tmaior = tamA;                                               /** Tmaior vira tamA                                                                                               **/
                    menor = &b;                                                  /** Faz o ponteiro menor receber o vetor b                                                                         **/
                    Tmenor = tamB;                                               /** Tmenor vira tamB                                                                                               **/
                    break;                                                       /** Para o for                                                                                                     **/
                }
                else if (a[passo] < b[passo])                                    /** Caso o algorismo passo do vetor a for menor que o de b                                                         **/
                {
                    maior = &b;                                                  /** Faz o ponteiro maior receber o vetor b                                                                         **/
                    Tmaior = tamB;                                               /** Tmaior vira tamB                                                                                               **/
                    menor = &a;                                                  /** Faz o ponteiro menor receber o vetor a                                                                         **/
                    Tmenor = tamA;                                               /** Tmenor vira tamA                                                                                               **/
                    break;                                                       /** Para o for                                                                                                     **/
                }
            }
        }
        else                                                                     /** Caso tamanho de A for maior que tamanho de B                                                                   **/
        {
            menor = &b;                                                          /** Faz o ponteiro menor receber o vetor b                                                                         **/
            Tmenor = tamB;                                                       /** Tmenor vira tamB                                                                                               **/
            maior = &a;                                                          /** Faz o ponteiro maior receber o vetor a                                                                         **/
            Tmaior = tamA;                                                       /** Tmaior vira tamA                                                                                               **/
        }
    }
    else                                                                         /** Caso tamanho de B for maior que tamanho de A                                                                   **/
    {
        menor = &a;                                                              /** Faz o ponteiro menor receber o vetor a                                                                         **/
        Tmenor = tamA;                                                           /** Tmenor vira tamA                                                                                               **/
        maior = &b;                                                              /** Faz o ponteiro maior receber o vetor b                                                                         **/
        Tmaior = tamB;                                                           /** Tmaior vira tamB                                                                                               **/
    }

    int c[(Tmaior+1)];                                                           /** Cria um novo vetor com o tamanho do vetor maior mais 1                                                         **/

    if (a[0] == 0 && b[0] == 0)                                                  /** Caso o primeiro elemento for igual a 0 nos dois vetores                                                        **/
    {
        c[0] = 0;                                                                /** Primeiro elemento do vetor c vira 0                                                                            **/
        for (d = 1; d <=Tmenor; d++)                                             /** Para d indo de 1 até o menor tamanho                                                                           **/
        {
            c[d] = (a[d] + b[d]);                                                /** Faz o valor de c ser a + b em cada elemento                                                                    **/
        }
        if (maior == &a){                                                        /** Se o ponteiro maior apontar para o vetor a                                                                     **/
            for (d = (Tmenor+1); d <= Tmaior; d++)                               /** Para d variando de T menor mais 1 até T maior                                                                  **/
            {
                c[d] = a[d];                                                     /** Faz um elemento do vetor c ser igual a um elemento do vetor a                                                  **/
            }
        }
        else if (maior == &b){                                                   /** Se o ponteiro maior apontar para o vetor b                                                                     **/
            for (d = (Tmenor+1); d <= Tmaior; d++)                               /** Para d variando de T menor mais 1 até T maior                                                                  **/
            {
                c[d] = b[d];                                                     /** Faz um elemento do vetor c ser igual a um elemento do vetor b                                                  **/
            }
        }
    }
    else if (a[0] == 0 && b[0] == 1)                                             /** Caso o primeiro numero de a for 0 e o primeiro de b foir 1                                                     **/
    {
        if (maior == &a)                                                         /** Se o ponteiro maior apontar para o vetor a                                                                     **/
        {
            c[0] = 0;                                                            /** Primeiro elemento de c igual a 0                                                                               **/
            for (d = 1; d <=Tmenor; d++)                                         /** Para d indo de 1 até o menor tamanho                                                                           **/
            {
                c[d] = (a[d] - b[d]);                                            /** Faz o valor de c ser a - b em cada elemento                                                                    **/
            }
            for (d = (Tmenor+1); d <= Tmaior; d++)                               /** Para d variando de T menor mais 1 até T maior                                                                  **/
            {
                c[d] = a[d];                                                     /** Faz um elemento do vetor c ser igual a um elemento do vetor a                                                  **/
            }
        }
        else                                                                     /** Se o ponteiro maior apontar para o vetor b                                                                     **/
        {
            if (maior == &b && menor == &b)                                      /** Caso os ponteiros maior e menor apontem pra o vetor b                                                          **/
            {
                for (d = 0; d <= Tmaior; d++)                                    /** Para d indo de 1 até o maior tamanho                                                                           **/
                {
                    c[d] = 0;                                                    /** Faz um elemento do vetor c ser igual a 0                                                                       **/
                }
            }
            else                                                                 /** Caso os ponteiros maior e menor não apontem pra o vetor b                                                      **/
            {
                c[0] = 1;                                                        /** Varivael d variando de 1 até o tamanho menor de vetor                                                          **/
                for (d = 1; d <=Tmenor; d++)                                     /** Para d indo de 1 até o menor tamanho                                                                           **/
                {
                    c[d] = (b[d] - a[d]);                                        /** Faz o valor de c ser a - b em cada elemento                                                                    **/
                }
                for (d = (Tmenor+1); d <= Tmaior; d++)                           /** Para d variando de T menor mais 1 até T maior                                                                  **/
                {
                    c[d] = b[d];                                                 /** Faz um elemento do vetor c ser igual a um elemento do vetor b                                                  **/
                }
            }
        }
    }
    else if (a[0] == 1 && b[0] == 0)                                             /** Caso o primeiro numero de a for 1 e de b for 0                                                                 **/
    {
        if (maior == &a)                                                         /** Se o ponteiro maior apontar para o vetor a                                                                     **/
        {
            c[0] = 1;                                                            /** Atribui o valor 1 ao primeiro numero do vetor                                                                  **/
            for (d = 1; d <=Tmenor; d++)                                         /** Para d indo de 1 até o menor tamanho                                                                           **/
            {
                c[d] = (a[d] - b[d]);                                            /** Faz o valor de c ser a - b em cada elemento                                                                    **/
            }
            for (d = (Tmenor+1); d <= Tmaior; d++)                               /** Para d variando de T menor mais 1 até T maior                                                                  **/
            {
                c[d] = a[d];                                                     /** Faz um elemento do vetor c ser igual a um elemento do vetor a                                                  **/
            }
        }
        else                                                                     /** Se o ponteiro maior apontar para o vetor b                                                                     **/
        {
            if (maior == &b && menor == &b){                                     /** Caso os ponteiros maior e menor não apontem pra o vetor b                                                      **/
                for (d = 0; d <= Tmaior; d++)                                    /** Para d indo de 1 até o maior tamanho                                                                           **/
                {
                    c[d] = 0;                                                    /** Faz um elemento do vetor c ser igual a 0                                                                       **/
                }
            }
            else                                                                 /** Caso os ponteiros maior e menor não apontem pra o vetor b                                                      **/
            {
                c[0] = 0;                                                        /** Faz o primeiro elemento de c valer 0                                                                           **/
                for (d = 1; d <=Tmenor; d++)                                     /** Para d indo de 1 até o menor tamanho                                                                           **/
                {
                    c [d] = (b[d] - a[d]);                                       /** Faz o valor de c ser a - b em cada elemento                                                                    **/
                }
                for (d = (Tmenor+1); d <= Tmaior; d++)                           /** Faz d percorrer de t menor mais 1 até t maior                                                                  **/
                {
                    c[d] = b[d];                                                 /** Faz um elemento do vetor c ser igual a um elemento do vetor b                                                  **/
                }
            }
        }
    }
    else if (a[0] == 1 && b[0] == 1)                                             /** Caso o primeiro elemento for igual a 1 nos dois vetores                                                        **/
    {
        c[0] = 1;                                                                /** Primeiro elemento do vetor c vira 1                                                                            **/
        for (d = 1; d <=Tmenor; d++)                                             /** Para d indo de 1 até o menor tamanho                                                                           **/
        {
            c[d] = (a[d] + b[d]);                                                /** Faz o valor de c ser a + b em cada elemento                                                                    **/
        }
        if (maior == &a){                                                        /** Se o ponteiro maior apontar para o vetor a                                                                     **/
            for (d = (Tmenor+1); d <= Tmaior; d++)                               /** Faz d percorrer de t menor mais 1 até t maior                                                                  **/
            {
                c[d] = a[d];                                                     /** Faz um elemento do vetor c ser igual a um elemento do vetor a                                                  **/
            }
        }
        else if (maior == &b){                                                   /** Se o ponteiro maior apontar para o vetor b                                                                     **/
            for (d = (Tmenor+1); d <= Tmaior; d++)                               /** Faz d percorrer de t menor mais 1 até t maior                                                                  **/
            {
                c[d] = b[d];                                                     /** Faz um elemento do vetor c ser igual a um elemento do vetor b                                                  **/
            }
        }
    }

    imprimeVetor(c, Tmaior);                                                     /** Chama a função que corrige numerão para ser impresso                                                           **/
    imprimeNumerao(c, Tmaior);                                                   /** Chama a função que imprime o numerão                                                                           **/
}

void somaN(int n)                                                                /** Função que soma os n primeiros numeros naturais                                                                **/
{
    int tN = tam(n);                                                             /** Tamanho de N obtido a partir de chamar tam                                                                     **/
    int vetorn [(tN + 1)];                                                       /** Vetor que armazena o numero final da soma e o inicial                                                          **/
    int f;                                                                       /** Variavel pra variar e criar o vetores para serem somados                                                       **/
    int fp;                                                                      /** Variavel que  percorre os numeros do vetor temporario                                                          **/
    int tEX;                                                                     /** Tamanho do vetor variavel                                                                                      **/

    criaNumerao(n, vetorn);                                                      /** CriaNumerao a partir de n                                                                                      **/
    for (f = (n-1); f > 0; f--)                                                  /** Varia f de n-1 até 1                                                                                           **/
    {
        tEX = tam(f);                                                            /** Pega o tamanho de f variando para criar o vetor a partir da função tam                                         **/
        int vetorEX [(tEX+1)];                                                   /** Cria o vetor variavel com o tamanho do n variando mais 1                                                       **/
        criaNumerao(f, vetorEX);                                                 /** Cria um novo vetor com numeros para serem somados                                                              **/
        for (fp = 1; fp <= tEX; fp++)                                            /** Faz uma variavel indo de 1 até o tamanho do vetor menor                                                        **/
        {
            vetorn [fp] = ((vetorn [fp]) + (vetorEX[fp]));                       /** Faz os valores do vetor inicial serem somados ao vetor variante                                                **/
        }
        imprimeVetor(vetorn, tN);                                                /** Chama a função que corrige numerão para ser impresso                                                           **/
    }
    imprimeNumerao(vetorn, tN);                                                  /** Chama a função que imprime o numerão                                                                           **/
}

void main ()                                                                     /** Função principal                                                                                               **/
{
    int escolhedor;                                                              /** Variavel pra deixar o usuarios escolher qual programa vai rodar                                                **/

    printf ("Digite 0 (soma) ou 1 (soma naturais): ");                           /** Printa o pedido no Ep3                                                                                         **/
    scanf ("%d", &escolhedor);                                                   /** Pega o  valor digitado pelo usuario                                                                            **/

    if (escolhedor == 0)                                                         /** Caso soma                                                                                                      **/
    {
        int an;                                                                  /** Variavel que guarda o input do primeiro numero do usuario                                                      **/
        int bn;                                                                  /** Variavel que guarda o input do primeiro numero do usuario                                                      **/
        int tA;                                                                  /** Tamanho do input do usuario                                                                                    **/
        int tB;                                                                  /** Tamanho do input do usuario                                                                                    **/

        printf ("Digite o primeiro numero: ");                                   /** Printa o pedido no Ep3                                                                                         **/
        scanf ("%d", &an);                                                       /** Pega o  valor digitado pelo usuario                                                                            **/
        printf ("Digite o segundo numero: ");                                    /** Printa o pedido no Ep3                                                                                         **/
        scanf ("%d", &bn);                                                       /** Pega o  valor digitado pelo usuario                                                                            **/
        tA = tam(an);                                                            /** Guarda o tamanho de a chamando a função tama                                                                   **/
        tB = tam(bn);                                                            /** Guarda o tamanho de b chamando a função tamb                                                                   **/
        int a[(tA+1)];                                                           /** Cria o vetor a com tamanho de digitos mais 1                                                                   **/
        int b[(tB+1)];                                                           /** Cria o vetor b com tamanho de digitos mais 1                                                                   **/
        tA = criaNumerao (an, a);                                                /** Pega o tamanho de a e chama crianumerao                                                                        **/
        tB = criaNumerao (bn, b);                                                /** Pega o tamanho de b e chama crianumerao                                                                        **/
        printf ("Soma: " );                                                      /** Printa o pedido no Ep3                                                                                         **/
        soma (a, tA, b, tB);                                                     /** Chama a função soma                                                                                            **/
    }

    else if (escolhedor == 1)                                                    /** Caso soma naturais                                                                                             **/
    {
        int n;                                                                   /** Cria a variavel n para receber o numero do usuario                                                             **/
        printf ("Entre com valor de n para soma dos n primeiros naturais: ");    /** Printa o pedido no Ep3                                                                                         **/
        scanf ("%d", &n);                                                        /** Pega o  valor digitado pelo usuario                                                                            **/
        printf ("Soma dos %d primeiros naturais = ", n);                         /** Printa o pedido no Ep3                                                                                         **/
        somaN(n);                                                                /** Chama a função soma                                                                                            **/
    }
}
