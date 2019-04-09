#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main(){
    int *x,*c,nLinhas,nColunas,nCamadas;//sendo c o centro e x a matriz3d
    float *r=malloc(3*sizeof(int));//o r representa 0 raio nas três coordenadas
    printf("numero de linhas: ");
    scanf("%d",&nLinhas);
     printf("numero de colunas: ");
    scanf("%d",&nColunas);
     printf("numero de camadas: ");
    scanf("%d",&nCamadas);
     printf("raioX: ");
    scanf("%fl",r);
     printf("raioY: ");
    scanf("%fl",(r+1));
     printf("raioZ: ");
    scanf("%fl",(r+2));
     //printf("%d %d %d %fl ",nLinhas,nColunas,nCamadas,raio);
    x = (int *)malloc(nLinhas*nColunas*nCamadas*sizeof(int));
    c = (int *)malloc(3*sizeof(int));
    *(c)=nLinhas/2;
    *(c+1)=nColunas/2;
    *(c+2)=nCamadas/2;
    for(int k=0;k<nCamadas;k++){
        for(int i=0;i<nLinhas;i++){
            for(int j=0;j<nColunas;j++){
                if(sqrt((i-*(c))*(i-*(c))/((*r)*(*r))+(j-*(c+1))*(j-*(c+1))/((*(r+1))*(*(r+1)))+(k-*(c+2))*(k-*(c+2))/(((*(r+2))*(*(r+2)))))<=1){
                    *(x+nLinhas*nColunas*k + i*nColunas+j)=1;
                }
                else{
                     *(x+nLinhas*nColunas*k + i*nColunas+j)=0;
                }
            }
        }
    }
     for(int k=0;k<nCamadas;k++){
        for(int i=0;i<nLinhas;i++){
            for(int j=0;j<nColunas;j++){
                   printf("%d ",*(x+nLinhas*nColunas*k + i*nColunas+j));
                }
                printf("\n");
            }
            printf("\n");
        }
        free(c);
        free(x);
        printf("%d",*x);
    return 0;
}
