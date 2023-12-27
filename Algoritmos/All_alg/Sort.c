#include "Sort.h"
void selectionSort(int arr[], int n) 
{
    int i, j, min_idx;

    // Percorre o array
    for (i = 0; i < n-1; i++) 
    {
        // Encontra o elemento mínimo no array não ordenado
        min_idx = i;
        for (j = i+1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Troca o elemento mínimo com o primeiro elemento não ordenado
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;

        // Move os elementos do arr[0..i-1] que são maiores que a chave para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void bubbleSort(int arr[], int n) 
{
    int i, j;
    for (i = 0; i < n-1; i++) 
    {
        // Percorre o array do início ao fim
        for (j = 0; j < n-i-1; j++) 
        {
            // Compara elementos adjacentes e troca se o elemento atual for maior que o próximo
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void merge(int arr[], int left, int middle, int right) 
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Cria arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge dos arrays temporários de volta para arr[left..right]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = left; // Índice inicial do subarray mesclado
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        // Encontra o ponto médio
        int middle = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Faz o merge das duas metades ordenadas
        merge(arr, left, middle, right);
    }
}
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // Pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) 
    {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivot) 
        {
            i++; // Incrementa o índice do menor elemento
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        // pi é o índice de partição, arr[p] está no lugar certo
        int pi = partition(arr, low, high);

        // Separa os elementos em lados opostos da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void heapify(int arr[], int n, int i) 
{
    int largest = i; // Inicializa o maior como raiz
    int left = 2 * i + 1; // Esquerda = 2*i + 1
    int right = 2 * i + 2; // Direita = 2*i + 2

    // Se o filho da esquerda for maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se o filho da direita for maior que o maior até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não for a raiz
    if (largest != i) 
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursivamente faz o heapify na subárvore afetada
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) 
{
    // Constroi o heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai um por um os elementos do heap
    for (int i = n - 1; i >= 0; i--) 
    {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama o max heapify no heap reduzido
        heapify(arr, i, 0);
    }
}
void countingSort(int arr[], int n) 
{
    int output[n + 1];
    int max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int count[max + 1]; // Array de contagem
    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Armazena a contagem de cada elemento
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Armazena a posição de cada elemento no array de saída
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Constroi o array de saída
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copia o array de saída para arr[], para que arr[] contenha os elementos ordenados
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void countingSortForRadix(int array[], int size, int place) {
    int output[size + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++) {
        if (((array[i] / place) % 10) > max)
            max = array[i];
    }

    int count[max + 1];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixSort(int array[], int size) {
    int max = getMax(array, size);

    for (int place = 1; max / place > 0; place *= 10)
        countingSortForRadix(array, size, place);
}





