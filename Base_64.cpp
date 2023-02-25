#include<fstream>
#include<iostream>
#include<locale>
#include<string.h>

using namespace std;

class base64
{
	private:
	    char *caracteres;
        int *ennumero;
        int *ennumero2;
        int **binario;
        int *binario2;
        int apuntador;
        int parce;
        int tam;
        int auxcbase;
	public:
		base64();
		~base64();
    	void codificar();
    	void decodificar();
};

base64::base64()
{
	int tam=0;
	int auxcbase=0;
	caracteres = new char[1000];
	if(caracteres==NULL)
	{
		cout<<"Error 1\n";
	}
	ennumero = new int[1000];
	if(ennumero==NULL)
	{
		cout<<"Error 1\n";
	}
    ennumero2 = new int[1000];
    if(ennumero2==NULL)
	{
		cout<<"Error 1\n";
	}
	binario2 = new int[8010];
    if(binario2==NULL)
	{
		cout<<"Error 1\n";
	}
    binario = new int*[1000];
	if(binario==NULL)
	{
		cout<<"\nError 1";
	}
	for(int i=0;i<1000;i++)
	{
	    binario[i] = new int[8];
	    if(binario[i]==NULL)
	    {
	    	cout<<"\nError 2";
		}
    }
	for( int j=0; j<1000;j++)
    {
        caracteres[j] = ' ';
    }
    for( int j=0; j<1000;j++)
    {
        ennumero[j] = 0;
        ennumero2[j] = 0;
    }
    for( int j=0; j<8010;j++)
    {
        binario2[j] = 2;
    }
    for(int i=0; i<1000;i++)
    {
    	for(int j=0; j<8; j++)
    	{
    		binario[i][j]=0;
		}
	}
	apuntador=0;
}

base64::~base64()
{
	delete caracteres;
	delete ennumero;
	delete ennumero2;
	for(int i=0;i<8;i++)
	{
		delete binario[i];
	}
	delete binario;
	delete binario2;
}

