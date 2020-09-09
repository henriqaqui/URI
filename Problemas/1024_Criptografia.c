/*
Solicitaram para que você construisse um programa simples de criptografia.
Este programa deve possibilitar enviar mensagens codificadas sem que alguém consiga lê-las.
O processo é muito simples. São feitas três passadas em todo o texto.

Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas
devem ser deslocadas 3 posições para a direita, segundo a tabela ASCII:
letra 'a' deve virar letra 'd', letra 'y' deve virar caractere '|' e assim sucessivamente.
Na segunda passada, a linha deverá ser invertida. Na terceira e última passada,
todo e qualquer caractere a partir da metade em diante (truncada)
devem ser deslocados uma posição para a esquerda na tabela ASCII. Neste caso, 'b' vira 'a' e 'a' vira '`'.

Por exemplo, se a entrada for “Texto #3”, o primeiro processamento sobre esta entrada deverá produzir “Wh{wr #3”.
O resultado do segundo processamento inverte os caracteres e produz “3# rw{hW”.
Por último, com o deslocamento dos caracteres da metade em diante, o resultado final deve ser “3# rvzgV”.

ENTRADA: A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém
um inteiro N (1 ≤ N ≤ 1*104), indicando a quantidade de linhas que o problema deve tratar.
As N linhas contém cada uma delas M (1 ≤ M ≤ 1*103) caracteres.

SAÍDA: Para cada entrada, deve-se apresentar a mensagem criptografada.
*/

#include <stdio.h>

int main(void){
    char mensagem[1000], mensagemCrip[1000];
    int quantidadeLinhas;
    int contador = 0, contadorInvert = 0;

    scanf("%d", &quantidadeLinhas);
    //setbuf(stdin, NULL);

    for(;   quantidadeLinhas > 0; quantidadeLinhas--){
        //gets(mensagem);
        //fgets(mensagem, 1000, stdin);
        scanf(" %[^\n]", mensagem);

        /*PRIMEIRA PASSADA*/
        while (mensagem[contador] != '\0')
        {
            if((mensagem[contador] >= 65 && mensagem[contador] <= 90) || (mensagem[contador] >= 97 && mensagem[contador] <= 122)){
                    mensagem[contador] += 3;
            }
            contador++;
        }

        mensagemCrip[contador] = '\0'; //Delimita tamanho da mensagem criptografada.
        contador--; //Para preparar o contador para a segunda passada.

        /*SEGUNDA PASSADA*/
        while (contador >= 0)
        {
            mensagemCrip[contadorInvert] = mensagem[contador];
            contador--;
            contadorInvert++;
        }

        contador = contadorInvert / 2; //prepara o contador para a terceira passada. 

        /*TERCEIRA PASSADA*/
        while (mensagemCrip[contador] != '\0')
        {
            mensagemCrip[contador]--;
            contador++;
        }

        printf("%s\n", mensagemCrip);

        contador = 0;
        contadorInvert = 0;
    }
    return 0;
}
