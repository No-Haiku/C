#include <stdio.h>
#include <stdlib.h>

int main()
{
//    int *punt,i;
//    int x[5]= {1,2,3,4,5};
//    punt=x;
//    *punt=9;
//    int *punt,i;
//    int x[5]= {1,2,3,4,5};
//    punt=&x[0];
//    *punt=9;
//    punt[3]=7;
    int *punt,i;
    int x[5]= {1,2,3,4,5};
    punt=x;
    *x=11;
    *(punt+3)=9 ;
    for(i=0; i<5; i++)
    {
        printf("%d,",x[i]); // ¿qué imprime
    }

    return 0;
}
