#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include<iostream>
#include <locale>
using namespace std;

int calc_Eula(int &p,int &q,int &n);
int IsPrime(int &n);
int GetGreatestCommonDivisor(int &c, int &d);
int E(int Euler_n);
int D(int e,int Euler_n);
int Encrypt_m(int m,int e,int n);
int Decrypt_c(int c,int d,int n);

int main()
{
    int p,q;
    while (true) 
    {
        system("cls");
        cout<<"--------------RSA Encrypt Program by WeiguangTWK(SWH)---------------"<<endl
            <<"Please enter prime number P and Q"<<endl
            <<"P=";
        scanf("%d",&p);
        cout<<"Q=";
        scanf("%d",&q);
        cout<<"You entered P="<<(int)p<<" and Q="<<(int)q<<endl;
            //<<"IsPrime(p)="<<IsPrime(p)<<" IsPrime(q)="<<IsPrime(p)<<endl;
        if(IsPrime(p)==1 && IsPrime(q)==1 && p!=q) cout<<"Requirement satisfied, continue...."<<endl;
        else
        {
            cout<<"Please retry"<<endl;
            system("pause");
            continue;
        }
		int n;
        int Euler_n=calc_Eula(p, q,n);
		cout<<"Calcated Eula number "<<Euler_n<<endl;
        int e=E(Euler_n);
        int d=D(e, Euler_n);
        cout<<"Public Key is e="<<e<<" and n="<<n<<endl
            <<"Privete Key is d="<<d<<" and n="<<n<<endl<<endl;

        cout<<"=================Encrypt & Decrypt Ready================="<<endl
            <<"Enter message to encrypy:";
        int measge;
        scanf("%d",&measge);
        int enm = Encrypt_m(measge, e, n);
        cout<<"Encrypted message:"<<enm<<endl;
        int decm=Decrypt_c(enm, d, n);
        cout<<"Decrypted message:"<<decm<<endl;
		break;
    }
	return 0;
}

int calc_Eula(int &p,int &q,int &n)
{
    n=p*q;
    return ((p-1)*(q-1));
}
int IsPrime(int &n)
{
	 int temp = (int)sqrt(n);
	for (int i = 2; i <= temp; i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}
int GetGreatestCommonDivisor(int &c, int &d) 
{
	int a=c,b=d;
	int t;
	if (a < b) 
	{
		t = a;
		a = b;
		b = t;
	}
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	cout<<"Get Greatest Common Divisor of "<<c<<" and "<<d<<" is "<<a<<endl;
	return a;
}

int E(int Euler_n)
{
    int e;
	e = rand() % (Euler_n - 1) + 1;
	do
	{
	e = rand() % (Euler_n - 1) + 1;
	} while (GetGreatestCommonDivisor(Euler_n , e)!=1);
    return e;
}

int D(int e,int Euler_n)
{

    int d;
	int Sign_of_Inverse_Element=0;
	do
	{
		for (int i = 1; i <Euler_n; i++)
		{
			if ((i * e) % Euler_n == 1)
			{
				Sign_of_Inverse_Element = 1;
				d = i;
			}
		}
	} while (Sign_of_Inverse_Element !=1);
    return d;
}


int Encrypt_m(int m,int e,int n)
{
	int product = 1;  
	for (int i = 1; i <=e; ++i)
	{
        product = (product *m)%n;
    };  
	return product;
}


int Decrypt_c(int c,int d,int n)
{
	int product = 1;
	for (int i = 1; i <= d; ++i)
	{
        product = (product * c) %n;
    }
	return product;
}

