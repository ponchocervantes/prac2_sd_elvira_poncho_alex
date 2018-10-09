#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


#define DIVISORES_I 100
#define AMIGOS 200
#define TRUE 1
#define FALSE 0

// PROTOTIPOS
unsigned char contenidaKa ( int* arr, int size, int amigo1, int amigo2 );


int cuenta = 0;
int amigos[ AMIGOS ];

int main ( int argc, char* argv ) 
{
    int min, max;
    int i, j, k;
    int divisores[ DIVISORES_I ];
    int sumatoria = 0;
    int sumatoria2 = 0;
    
    long long start_ts;
	long long stop_ts;
	float elapsed_time;
	long lElapsedTime;
	struct timeval ts;
    
    puts( "Ingrese límite inferior: \n" );
    scanf( "%d", &min );
    puts( "Ingrese límite superior: \n" );
    scanf( "%d", &max );
    
    gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec * 1000000 + ts.tv_usec;
    
    for ( i = min; i < max; i++) 
    {
        sumatoria2 = 0;
        sumatoria = 0;
        for ( j = 1; j < i; j++ ) 
        {
            if ( i % j == 0 )
            {
                sumatoria += j;
            }
        }  
        
        for ( j = 1; j < sumatoria; j++ ) 
        {
            if ( sumatoria % j == 0 )
            {
                sumatoria2 += j;
            }
        }
        
        if ( sumatoria2 == i && sumatoria != i && ! contenidaKa( amigos, cuenta, i, sumatoria ) )
        {
            amigos[cuenta++] = i;
            amigos[cuenta++] = sumatoria;
            
        }
    }

    puts( "NUMEROS AMIGOS:" );
    for ( i = 0; i < cuenta; i+= 2 ) 
    {
        printf( "%d, %d\n", amigos[i], amigos[i + 1] );
    }
    
    gettimeofday(&ts, NULL);
	stop_ts = ts.tv_sec * 1000000 + ts.tv_usec; // Tiempo
    
     elapsed_time = (float) (stop_ts - start_ts)/1000000.0;
     printf("Tiempo en %1.2f segundos\n",elapsed_time);
    
    return 0;
}

unsigned char contenidaKa ( int* arr, int size, int amigo1, int amigo2 ) 
{
    int i;
    
    for ( i = 0; i < size; i++ ) 
    {
        if( arr[i] == amigo1 || arr[i] == amigo2 ) return TRUE;
    }
    return FALSE;
}
