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
/**   Exercício-Programa 04                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXM  100
#define MAXK  5
#define MAXP  32000
#define MAXD  100
#define MAXF  100
#define FALSE 0
#define TRUE  1



/*
Abaixo, temos o protótipo de algumas funções que você deve implementar
*/


int BuscaMarcador( int ini, char politech[MAXP], char marcador[MAXM] ){
    int i, j, finalmarc, resultado = MAXP;
    for (i = 0; i < MAXM; i++){
        if (marcador[i] == 0) {
            finalmarc = (i - 1);
            break;
        }
    }
    for (i = ini; i<MAXP; i++){
        if ( politech[i] == 0 ){
            break;
        }
        if (politech[i] == marcador[0]){
            for (j = 1; j <= finalmarc; j++){
                if (politech[i+j] != marcador[j]){
                    break;
                }
            }
            if (j == finalmarc + 1){
                resultado = i;
                break;
            }
        }
    }
    return resultado;
}

int BuscaMarcadores( int ini, char politech[MAXP], int k, char marcadores[MAXK][MAXM], int *compr){
    int i, resultado = MAXP, j = resultado;
    char linha[MAXM];
    for (i = 0; i < k; i++){
        strcpy(linha , marcadores[i]);
        j = BuscaMarcador(ini, politech, linha);
        if (j != 32000){
            resultado = j;
            break;
        }
    }
    if (resultado != 32000){
        for (i = 0; i < MAXM; i++){
            if (linha[i] == 0){
                break;
            }
        }
        * compr = i;
    }
    else{
        * compr = 0;
    }
    return resultado;
}

int Delta( char q[MAXP], char p[MAXP], int delta[MAXD], int desloc, int ini, int fim ){
    int i, j, contador = 0, comeco = 0;
    for ( i = 0; i < MAXP; i++){
        if (q[i] != '\000'){
            desloc = (i-ini);
            break;
        }
    }
    for ( j = ini; j<= fim; j++){
        if (p[j] != q[j+desloc]){
            delta[contador] = j;
            contador = contador + 1;
        }
    }
    delta[contador] = MAXP;
    return contador;
}

int DiferencaDeConjuntos( int delta_q[MAXD], int delta_s[MAXD], int q_menos_s[MAXD] ){
    int cont = 0, contador = 0, i, j;

    for (i = 0; i < MAXD; i++){
        if (delta_q[i] == MAXP){
            break;
        }
        for (j = 0; j < MAXD; j++){
            if (delta_s[j] == MAXP){
                q_menos_s[cont] = delta_q[i];
                cont = cont + 1;
                break;
            }
            else{
                if (delta_q[i] == delta_s[j]){
                    contador = contador + 1;
                    break;
                }
            }
        }
    }
    q_menos_s[cont] = MAXP;
    return contador;
}

int HaIncompatibilidade( int n, char F[MAXF][MAXP], int j_p, int G[MAXF], int D[MAXF][MAXD] ){
    int i, j = 0, k, fm = (strlen( F[j_p] ) - 1), in, desloc, ccon = 0;

    for (k = 0; k < MAXP; k++){
        if (F[j_p][k] != '\000'){
            in = k;
            break;
        }
    }

    for (i = 0; i < n; i++){
        for (k = 0; k < MAXP; k++){
            if (F[i][k] != '\000'){
                G[ccon] = k;
                ccon = ccon + 1;
            }
        }
        if (i != j_p){
            Delta(F[i], F[j_p], D[j], desloc, in, fm);
            j = j + 1;
        }
    }

    for (i = 0; i < (n-1); i++){
    /* faria a comparação aqui, depois de obter G e D, para assim  comparar os D com os outros D, e obter o pedido */
    }
}

int fatorial (int f){
    int i, r = 1;
    if (f > 0){
        for (i = f; i > 1; i--){
            r = (i * r);
        }
    }
    else{
        return 1;
    }
}

int Sorteios (int n, int k, int d){

    if (d < 2){
        return n;
    }

    else{
        return (((n-d+1)*k*(k-1)*(fatorial((d-2))))/(fatorial((d-k))));
    }
}

