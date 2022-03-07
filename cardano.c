#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*
MÉTODO PROPORCIONADO POR:
Gutiérrez Olvera, Lorena. (2016). "Métodos numéricos para resolver ecuaciones y problemas de optimización no lineales". (Tesis de Licenciatura). 
Universidad Nacional Autónoma de México, México. Recuperado de https://repositorio.unam.mx/contenidos/165243
Página 40
*/

#define RCub(X) (pow(X,0.333333333333333333333333333333333333))
#define Cub(X) ((X)*(X)*(X))
#define SQR(X) ((X)*(X))
#define theta(G,H) (acos((G)/sqrt(Cub(-H)))
 
int main(int argc, char *argv[]){
    double a,b,c,D,G,H;
    // NAME  X3 X2 X1 X0
    //  0    1  2  3  4
    if(argc !=5){
        perror("Error de argumentos.");
        return -1;
    }
    if(atoi(argv[1])!=1){
        a=atof(argv[2])/atof(argv[1]); b=atof(argv[3])/atof(argv[1]); c=atof(argv[4])/atof(argv[1]); }
    else{
        a=atof(argv[2]); b=atof(argv[3]); c=atof(argv[4]); }
    //
    H=0.3333333333*b - 0.1111111111*SQR(a);
    G =0.1666666667*a*b - 0.5*c - 0.03703703704*Cub(a); 
    D=SQR(G) + Cub(H);

    if(D<0.0){
        double ang = theta(G,H));
        printf("\nx1 = %lf ", 2.0*sqrt(-H)*cos(ang/3.0) - a/3.0);
        printf("\nx2 = %lf ", 2.0*sqrt(-H)*cos(ang/3.0 + 2.0944) - a/3.0);
        printf("\nx3 = %lf \n", 2.0*sqrt(-H)*cos(ang/3.0 + 4.18879) - a/3.0);
    }
    else{ //(D>0.0) & D==0.0)
        double P = RCub(G+sqrt(D)), Q = RCub(G-sqrt(D)), real,img;
        real= -(P+Q)/2.0 -a/3.0;
        img = (P-Q)*(sqrt(3.0))/2.0;
        printf("\nx1 = %lf", P+Q -a/3.0);
        printf("\nx2 = %lf %+lf i", real , img);
        printf("\nx3 = %lf %+lf i \n", real ,-img);
    }
    return 0;
}
