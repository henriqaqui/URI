#include <stdio.h>

int main(void){
    char mensagem[1001], mensagemCrip[1001];
    int linhas, contador = 0, contadorInvert = 0;

    scanf("%d", &linhas);

    for(; linhas > 0; linhas--){
        setbuf(stdin, NULL);
        //scanf("%[^\n]s", mensagem);
        fgets(mensagem, 1001, stdin);


        while (mensagem[contador] != '\0')
        {
            if((mensagem[contador] >= 65 && mensagem[contador] <= 90) || (mensagem[contador] >= 97 && mensagem[contador] <= 122)){
                    mensagem[contador] += 3;
            }
            contador++;
        }

        mensagemCrip[contador] = '\0';
        contador--;

        while (contador >= 0)
        {
            mensagemCrip[contadorInvert] = mensagem[contador];
            contador--;
            contadorInvert++;
        }

        contadorInvert /= 2;

        while (mensagemCrip[contadorInvert] != '\0')
        {
            mensagemCrip[contadorInvert]--;
            contadorInvert++;
        }

        contador = 0;

        printf("%s\n", mensagemCrip);

        contador = 0;
        contadorInvert = 0;
    }
    return 0;
}
