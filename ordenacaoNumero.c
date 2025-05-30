#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

 main()
{
    // numeros a serem ordenados
    int num[]={1,3,48,78,9,0,9,23,67,1,2,55,6,4,5,56,78,12,23,4,5,7,98,76,45,11,10,16,7,3,6,16,26,56,45,89,100,34,54,789,232,14,177,676,890,900,786,123432,67654,898,99,767,56,55,790,8,879,988,1008,787};
    int tamanho= sizeof(num)/sizeof(num[0]);
    int i,f= 0;
    int nmaior= num[0];

    //ver qual é o numero dentro do  array 
    for(i=0;i<=tamanho;i++)
    {
       if(num[i]>nmaior) nmaior=num[i];
    }
    
    //essa liha cria um vetor que a locação de memoria e o vetor começa em 0
     int *count = (int *)calloc(nmaior+1, sizeof(int));
     
     // Função para saber o tempo de execução
     double start = omp_get_wtime();
    // Aqui começa a entrar o OpenMP 
    #pragma omp parallel for
    for(i=0;i<tamanho;i++)
   {
    #pragma omp atomic 
    count[num[i]]++;
   }
    
   // Essa parte segue sequencial pq é muito complicado por em paralelo 
   for(i=0; i<= nmaior;i++)
   {
    while(count[i]-- >0)
    {
        num[f++]=i;
    }
   }
  double end = omp_get_wtime();

   printf("Esses sao os numeros ordenados:");
   for(i=0;i<tamanho; i++)
   {
    printf("%d , ", num[i]);
   }
   printf("Tempo de execução: %f segundos\n", end - start);

   free(count); // liberando a memoria que foi ocupada 
   return 0;

}