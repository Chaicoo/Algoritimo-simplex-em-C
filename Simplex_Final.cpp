//Francisco Gabriel Noleto Lima
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define max 10
using namespace std;

//variáveis globais
int numero_Variaveis, numero_Restricoes; //número de variáveis e de restrições
int linhas, colunas, coluna_Pivo, linha_Pivo, linha_Menor, variaveis[max], variaveis_Ref, count, count_Multi;
double tabela[max][max], entrada, coluna_Entrada, menor_Pivo, pivo;
boolean limite, multi;

//Cabeçalho das funções
void simplex();
void escolher_Entrada();
void escolher_Pivo();
void gerarNovas_Linhas();
void gerarLinha_Pivo();
void calcular_Variaveis();
void testar_Ilimitado();
void testar_Multi();
bool testar_Solucao();

int main(){  
setlocale(LC_ALL, "portuguese");   
	double solucao;
    
    printf("Para gerar a matriz do Tableau Simplex, precisa-se informar a quantidade de variaveis e restricoes.\n");
    printf("\nDigite o numero de variaveis do problema:\n");
        scanf("%d", &numero_Variaveis);
    printf("\nDigite o numero de restricoes do problema(ignore as restricoes de nao negatividade)\n");
        scanf("%d", &numero_Restricoes);
    colunas = numero_Variaveis + numero_Restricoes + 1;
    linhas = numero_Restricoes + 1;//o número de colunas será o número de restrições + 1(linha da FO)

    printf("\nDigite a tabela: \n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%lf", &tabela[i][j]);
        }
    }
    testar_Multi();
    do{
        printf("\nIniciando o metodo simplex\n");
        simplex();
    }
        while(!testar_Solucao());
    // caso seja ilimitado ele não ira calcular a solução
    if(limite == true){
   	 	printf("\nPpl  ilimitado\n");
	}
        else{
            solucao = tabela[linhas - 1][colunas - 1];
            printf("\nO valor gerado pela FO e: %1.lf\n", solucao);
            if(count_Multi == 1){
            printf("\nPpl de multiplas solucoes\n");
            } 
                else{
                    //as variáveis só seram calculadas se ele não for multipla
   	 		        calcular_Variaveis();
                }
		}
    return 0;
}

void escolher_Entrada(){
    //inicializando as variaveis usadas na função
    linha_Menor = 0;
    coluna_Pivo = 0;
    entrada = INT_MAX;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(tabela[numero_Restricoes][j] < entrada){
                entrada = tabela[i][j];
                linha_Menor = i;
                coluna_Pivo = j;
            }
        }
    }
    printf("\nA variavel que entra na base e %.1lf\n", entrada);
}

void escolher_Pivo(){
    menor_Pivo = INT_MAX;
    linha_Pivo = 0;
    pivo = 0;

    for(int i = 0; i < linhas; i++){
        if(i == linha_Menor) continue;
        coluna_Entrada = tabela[i][colunas-1] / tabela[i][coluna_Pivo];
        if(coluna_Entrada < menor_Pivo && coluna_Entrada>0){
            menor_Pivo = coluna_Entrada;
            linha_Pivo = i;
        }
    }
    pivo = tabela[linha_Pivo][coluna_Pivo];
    printf("\nLinha do Pivo: %d\n",linha_Pivo);
    printf("\nPivo: %.2lf\n", pivo);
}

void gerarNovas_Linhas(){
    int ref = 0;//o ref � o indice da linha 0, 1, 2 . . .
    while(ref < linhas){//enquanto ref for menor que as linhas o while sera repetido e incrementa o ref
        if(ref != linha_Pivo){
            printf("\nNova linha %.0d: \n", ref);

            double ref_Linha[colunas], inv = tabela[ref][coluna_Pivo] * -1;//inve � o inverso do elemento da coluna pivo
            	//gerando a nova linha
				for(int i = 0; i < colunas; i++){
                    ref_Linha[i] = tabela[linha_Pivo][i] * inv;
                    tabela[ref][i] += ref_Linha[i];

                printf("%.2lf ", tabela[ref][i]);
                }
            printf("\n");
        }
        ref++;
    }
}

void gerarLinha_Pivo(){
    printf("\nNova linha pivo: \n");
    for(int i = 0; i < colunas; i++){
        tabela[linha_Pivo][i] = tabela[linha_Pivo][i] / pivo;
        printf("%.2lf ",tabela[linha_Pivo][i]) ;
    }
    printf("\n");

    gerarNovas_Linhas();
}

void simplex(){
	//chama os metodos que calculam os pivos e geram as novas linhas
    escolher_Entrada();

    escolher_Pivo();

    gerarLinha_Pivo();
	//exibe a tabela gerada p�s a fun��o de gerar novas linhas
    printf("\n\nNova tabela: \n");
    for(int i = 0; i < linhas; i++){
        printf("\n");
        for(int j = 0; j < colunas; j++){
           printf("%1.lf ", tabela[i][j]);
        }
    }

    printf("\n");

}

bool testar_Solucao(){

    testar_Ilimitado();

    if(limite == true){
		return true;
	}
    for(int i = 0; i< colunas; i++){
        if(tabela[numero_Restricoes][i] < 0){//se existe numero negativo na ultima linha ela n�o � solu��o otima
            printf("\nA solucao ainda nao e a otima.\n");
            return false;
        }
    }
    printf("\nA solucao e otima.\n");
    return true;
}

void testar_Multi(){
    float div[max][max];
	for(int i = 0; i < numero_Restricoes; i++){
			for(int j = 0; j < numero_Variaveis; j++){
				div[i][j] = tabela[numero_Restricoes][j] / tabela[i][j];
			}	
			printf("\n");
		 }	

		for(int i = 0; i < numero_Restricoes; i++){
			for(int j = 0; j < numero_Variaveis; j++){
				if(j < numero_Variaveis - 1){
					if(div[i][j] == div[i][j + 1]){
					multi = true;	   	   	
					} else {
						multi = false;
					}
					if (j = numero_Variaveis - 1 && multi == (true)){
						count_Multi = 1;
					} 	 
				}
				
			}
		}
} 

void calcular_Variaveis(){
    double ref = 0;
    
    for(int i = 0; i < colunas - 1; i++){
        for(int j = 0; j < linhas; j++){
            ref += tabela[j][i];
        }
        if(ref==1){
            variaveis[variaveis_Ref] = i;
            variaveis_Ref++;
        }
        ref=0;
    }
    printf("\nValor das variaveis para a solucao otima: \n");

    for(int i = 0; i < variaveis_Ref; i++){
        if(variaveis[i] <= numero_Variaveis){
            double valorResp=0;
            for(int j = 0; j < linhas; j++){
                if(tabela[j][variaveis[i]] == 1){
                    valorResp = tabela[j][colunas - 1];
                    break;
                }
            }
            printf("X%d = %.1lf\n",variaveis[i] + 1,valorResp);
        }
    }
}

void testar_Ilimitado(){
	for(int cont = 0; cont < linhas - 1; cont++)
	coluna_Entrada = tabela[cont][colunas-1] / tabela[cont][coluna_Pivo];
	if(coluna_Entrada < 0){
		coluna_Entrada = 0;
		limite = true;
	} else {
		limite = false;
	}
}