void base64::codificar()
{
	cout<<"Trx...\n";
	cout<<"Por favor, ingrese la frase: ";
    cin>>caracteres;
    fflush(stdin);
    tam = strlen(caracteres);
    int j=0;
	ofstream datos("Base64.txt");
	for(int i=0;i<tam;i++)
	{
		ennumero[i]=int(caracteres[i]);
		ennumero2[i]=int(caracteres[i]);
	}
	cout<<"Valores decimales de ascci: ";
	for(int i=0; i<tam; i++)
	{
		cout<<ennumero[i]<<" ";
	}
	cout<<"\n";
	cout<<"Valores binarios de ascci: ";
	int aux=0;
	for(apuntador=0; apuntador<tam; apuntador++)
	{
		while(aux<8)
		{
			binario[apuntador][aux] = ennumero2[apuntador] % 2 ;
            ennumero2[apuntador] = ennumero2[apuntador]/2;
            aux++;
		}
		aux=0;
	}
    aux=7;
    int z=0;
	for(apuntador=0; ennumero[apuntador]!=0; apuntador++)
	{
		while(aux>=0)
		{
			binario2[z]=binario[apuntador][aux];
            aux--;
            z++;
		}
		aux=7;
	}
	for(int i=0; i<z; i++)
	{
		cout<<binario2[i];
		if(j==7)
		{
			j=-1;
			cout<<" ";
		}
		j++;
	}
	cout<<"\n";
	cout<<"Valores binarios juntos: ";
	for(int l=0;l<z;l++)
	{
		cout<<binario2[l];
	}
	cout<<"\n";
	int a=0, b=0, w=0;
	while(a!=1)
	{
		w=w+6;
		if(z<=w)
		{
			int m=z;
			while(m<=w)
			{
				binario2[m]=0;
				m++;
			}
			a=1;
		}
	}
	parce=(w-z)/2;
	z=z+(w-z);
	cout<<"Valores binarios de base64: ";
	for(int l=0;l<z;l++)
	{
		cout<<binario2[l];
		if(j==5)
		{
			j=-1;
			cout<<" ";
		}
		j++;
	}
	cout<<"\n";
	aux=z/6;
	auxcbase = aux+parce;
	int dec[aux];
	char cbase[auxcbase];
	a = 0;
	int c = 0;
	int d=0;
	int sum;
	for(int i=0; i<aux; i++)
	{
		a=0;
		b = 1;
		sum=0;
		while(a!=1)
		{
			if(b==1)
			{
				c=32;
			}
			if(b==2)
			{
				c=16;
			}
			if(b==3)
			{
				c=8;
			}
			if(b==4)
			{
				c=4;
			}
			if(b==5)
			{
				c=2;
			}
			if(b==6)
			{
				c=1;
				a=1;
			}
			sum=sum+(binario2[d]*c);
			b++;
			d++;
		}
		dec[i]=sum;
	}
	cout<<"Valores decimales de base64: ";
	for(int i=0; i<aux; i++)
	{
		cout<<dec[i];
		cout<<" ";
	}

	for(int i=0; i<aux; i++)
	{
		switch (dec[i])
		{
			case 0:
				cbase[i]='A';
				break;
			case 1:
				cbase[i]='B';
				break;
			case 2:
				cbase[i]='C';
				break;
			case 3:
				cbase[i]='D';
				break;
			case 4:
				cbase[i]='E';
				break;
			case 5:
				cbase[i]='F';
				break;
			case 6:
				cbase[i]='G';
				break;
			case 7:
				cbase[i]='H';
				break;
			case 8:
				cbase[i]='I';
				break;
			case 9:
				cbase[i]='J';
				break;
			case 10:
				cbase[i]='K';
				break;
			case 11:
				cbase[i]='L';
				break;
			case 12:
				cbase[i]='M';
				break;
			case 13:
				cbase[i]='N';
				break;
			case 14:
				cbase[i]='O';
				break;
			case 15:
				cbase[i]='P';
				break;
			case 16:
				cbase[i]='Q';
				break;
			case 17:
				cbase[i]='R';
				break;
			case 18:
				cbase[i]='S';
				break;
			case 19:
				cbase[i]='T';
				break;
			case 20:
				cbase[i]='U';
				break;
			case 21:
				cbase[i]='V';
				break;
			case 22:
				cbase[i]='W';
				break;
			case 23:
				cbase[i]='X';
				break;
			case 24:
				cbase[i]='Y';
				break;
			case 25:
				cbase[i]='Z';
				break;
			case 26:
				cbase[i]='a';
				break;
			case 27:
				cbase[i]='b';
				break;
			case 28:
				cbase[i]='c';
				break;
			case 29:
				cbase[i]='d';
				break;
			case 30:
				cbase[i]='e';
				break;
			case 31:
				cbase[i]='f';
				break;
			case 32:
				cbase[i]='g';
				break;
			case 33:
				cbase[i]='h';
				break;
			case 34:
				cbase[i]='i';
				break;
			case 35:
				cbase[i]='j';
				break;
			case 36:
				cbase[i]='k';
				break;
			case 37:
				cbase[i]='l';
				break;
			case 38:
				cbase[i]='m';
				break;
			case 39:
				cbase[i]='n';
				break;
			case 40:
				cbase[i]='o';
				break;
			case 41:
				cbase[i]='p';
				break;
			case 42:
				cbase[i]='q';
				break;
			case 43:
				cbase[i]='r';
				break;
			case 44:
				cbase[i]='s';
				break;
			case 45:
				cbase[i]='t';
				break;
			case 46:
				cbase[i]='u';
				break;
			case 47:
				cbase[i]='v';
				break;
			case 48:
				cbase[i]='w';
				break;
			case 49:
				cbase[i]='x';
				break;
			case 50:
				cbase[i]='y';
				break;
			case 51:
				cbase[i]='z';
				break;
			case 52:
				cbase[i]='0';
				break;
			case 53:
				cbase[i]='1';
				break;
			case 54:
				cbase[i]='2';
				break;
			case 55:
				cbase[i]='3';
				break;
			case 56:
				cbase[i]='4';
				break;
			case 57:
				cbase[i]='5';
				break;
			case 58:
				cbase[i]='6';
				break;
			case 59:
				cbase[i]='7';
				break;
			case 60:
				cbase[i]='8';
				break;
			case 61:
				cbase[i]='9';
				break;
			case 62:
				cbase[i]='+';
				break;
			case 63:
				cbase[i]='/';
				break;
		}
	}
	for(int i=aux; i<auxcbase; i++)
	{
		cbase[i]='=';
	}
	cout<<"\n";
	cout<<"Caracteres en base64: ";
	for(int i=0; i<auxcbase; i++)
	{
		cout<<cbase[i];
		datos<<cbase[i];
	}
	cout<<"\n";
	cout<<"Generando archivo...";
	cout<<"\n";
	cout<<"\n";
}

