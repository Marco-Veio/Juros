#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    system("color F0");
    char sair;
    do{
        const int tam=2;
        int e=0,er,parcelas;
        char escolha[tam],move,cont;
        float montante,capital,taxa,ans;
        do{
            system("cls");
            for(er=0;er<tam;er++)
                escolha[er]=' ';
            escolha[e]=254;
            printf("%c Juros simples\n%c Juros compostos\n",escolha[0],escolha[1]);
            do{
                do{
                    move=getch();
                }while(move!=-32 && move!=13 && move!=27 && move!='w' && move!='s' &&(move<'1' && move>'2'));
                if(move==-32)
                    move=getch();
            }while(move!='H' && move!='P' && move!='w' && move!='s' && move!=13 && move!=27 &&(move<'1' && move>'2'));
            if(move>='1' && move<='2')
                e=move-49;
            switch(move){
                case 'w':
                case 'H':if(e>0) e--;else e=tam-1;break;
                case 's':
                case 'P':if(e<tam-1) e++;else e=0;break;
                case 27:return 0;break;
            }
        }while(move!=13);
        if(e==0){
            do{
                system("cls");
                printf("Irei calcular o montante de um sistema de juros simples!\nQual %c a capital? ",-126);
                scanf("%f",&capital);
                printf("Qual %c a taxa de juros? ",-126);
                scanf("%f",&taxa);
                printf("Quantas parcelas? ");
                scanf("%d",&parcelas);
                printf("\n");
                montante=capital+(capital*taxa*parcelas/100);
                printf("O valor a ser pago %c R$%.2f",-126,montante);
                printf("\n\nAperte enter para recome%car, backspace para voltar ou esc para sair",-121);
                do{
                    sair=getch();
                }while(sair!=13 && sair!=8 && sair!=27);
            }while(sair==13);
        }
        if(e==1){
            do{
                system("cls");
                printf("Irei calcular o montante de um sistema de juros compostos!\nQual %c a capital? ",-126);
                scanf("%f",&capital);
                printf("Qual %c a taxa de juros? ",-126);
                scanf("%f",&taxa);
                printf("Quantas parcelas? ");
                scanf("%d",&parcelas);
                printf("\n");
                for (cont=parcelas,ans=1;cont!=0;cont--,ans*=(1+taxa/100)){}
                montante=capital*ans;
                printf("O valor a ser pago %c R$%.2f\n",-126,montante);
                printf("\n\nAperte enter para recome%car, backspace para voltar ou esc para sair",-121);
                do{
                    sair=getch();
                }while(sair!=13 && sair!=8 && sair!=27);
            }while(sair==13);
        }
    }while(sair==8);
}
