#include <stdio.h>
#include <string.h>
#include <iostream.h>

// using namespace std;
 
// Uma função de utilidade para obter o máximo de valor em arr []
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// Uma função para contar o tipo de arr [] de acordo com
// o dígito representado pela exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Armazenar contagem de ocorrências em contagem []
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Altere a contagem [i] para que a contagem [i] agora contenha informações reais
    //  posição desse dígito na saída []
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Crie a matriz de saída
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copie a matriz de saída para arr [], de modo que arr [] agora
    // contém números ordenados de acordo com o dígito atual
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// A função principal para esse tipo arr [] de tamanho n usando
// Radix Sort
void radixsort(int arr[], int n)
{
    // Encontre o número máximo para saber o número de dígitos
    int m = getMax(arr, n);
 
    // Contagem de classificação para cada dígito. Note que em vez disso
    // de número de dígitos passantes, exp é aprovado. exp é 10 ^ i
    // onde eu sou o número de dígito atual
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// Uma função de utilidade para imprimir uma matriz
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
// Programa de driver para testar funções acima
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}