void DiametroEProbabilidades( int delta[MAXD], int ini, int fim, int d, int Pkmd, int Pkns){
    int n = ((fim - ini) + 1), k, i, pcima1=0, pcima2=0;

    for (i = 0; i < MAXD; i++){
        if (delta[i] == MAXP) {
            k = i;
        }
    }

    d = ((delta [k-1] - delta[0]) + 1);

    int pgeral, pgeralcima = n, pgeralbaixo = (n-k);

    for (i = n-1; i > 1; i--){
        pgeralcima = (pgeralcima * i);
    }
    for (i = (pgeralbaixo - 1); i > 1; i--){
        pgeralbaixo = (pgeralbaixo * i);
    }

    pgeral = ( pgeralcima / pgeralbaixo );

    pcima1 = Sorteios(n, k, d);

    for (i = d; i > 0 ; i--){
        pcima2 = (Sorteios(n, k, i) + pcima2);
    }
    Pkmd = (pcima1/pgeral);
    Pkns = (pcima2/pgeral);
}

int main() {
  char F[MAXF][MAXP];		                 /* matriz com a família de Politechs, um por linha */
  int np = 0;	                             /* número de Politechs armazenados em F */
  int ncp = 0;			                     /* total de caracteres dos Politechs de F */
  int j_p = 0;			                     /* indice do patriarca na família */
  int L[MAXF];		                         /* length (comprimento) de cada politech */
  int G[MAXF];		                         /* gama, primeira ocorrência de marcador de início */
  int continua = TRUE;		                 /* iteração continua?  */
  char comando;			                     /* comando selecionado */
  char m[MAXK][MAXM];		                 /* marcadores de início */
  int nm = 0;	                             /* número de marcadores de início */
  char M[MAXK][MAXM];		                 /* marcadores de fim */
  int nM = 0;	                             /* número de marcadores de fim */
  int i, j, k, compr;
  int ini = 0, fim = MAXP-1;	             /* extremidades do intervalo de busca de caracteristicas */
  int D[MAXF][MAXD];		                 /* matriz de caracteristicas com Delta( F[i] ) em cada linha D[i] */
  int diametro;			                     /* valor devolvido por DiametroEProbabilidade */
  double Prob_eq_diametro, Prob_le_diametro; /* valores devolvidos por DiametroEProbabilidades */
  char comentario[300];			             /* linha de comentario */

  while( continua ) {
    printf( "Digite uma letra para um comando: " );
    comando = 'q';		                     /* valor default de leitura se houver erro no scanf */
    do {
      scanf( " %c", &comando );
      if ( comando == '#' ) {
	scanf( "%[^\n]",comentario );
	printf("\n#%s",comentario);
      }
    } while (comando=='#');
    switch( comando ) {
    case 'p':
      printf( "\nDigite um Politech: " );
      scanf( " %[!-~]", F[np] );
      L[np] = strlen( F[np] );
      ncp += L[np];
      printf( "\nPolitech %d de comprimento %d inserido na familia, com %d caractere(s).\n",
	      np, L[np], ncp );
      G[np] = D[np][0] = MAXP;	/* calculo posterior */
      np++;
      break;
    case 'P':
      printf( "\nDigite indice do patriarca: " );
      scanf( " %d", &j_p );
      ini = 0, fim = strlen( F[j_p] ) - 1;
      printf( "\nPatriarca da familia [ %d .. %d ] eh o de numero %d e tem comprimento %d .\n", 0, np-1, j_p, fim + 1 );
      break;
    case 'e':
      printf( "\nExtremidades atuais do intervalo de posicoes do patriarca a ser comparado: %d %d", ini, fim );
      if ( nm > 0 )
	printf( "\nPrimeira ocorrencia de um marcador de inicio: %d", BuscaMarcadores( ini, F[j_p], nm, m, &compr ) );
      printf("\nDigite duas novas extremidades do intervalo de onde serao extraidas as caracteristicas\n(valores invalidos provocam uma busca automatica que use os conjuntos de marcadores): ");
      scanf( "%d %d", &ini, &fim );
      if ( !( 0 <= ini && ini <= fim && fim < L[j_p] ) ) {
	/* valores invalidos provocam uma busca automatica */
	ini = 0; fim = L[j_p];
	printf( "\nAntigo interv. de busca de caracteristicas: [ %d .. %d ].", ini, fim );
	i = ini; k = -1;
	do {
	  /* busca marcador de início */
	  i = BuscaMarcadores( i, F[j_p], nm, m, &compr );
	  /* printf( "[ marca_ini compr =  %d %d\n", i, compr ); */
	  if ( i <= fim-compr ) {
	    i = i + compr;
	    /* busca marcador de fim */
	    j = BuscaMarcadores( i, F[j_p], nM, M, &compr );
	    /* printf( "marca_fim ] compr =  %d %d\n", j, compr ); */
	    if ( j <= fim-compr )
	      k = i = j + compr;
	    else if ( j == MAXP || j + compr > fim ) {
	      i = MAXP;
	      compr = 0;
	    }
	  } /* if i */
	} while ( i <= fim );
	if ( k >= 0) {
	  /* printf( "ini fim len = %d %d %d\n", ini, fim, L[j_p] ); */
	  fim = k;
	  ini = BuscaMarcadores( 0, F[j_p], nm, m, &compr );
	  /* para incluir mutações biológicas em regiões promotoras */
	  ini = ini < 10 ? 0 : ini-10;
	  /* printf( "ini fim len = %d %d %d\n", ini, fim, L[j_p] ); */
	}
      }
      printf( "\nNovo intervalo de busca de caracteristicas: [ %d .. %d ].\n", ini, fim );
      break;
    case 'm':
      assert( nm < MAXM );
      printf( "\nDigite um marcador de inicio: " );
      scanf( " %[!-~]", m[ nm++ ] );
      printf( "\nInserindo marcador de inicio: %s", m[ nm - 1 ] );
      printf( "  Temos %d marcador(es) de inicio.\n", nm );
      break;
    case 'M':
      assert( nM < MAXM );
      printf( "\nDigite um marcador de fim: " );
      scanf( " %[!-~]", M[ nM++ ] );
      printf( "\nInserindo marcador de fim: %s", M[ nM - 1 ] );
      printf( "  Temos %d marcador(es) de fim.\n", nM );
      break;
    case 'g':
      printf( "\nPrimeira ocorrencia de marcador de inicio (gama) de cada politech:\n%s",
	      "  i   gama" );
      for ( i = 0; i < np; i++ ) {
	G[i] = BuscaMarcadores( 0, F[i], nm, m, &compr );
	printf( "\n%3d %5d", i, G[i] );
      }
      printf("\n");
      break;
    case 'd':
      printf( "\nCaracteristicas no intervalo [ %d .. %d ]:", ini, fim );
      for ( i = 0; i < np; i++ )
	if ( i != j_p ) {
	  k = Delta( F[i], F[j_p], D[i], G[i] - G[j_p], ini, fim );
	  printf( "\nD[ %3d ] = ", i );
	  for ( j = 0; D[i][j] < MAXP; j++ )
	    printf( " %5d", D[i][j] );
	}
	else
	  D[i][0] = MAXP;	/* conjunto vazio de cararacterísticas */
      printf("\n");
      break;
    case 'b':
      printf( "\nDiametros e Probabilidades do conjunto de caracteristicas:" );
      printf( "\npol     n   k     d  P(diam=d) P(diam<=d)" );
      for ( i = 0; i < np; i++ )
	if ( i != j_p ) {
	  k = Delta( F[i], F[j_p], D[i], G[i] - G[j_p], ini, fim );
	  DiametroEProbabilidades( D[i], ini, fim, &diametro, &Prob_eq_diametro, &Prob_le_diametro );
	  printf( "\n%3d %5d %3d %5d   %8.2e  %-8.3g", i, fim - ini + 1, k, diametro, Prob_eq_diametro, Prob_le_diametro );
	}
	else
	  D[i][0] = MAXP;	/* conjunto vazio de cararacterísticas */
      printf( "\n" );
      break;
    case 'i':
      if ( HaIncompatibilidade( np, F, j_p, G, D ) )
	printf( "\nHah caracteristicas incompativeis e nao hah arvore filogenetica perfeita.\n" );
      else
	printf( "\nNao hah caracteristicas incompativeis e hah arvore filogenetica perfeita.\n" );
      break;
    default:
      printf( "\nComando invalido: %c\n", (int) comando );
    case 'q':
      continua = FALSE;
      printf( "\nObrigado, ate mais.\n" );
      break;
    }
  }
  return 0;
}







