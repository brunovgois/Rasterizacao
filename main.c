#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define zeroX 40
#define zeroY 10

void showMenu();
void imprimeRetaDDA();
void imprimeRetaBresenham();
void imprimePlanoCartesiano();
void posicionaCursorNaPosicao(int, int);
void calculaDDA(int, int, int, int);
void calculaBresenham(int, int, int, int); 
int main() {
   showMenu();
   return 0;

}

void showMenu() {
   int option;
   while(option != 0) {
      printf("Algoritmos de Rasterizacao\n");
      printf("----------------------------\n");
      printf("(0) - Sair\n");
      printf("(1) - Imprime uma reta (Algoritmo DDA)\n");
      printf("(2) - Imprime uma reta (Algoritmode Bresenham)\n");
      printf("(3) - Imprime polilinhas formando um poligono (Algoritmo DDA)\n");
      printf("(4) - Imprime polilinhas formando um poligono (Algoritmo de Bresenham)\n");
      printf("(5) - Imprime o tracado de um cicrculo (Teorema de Pitagoras)\n");
      printf("(6) - Imprime o tracado de um cicrculo (Sistemas de coordenadas polares)\n");
      printf("(7) - Imprime o tracado de um circulo (Algoritmo de Bresenham)\n");

      scanf("%d", &option);
            
      switch (option)
      {
         case 0:
            continue;
         case 1:
            imprimeRetaDDA();
            break;
         case 2:
            imprimeRetaBresenham();
            break;
         case 3:
            printf("case 3");
            break;
         default:
            printf("\nValor invalido, tente novamente.\n");
            break;
      }
   }
}

void imprimeRetaBresenham() {
      int x1, x2, y1, y2;

   imprimePlanoCartesiano();

   printf("Digite o valor para x1\n");
   scanf("%d", &x1);
   printf("Digite o valor para y1\n");
   scanf("%d", &y1);
   printf("Digite o valor para x2\n");
   scanf("%d", &x2);
   printf("Digite o valor para y2\n");
   scanf("%d", &y2);

   calculaBresenham(x1, x2, y1, y2);
}

void imprimeRetaDDA() {
   int x1, x2, y1, y2;

   imprimePlanoCartesiano();

   printf("Digite o valor para x1\n");
   scanf("%d", &x1);
   printf("Digite o valor para y1\n");
   scanf("%d", &y1);
   printf("Digite o valor para x2\n");
   scanf("%d", &x2);
   printf("Digite o valor para y2\n");
   scanf("%d", &y2);


   calculaDDA(x1, x2, y1, y2);
}


void posicionaCursorNaPosicao(int x, int y) {
   COORD coord;
   coord.X = (short) x;
   coord.Y = (short) y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void imprimePlanoCartesiano() {
   system("cls");
   printf("\n");
   int x, y;

   for(y = 0; y < 25; y++) {
      posicionaCursorNaPosicao(40, y);
      printf("|");
   }

   for(x = 0; x < 80; x++) {
      posicionaCursorNaPosicao(x, 10);
      printf("-");
   }

   posicionaCursorNaPosicao(0, 30);
   printf("\n");
}

void calculaDDA(int x1, int x2, int y1, int y2){
   double step = fmax(fabs((double)(x2 - x1)), fabs((double)(y2-y1)));

   double xInc = (x2 - x1)/ step;
   double yInc = (y2 - y1)/ step;

   double xPlot = (double) (x1 + zeroX); 
   double yPlot = (double) (y1 + zeroY);

   int contador = 1;

   while(xPlot != (x2 + zeroX)) {
      posicionaCursorNaPosicao((int) round(xPlot), (int) round(yPlot));
      printf("%c", 254);


      xPlot = xPlot + xInc;
      yPlot = yPlot - yInc;

      posicionaCursorNaPosicao(0, 40+contador);
      if(contador == 1){
         printf("Ponto 0->");
         printf("XPlot --- %.1f ", (double) x1);
         printf("yPlot --- %.1f\n", (double) y1);
         contador++;

      }
      printf("Ponto %d->", contador);
      printf("xPlot --- %.1f ", xPlot-zeroX);
      //bug
      printf("yPlot --- %.1f", yPlot-zeroY);
      
      contador++;
   }

   posicionaCursorNaPosicao(0, 43+contador);
   printf("step--- %f\n", step);
   printf("xInc--- %f\n", xInc);
   printf("yInc---%f\n", yInc);
   printf("\n");
} 

void calculaBresenham(int x1, int x2, int y1, int y2) {

}

