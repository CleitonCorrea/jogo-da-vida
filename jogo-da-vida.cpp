//Autor Cleiton Correa
//Data 23/11/2014
//Versão 4.0
//Objetivo: Simular o Jogo da Vida de Jonw Cowen

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "iostream"
#include "conio.h"
#include "windows.h"
#include <locale.h>
#include <locale.h>
using namespace std;


//	Construindo a matriz que foi digitada pelo usuário.

int mat(int *a,int replica[5][5])
    {
	int i,j,k,l,c,y,w,esc;
	if(*a==1)
	{
        replica[2][1]=1;
		replica[2][2]=1;
		replica[2][3]=1;
	}
	if(*a==2)
	{
        replica[1][1]=1;
		replica[1][2]=1;
        replica[2][1]=1;
		replica[2][2]=1;
    }
	if(*a==3)
	{
		replica[1][1]=1;
		replica[1][2]=1;
		replica[1][3]=1;
        replica[2][2]=1;
    }
	if(*a==4)
	{
		replica[1][2]=1;
        replica[2][3]=1;
        replica[3][1]=1;
		replica[3][2]=1;
		replica[3][3]=1;
    }
	if(*a==5)
	{
        replica[1][2]=1;
		replica[1][3]=1;
        replica[2][1]=1;
		replica[2][2]=1;
        replica[3][2]=1;
    }
	if(*a==6)
	{
		cout<<"Preencha as posições da matriz"<<endl;
            for(i=0;i<5;i++)
			{
                for(j=0;j<5;j++)
				{
					system("cls");
					k=0;
					while(k<1)
					{
						cout<<"Valor das posições: 1 para vivo e 0 para morto\n\n"<<endl;
						for(l=0;l<5;l++)
						{
							cout<<"\t\t\t";
							for(c=0;c<5;c++)
							{
								if(i==l&&j==c)
								{
									cout<<"X";
									y=i;
									w=j;
								}
								else
								{
									cout<<replica[l][c];
								}
							}
							cout<<endl;
						}
						cin>>esc;
						if(esc==1)
						{
                            k=1;
						}
						if(esc==0)
						{
							k=1;
						}
						if(esc!=1&&esc!=0)
						{
							system("cls");
							cout<<"\n\n Escolha \n1 para vivo e \n0 para morto"<<endl;
						}

					}
					replica[i][j]=esc;
				}
			}
	}
return 0;
}

//O procedimento matrizreplica faz a impressao na tela da matriz 5x5 a ser replicada
void matrizreplica(int replica[5][5])
{
	int i,j;
	cout<<endl;
	for(i=0;i<5;i++)
	{
		cout<<"\t\t\t";
		for(j=0;j<5;j++)
		{
			cout<<replica[i][j];
		}
		cout<<endl;
	}

}

/*
	A função abaixo faz a verificação das celulas vivas, acumulando a
	quantidade em um contador chamado verd, ao final conforme as regras
	ele determinará se a celula viva permanece viva ou morre e, se uma
	celula morta viverá.
*/