void base64::decodificar()
{
	cout<<"Rx...\n";
	ifstream salida("Base64.txt");
	int i=0;
	int a=0;
	int aux;
	aux=auxcbase-parce;
	char cbase[auxcbase];
	while(!salida.eof())
	{
		cbase[i]=salida.get();
		i++;
	}
	cout<<"Caracteres en base64 obtenidos del archivo: ";
	for(int i=0; i<auxcbase; i++)
	{
		cout<<cbase[i];
	}
	i=0;
	int dec[aux];
	for(int i=0; i<aux; i++)
	{
		switch (cbase[i])
		{
			case 'A':
				dec[i]=0;
				break;
			case 'B':
				dec[i]=1;
				break;
			case 'C':
				dec[i]=2;
				break;
			case 'D':
				dec[i]=3;
				break;
			case 'E':
				dec[i]=4;
				break;
			case 'F':
				dec[i]=5;
				break;
			case 'G':
				dec[i]=6;
				break;
			case 'H':
				dec[i]=7;
				break;
			case 'I':
				dec[i]=8;
				break;
			case 'J':
				dec[i]=9;
				break;
			case 'K':
				dec[i]=10;
				break;
			case 'L':
				dec[i]=11;
				break;
			case 'M':
				dec[i]=12;
				break;
			case 'N':
				dec[i]=13;
				break;
			case 'O':
				dec[i]=14;
				break;
			case 'P':
				dec[i]=15;
				break;
			case 'Q':
				dec[i]=16;
				break;
			case 'R':
				dec[i]=17;
				break;
			case 'S':
				dec[i]=18;
				break;
			case 'T':
				dec[i]=19;
				break;
			case 'U':
				dec[i]=20;
				break;
			case 'V':
				dec[i]=21;
				break;
			case 'W':
				dec[i]=22;
				break;
			case 'X':
				dec[i]=23;
				break;
			case 'Y':
				dec[i]=24;
				break;
			case 'Z':
				dec[i]=25;
				break;
			case 'a':
				dec[i]=26;
				break;
			case 'b':
				dec[i]=27;
				break;
			case 'c':
				dec[i]=28;
				break;
			case 'd':
				dec[i]=29;
				break;
			case 'e':
				dec[i]=30;
				break;
			case 'f':
				dec[i]=31;
				break;
			case 'g':
				dec[i]=32;
				break;
			case 'h':
				dec[i]=33;
				break;
			case 'i':
				dec[i]=34;
				break;
			case 'j':
				dec[i]=35;
				break;
			case 'k':
				dec[i]=36;
				break;
			case 'l':
				dec[i]=37;
				break;
			case 'm':
				dec[i]=38;
				break;
			case 'n':
				dec[i]=39;
				break;
			case 'o':
				dec[i]=40;
				break;
			case 'p':
				dec[i]=41;
				break;
			case 'q':
				dec[i]=42;
				break;
			case 'r':
				dec[i]=43;
				break;
			case 's':
				dec[i]=44;
				break;
			case 't':
				dec[i]=45;
				break;
			case 'u':
				dec[i]=46;
				break;
			case 'v':
				dec[i]=47;
				break;
			case 'w':
				dec[i]=48;
				break;
			case 'x':
				dec[i]=49;
				break;
			case 'y':
				dec[i]=50;
				break;
			case 'z':
				dec[i]=51;
				break;
			case '0':
				dec[i]=52;
				break;
			case '1':
				dec[i]=53;
				break;
			case '2':
				dec[i]=54;
				break;
			case '3':
				dec[i]=55;
				break;
			case '4':
				dec[i]=56;
				break;
			case '5':
				dec[i]=57;
				break;
			case '6':
				dec[i]=58;
				break;
			case '7':
				dec[i]=59;
				break;
			case '8':
				dec[i]=60;
				break;
			case '9':
				dec[i]=61;
				break;
			case '+':
				dec[i]=62;
				break;
			case '/':
				dec[i]=63;
				break;
		}
	}
	cout<<"\n";
	cout<<"Valores decimales de base64: ";
	for(int i=0; i<aux; i++)
	{
	    cout<<dec[i]<<" ";
	}
	cout<<"\n";
	a=0;
	int sum=0;
	int z=aux*6;
	int binario3[z];
	for(int i=0; i<aux; i++)
	{
			sum=dec[i];
			if(sum>=32)
			{
				binario3[a]=1;
				sum=sum-32;
				a++;
			}
			else
			{
				binario3[a]=0;
				a++;
			}
			if(sum>=16)
			{
				binario3[a]=1;
				sum=sum-16;
				a++;
			}
			else
			{
				binario3[a]=0;
				a++;
			}
			if(sum>=8)
			{
				binario3[a]=1;
				sum=sum-8;
				a++;
			}
			else
			{
				binario3[a]=0;
				a++;
			}
			if(sum>=4)
			{
				binario3[a]=1;
				sum=sum-4;
				a++;
			}
			else
			{
				binario3[a]=0;
				a++;
			}
			if(sum>=2)
			{
				binario3[a]=1;
				sum=sum-2;
				a++;
			}
			else
			{
				binario3[a]=0;
				a++;
			}
			if(sum>=1)
			{
				binario3[a]=1;
				sum=sum-1;
				a++;
			}
			else
			{
				binario3[a]=0;
				a++;
			}
		}
	int j=0;
	cout<<"Valores binarios de base64: ";
	for(int i=0; i<z; i++)
	{
	    cout<<binario3[i];
		if(j==5)
		{
			j=-1;
			cout<<" ";
		}
		j++;
	}
	int x = z-(parce*2);
	cout<<"\n";
	cout<<"Valores binarios juntos: ";
	for(int i=0; i<x; i++)
	{
	    cout<<binario3[i];
	}
	cout<<"\n";
	cout<<"Valores binarios de ascci: ";
	j=0;
	for(int i=0; i<x; i++)
	{
		cout<<binario3[i];
		if(j==7)
		{
			j=-1;
			cout<<" ";
		}
		j++;
	}
	int r=x/8;
	int dec2[r];
	a=0;
	int c=0;
	int d=0;
	int e=0;
	int o=0;
	while(a!=1)
	{
		e=0;
		for(o=0; o<8; o++)
		{
			if(o==0)
			{
				if(binario3[d]==1)
				{
					e=e+128;
				}
			}
			if(o==1)
			{
				if(binario3[d]==1)
				{
					e=e+64;
				}
			}
			if(o==2)
			{
				if(binario3[d]==1)
				{
					e=e+32;
				}
			}
			if(o==3)
			{
				if(binario3[d]==1)
				{
					e=e+16;
				}
			}
			if(o==4)
			{
				if(binario3[d]==1)
				{
					e=e+8;
				}
			}
			if(o==5)
			{
				if(binario3[d]==1)
				{
					e=e+4;
				}
			}
			if(o==6)
			{
				if(binario3[d]==1)
				{
					e=e+2;
				}
			}
			if(o==7)
			{
				if(binario3[d]==1)
				{
					e=e+1;
				}
			}
			d++;
		}
		dec2[c]=e;
		c++;
		if(c==r)
		{
			a=1;
		}
	}
	cout<<"\n";
	cout<<"Valores decimales de ascci: ";
	for(int i=0; i<r; i++)
	{
	    cout<<dec2[i]<<" ";
	}
	char cc[r];
	for(int i=0; i<r; i++)
	{
	    cc[i]=char(dec2[i]);
	}
	cout<<"\n";
	cout<<"Caracteres en ascci: ";
	for(int i=0; i<r; i++)
	{
	    cout<<cc[i];
	}
	cout<<"\n";
	cout<<"\n";
}


int main()
{
	setlocale(LC_CTYPE,"spanish");
	base64 B64;
	B64.codificar();
	B64.decodificar();
}
