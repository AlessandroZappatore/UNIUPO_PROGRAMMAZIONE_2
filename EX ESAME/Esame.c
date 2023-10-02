#include <stdio.h>
#include <stdlib.h>

void ema(float arr[], int i, float a){
    if(i==0){
        printf("EMA(0): %.2f\n", arr[0]);
        return;
    }
    else{
        
    }

}

int main(){
    float arr[]={2.4, 5.1, 0.2, 7.8, 10.0, 0.9};

    for(int i=0; i<6; i++){
        printf("%d) %f\n", i, arr[i]);
    }
    float a=0.5;


    return 0;
}

/*EMA(0)=v[0]
  EMA(i)=a*v[i]+(1*a)*EMA(i-1)  
*/