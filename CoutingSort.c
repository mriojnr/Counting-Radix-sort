#include <stdio.h>
#include <string.h>
#define RANGE 255

// A principal função que classifica o string arr [] em
// ordem alfabética
void countSort(char arr[])
{
    // A matriz de caracteres de saída que terá ordenado arr
    char output[strlen(arr)];

    // Crie uma matriz de contagem para armazenar a contagem inidividual de
    // caracteres e inicialize a matriz de contagem como 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    //Contagem de loja de cada personagem
    for(i = 0; arr[i]; ++i)
        ++count[arr[i]];

    // Altere a contagem [i] para que a contagem [i] agora contenha informações reais
    // posição desse personagem na matriz de saída
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];

    //Crie a matriz de caracteres de saída
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }

    // Copie a matriz de resultados para arr, de modo que arr agora
    // contém caracteres ordenados
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

// Programa de driver para testar a função acima
int main()
{
    char arr[] = "mariojuniormario";

    countSort(arr);

    printf("A matriz de caracteres ordenados é %sn", arr);
    return 0;
}