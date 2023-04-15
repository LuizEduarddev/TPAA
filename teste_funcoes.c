#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
    char hash[11];
    int resultado = 0;
    for (int i=0; i < 5; i++)
    {
        resultado = 48 + (rand() % 9);
        hash[2 * i] = 48 + (rand() % 9);
        hash[2 * i + 1] = 65 + (rand() % 26);
    }
    for (int i=0; i < 10; i++)
    {
        printf("%c", hash + i);
    }
    
}