int verifica(int matriz[25][75],char matrizchar[25][75])
{
	int i,j,reflex[25][75],verd=0,somavivo=0;

//Transportando a matriz original para uma matriz de nome reflex
	for(i=0;i<25;i++)
	{
		for(j=0;j<75;j++)
		{
			reflex[i][j]=matriz[i][j];
		}
	}
/*Fim da transferencia de conteudos entre as matrizes.

               Inicio dos testes de posições:
			   Vou descrever a matriz da seguinte forma:
					  A B C
					  D E F
					  G H I

			   Sendo:
                   A canto superior esquerdo
                   B posições entre cantos A e C
                   C canto superior direito
                   D posições entre cantos A e G
                   E posições no meio da matriz
                   F posições entre os cantos C e I
                   G canto inferior esquerdo
                   H posições entre os cantos G e I
                   I canto inferior direito
                   */

	for(i=0;i<25;i++)//--Contador/gerador de linhas
	{
	   for(j=0;j<75;j++)//--Contador/gerador de colunas
	   {
		 verd=0;
		 if(i==0&&j==0)//--Verifica posição de canto A
		 {
			if(reflex[i][j+1]==1)
			{
			verd++;
			}
			if(reflex[i+1][j+1]==1)
			{
			verd++;
			}
			if(reflex[i+1][j]==1)
			{
			verd++;
			}
		 }

		 if(i==0&&(j>0&&j<74))       //Verifica posições entre cantos B
		 {
			if(reflex[i][j-1]==1)
			{
			verd++;
			}
			if(reflex[i+1][j-1]==1)
			{
			verd++;
			}
			if(reflex[i+1][j]==1)
			{
			verd++;
			}
			if(reflex[i+1][j+1]==1)
			{
			verd++;
			}
			if(reflex[i][j+1]==1)
			{
			verd++;
			}
		 }
		 if(i==0&&(j==74))     //Verifica posição de canto C
		 {
			if(reflex[i][j-1]==1)
			{
			verd++;
			}
			if(reflex[i+1][j-1]==1)
			{
			verd++;
			}
			if(reflex[i+1][j]==1)
			{
			verd++;
			}

		 }
		 if(i==24&&j==0)      //Verifica posição de canto G
		 {
			if(reflex[i-1][j]==1)
			{
			verd++;
			}
			if(reflex[i-1][j-1]==1)
			{
			verd++;
			}
			if(reflex[i][j-1]==1)
			{
			verd++;
			}
		 }
		 if(i==24&&j==74)    //Verifica posição de Canto I
		 {
			if(reflex[i-1][j]==1)
			{
			verd++;
			}
			if(reflex[i-1][j-1]==1)
			{
			verd++;
			}
			if(reflex[i][j-1]==1)
			{
			verd++;
			}
		 }

		 if((i!=0&&j!=74)&&(i!=24&&j!=0))  //Verifica as posições centrais E
		 {
			if(reflex[i-1][j]==1)
			{
			verd++;
			}
			if(reflex[i-1][j+1]==1)
			{
			verd++;
			}
			if(reflex[i][j+1]==1)
			{
			verd++;
			}
			if(reflex[i+1][j+1]==1)
			{
			verd++;
			}
			if(reflex[i+1][j]==1)
			{
			verd++;
			}
			if(reflex[i+1][j-1]==1)
			{
			verd++;
			}
			if(reflex[i][j-1]==1)
			{
			 verd++;
			}
			if(reflex[i-1][j-1]==1)
			{
			verd++;
			}
		 }         //Fim dos testes de posições

		 if(verd<2&&(matriz[i][j]==1))      //Inicio das alterações na matriz original
		 {
		 matriz[i][j]=0;
		 }
		 if((verd>3)&&(matriz[i][j]==0))
		 {
		 matriz[i][j]=1;
		 somavivo++;
		 }
		 if(verd>3&&matriz[i][j]==1)
		 {
			 matriz[i][j]=0;

		 }
		 if(verd==3)
		 {
		 matriz[i][j]=1;
		 }


	  }      //Fim do for de J;

   }      //Fim do for de I

return somavivo;
}

/* A Função abaixo faz a replica da Matriz de 5x5 (replica) na
   matriz 25x75.
*/
int replicando(int matriz[25][75], int replica[5][5])
{
	int a,b,l,c;

	for(l=0;l<25;l++)// for para linha da matriz 25x75
	{
		for(c=0;c<75;c++)// for para coluna da matriz 25x75
		{
			for(a=0;a<5;a++)// for para linha a replica 5x5
			{
				for(b=0;b<5;b++)//for para coluna da replica 5x5
				{
					matriz[l+a][c+b]=replica[a][b];
				}
			}
		c +=4;
		}
	l +=4;
	}
return 0;
}

//Esta rotina mostra as estatiscas do jogo

void estatisticas(int *opcao,int *quant, int *totalvivos,int *vivos,int *gervivos,int replica[5][5])
{
	system("cls");
	cout<<"\t\tEstatisticas do jogo\n";
	cout<<"Matriz replicada:\n";
        matrizreplica(replica);
	cout<<"\n\n";
	cout<<"Quantidade total de ciclos solicitados"<<*opcao<<endl;
	cout<<"Quantidade de Ciclos Efetuados"<<*quant<<endl;
	cout<<"Quantidade de vivos na ultima geracao: "<<*totalvivos<<endl;
	cout<<"Quantidade total de celulas mortas que viveram "<<*vivos<<endl;
	cout<<"Quantidade Total de vivos (soma de vivos de todas geracoes):"<<*gervivos<<endl;

}

