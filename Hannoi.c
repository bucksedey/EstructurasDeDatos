//Torres de Hanoi
#include<stdio.h>
#include<math.h>

void Hanoi(int n, char origen, char aux, char destino)
{
    if(n==1)
    {
        printf("\nMueve el disco 1 del palo %c al palo %c",origen,destino);
        return;
    }
    
    Hanoi(n-1,origen,destino,aux);
    printf("\nMueve el disco %d del palo %c al palo %c",n,origen,destino);
    Hanoi(n-1,aux,origen,destino);

}

int main()
{
    int num, mov;
    printf("\nIntroduce el numero de discos a mover: ");
    scanf("%d",&num);

    mov = pow(2,num)-1;
    Hanoi(num,'A','B','C');
    printf("\nNumero de movimiendestinos: %d",mov);
    return 0;
}