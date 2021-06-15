#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

//Tradutor Élfico-Computacional (EC) feito com base na tabela ASCII - 2, por exemplo, o valor 65 se torna 63
//O usuário pode entrar com letras minúsculas, porém a tradução é feita somente com letras maiúsculas

int main(){
    //Alguns caracteres são impossíveis de expressar ou deram erro dentro das aspas então viraram 0
    setlocale(LC_ALL, "Portuguese");
    
    char ascii[126] = {
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 
    '0', '0', '0', '0', '0', '0', '0', ' ', '!', '0', '#', '$', 
    '%', '&', '0', '(', ')', '*', '+', ',', '-', '.', '/', '0', 
    '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', 
    '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
    'V', 'W', 'X', 'Y', 'Z', '[', '0', ']', '^', '_', '`', 'a', 
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 
    'z', '{', '|', '}', '~'};
    
    char frase[100], traducao[100], decimal[100];
    int a = 0, elfico_computacional = 0;

    printf("Tradutor Élfico-Computacional (EC)\n\n");
    printf("Tabela ASCII\n");
    //printf("%s\n\n", ascii);

    printf("[");
    for(a = 0; a <= 30; a++){
        printf("%c", ascii[a]);
    }
    printf("]\n");

    printf("[");
    for(a = 31; a <= 61; a++){
        printf("%c", ascii[a]);
    }
    printf("]\n");

    printf("[");
    for(a = 62; a <= 92; a++){
        printf("%c", ascii[a]);
    }
    printf("]\n");

    printf("[");
    for(int a = 93; a <= 124; a++){
        printf("%c", ascii[a]);
    }
    printf("]\n\n");

    printf("Digite a frase em português: ");
    setbuf(stdin, 0);
	fgets(frase, 100, stdin);
	fflush(stdin);

    for(int i = 0; frase[i]; i++){
        //transformar a frase digitada pelo usuário em maiúscula
        frase[i] = toupper(frase[i]);
    }
    printf("\nUppercase: %s", frase);

    int z = 0;

    for(int x = 0; x < frase[z]; x++){
        //procurar no vetor ascii a letra equivalente e salvar sua posição como decimal
        if(ascii[x] == frase[z]){
           decimal[z] = x;
           z++;
           x = 0;
        }
    }

    for(int w = 0; w < frase[w]; w++){
    //transformar o decimal em élfico-computacional
    elfico_computacional = decimal[w];
    elfico_computacional -= 2;

    //traduzir
    traducao[w] = ascii[elfico_computacional];
    }

    printf("\nTradução: %s\n\n", traducao);

    

    return 0;
}