// Esta rotina mostrará o grafico do jogo referente a evolução das gerações caso houver
void vergrafico(int grafico[1000],int *quant)
{
	int i,j,para;
	cout<<"Evolucao da Geração Atual"<<endl;
	for(i=0;i<*quant;i++)
	{
		para=grafico[i]/10;//calculo para a demonstracao de 60 colunas
		if(para>70)
			  para=70;
		cout<<"Ciclo: "<<i+1;
		for(j=0;j<para;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
}

//Inicio do método main

int main()
{
	int i,j,opcao,matriz[25][75],replica[5][5],grafico[1000],quant,escolha,totalvivo=0,gervivos=0,vivos=0,cont=0,pausa=100,opausa;
	char matrizchar[25][75],vivo='*',morto=' ';

	 setlocale(LC_ALL, "Portuguese"); // função da biblioteca locale para acentuar as strings do meu programa

//Preenchendo a matriz inicial com 0

for(i=0;i<25;i++)
	{
	   for(j=0;j<75;j++)
	   {
		   matriz[i][j]=0;
	   }
	}
	for(i=0;i<25;i++)
	{
	   for(j=0;j<75;j++)
	   {
		   matrizchar[i][j]=' ';
	   }
	}

//Exibindo a matriz inicial

	for(i=0;i<25;i++)
	{
	   for(j=0;j<75;j++)
	   {
		   cout<<matriz[i][j];
	   }
		cout<<endl;
	}
	cout<<"A matriz original foi preenchida com 0: (pressione uma tecla para continuar...)"<<endl;
	getch();
	system("cls");
	i=0;

// Matriz Replíca, você pode escolher uma das opções padrão do jogo ou fazer sua própria matriz
	for(i=0;i<5;i++)
	{
	   for(j=0;j<5;j++)
	   {
		   replica[i][j]=0;
	   }
	}

	cout<<"Você poderá escolher nossas opções padrão:"<<endl;
	cout<< "1:\t"<<"00000"<<"\t2:"<<"\t00000"<<"\t3:"<<"\t00000"<<"\t4:"<<"\t00000"<<"\t5:"<<"\t00000"<<endl;
	cout<< " \t"<<"00000"<<"\t "<<"\t01100"<<"\t "<<"\t01110"<<"\t "<<"\t00100"<<"\t "<<"\t00110"<<endl;
	cout<< " \t"<<"01110"<<"\t "<<"\t01100"<<"\t "<<"\t00100"<<"\t "<<"\t00010"<<"\t "<<"\t01100"<<endl;
	cout<< " \t"<<"00000"<<"\t "<<"\t00000"<<"\t "<<"\t00000"<<"\t "<<"\t01110"<<"\t "<<"\t00100"<<endl;
	cout<< " \t"<<"00000"<<"\t "<<"\t00000"<<"\t "<<"\t00000"<<"\t "<<"\t00000"<<"\t "<<"\t00000"<<endl;
	cout<< "Ou tecle 6 para digitar uma matriz a ser replicada"<<endl;
	cin>>opcao;

	mat(&opcao,replica);
	cout<<"\NMatriz"<<endl;
	matrizreplica(replica);
	cout<<"\n\nEnter P/ Continuar...";
	getch();
	replicando(matriz,replica);
	system("cls");
	cout<<"\ Maximize a a tela para ver melhor!"<<endl;
	cout<<"\nENTER ->..."<<endl;
	getch();
	system("cls");
	cout<<"\n Matriz replicada:"<<endl;

	for(i=0;i<25;i++)
	{
	   for(j=0;j<75;j++)
	   {
		   cout<<matriz[i][j];
	   }
		cout<<endl;
	}
	cout<<"\n\n Quantos ciclos de gerções você deseja?"<<endl;
	cin>>opcao;
	system("cls");
	cout<<"Pause para ver as mudanças a cada ciclo\n\n 1 - SIM \n 2 - NAO:"<<endl;
	cin>>opausa;
	if(opausa==1)
	{
		cout<<"\nInforme o tempo em miléssimos de segundos (1000 milisegundos = 1 segundo)"<<endl;
		cin>>pausa;
	}
	cout<<"E possivel alterar o sinal de vivos e mortos para caracteres deseja utilizar?\nDigite 1 para sim e 2 para nao:"<<endl;
	cin>>escolha;

	if(escolha==1)
	{
		cout<<"Digite o caracter para vivo"<<endl;
		vivo=getch();
		cout<<"Digite o caracter para morto"<<endl;
		morto=getch();
		quant=0;
		while(quant<opcao)
		{
			totalvivo=0;
			system("cls");
			vivos+=verifica(matriz,matrizchar);
			for(i=0;i<25;i++)
			{
				for(j=0;j<75;j++)
				{
					if(matriz[i][j]==0)
					{
						cout<<morto;
					}
					if(matriz[i][j]==1)
					{
						cout<<vivo;
						totalvivo++;
						gervivos++;
					}
				}
			cout<<endl;
			}
			cout<<"Ciclo"<<quant+1<<" Quantidade de vivas neste ciclo: "<<totalvivo<<" Ciclos Solicitados: "<<opcao;
		grafico[quant]=totalvivo;
		quant++;
		Sleep(pausa);
		if(quant==opcao)
			{
				cout<<"\nFim dos Ciclos solicitados, deseja mais ciclos? Digite 1 para sim e 2 para nao";
				int ciclos;
				cin>>ciclos;
				if(ciclos==1)
				{
					cout<<"Digite a quantidade de ciclos: ";
					cin>>cont;
					opcao+=cont;
				}
				if(ciclos==2)
				{
					estatisticas(&opcao,&quant,&totalvivo,&vivos,&gervivos,replica);
					vergrafico(grafico,&quant);
				}
			}
			if(totalvivo==0)
			{
				cout<<"\nTotal de Vivos = 0 Fim de jogo"<<endl;
				cout<<"Pressione uma tecla para ver as estatisticas";
				getch();
				estatisticas(&opcao,&quant,&totalvivo,&vivos,&gervivos,replica);
				quant=opcao;
				vergrafico(grafico,&quant);
			}
		}
	}
	if(escolha==2)
	{
		quant=0;
		while(quant<opcao)
		{
			totalvivo=0;
			system("cls");
			vivos+=verifica(matriz,matrizchar);
			for(i=0;i<25;i++)
			{
				for(j=0;j<75;j++)
				{
					if(matriz[i][j]==0)
					{
						cout<<matriz[i][j];
					}
					if(matriz[i][j]==1)
					{
						cout<<matriz[i][j];
						totalvivo++;
						gervivos++;
					}
				}
				cout<<endl;
			}
			cout<<endl;
			cout<<"Ciclo"<<quant+1<<" Quantidade de vivas neste ciclo: "<<totalvivo<<" Ciclos Solicitados: "<<opcao;
			grafico[quant]=totalvivo;
			quant++;
			Sleep(pausa);
			if(quant==opcao)
			{
				cout<<"\nFim dos Ciclos solicitados, deseja mais ciclos? Digite 1 para sim e 2 para nao";
				int ciclos;
				cin>>ciclos;
				if(ciclos==1)
				{
					cout<<"Digite a quantidade de ciclos: ";
					cin>>cont;
					opcao+=cont;
				}
				if(ciclos==2)
				{
					estatisticas(&opcao,&quant,&totalvivo,&vivos,&gervivos,replica);
					vergrafico(grafico,&quant);
				}
			}
			if(totalvivo==0)
			{
				cout<<"\nTotal de Vivos = 0 Fim de jogo"<<endl;
				cout<<"Pressione uma tecla para ver as estatisticas";
				getch();
				estatisticas(&opcao,&quant,&totalvivo,&vivos,&gervivos,replica);
				cout<<"grafico : "<<grafico[0];
				vergrafico(grafico,&quant);
				quant=opcao;

			}

		}
	}
getch();

}
