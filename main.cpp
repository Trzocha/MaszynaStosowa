#include <iostream>
 
using namespace std;
 
struct Lista
{
int liczba;
Lista *kolejny_el;
Lista (){kolejny_el =NULL;}
};
 
void czynnosci(Lista *&nowy,char znak,int &elementy);
void dodaj_el(Lista *&Dane,int liczba);
void wypisz_el(Lista *Dane);
void usun_el(Lista *&Dane);
//void zamiana_el(Lista *&Dane);
void Suma2_el(Lista *&Dane);
void zamiana_el(Lista *&Dane,int przesun);
bool wczytaj_dane();
int convertNaInt(int buffor[],int dlug);
void czyscbuffor(int buffor[]);
 
 
int main()
{
bool x;
        x = wczytaj_dane();
        return x;
}
 
void czynnosci(Lista *&nowy, char znak,int &elementy)
{
int zdjeta=0;
                   switch(znak)
                   {
                   case 'p':
                           wypisz_el(nowy);                 //zastepczo
                           break;
                   case 's':                            //zamiana 2 elementow na szczycie stosu
                           if(elementy>=2)
                           zamiana_el(nowy,2);
                           break;
                   case 'x':
                           usun_el(nowy);                    //zrobione
                           elementy--;
                           break;
                   case '+':
                                   if(elementy>=2){
                           Suma2_el(nowy);                   //sumuje 2 elementy na szczycie i usuwa pierwszy element
                           elementy--;}
                           break;
                   case 'r':
                               zdjeta = nowy->liczba;               //wierzcholek stosu
                               if(zdjeta == 0 || zdjeta ==1){usun_el(nowy); elementy--;}
                               if(zdjeta == 2) {usun_el(nowy); elementy--; zamiana_el(nowy,zdjeta);}
                               if(zdjeta >= 3)
                               {
                                   if(zdjeta <= elementy)
                                   {
                                          usun_el(nowy);
                                          elementy--;
                                          zamiana_el(nowy,zdjeta);
                                   }else {usun_el(nowy); elementy--;}
                               }
                                   break;
 
                   };
 
}
 
void dodaj_el(Lista *&Dane,int wartosc)
{
Lista *nowy = new Lista;
Lista *pomocnicza;
 
        nowy->liczba = wartosc;   //nie zamienia
        pomocnicza = Dane;
        Dane = nowy;
        nowy->kolejny_el = pomocnicza;
}
 
void wypisz_el(Lista *Dane)
{
        while(Dane != NULL)
    {
        cout<<Dane->liczba<<" ";
        Dane = Dane->kolejny_el;
    }
        cout <<"\n";
}
 
void usun_el(Lista *&Dane)
{
        Lista *pomocnicza;
        pomocnicza = Dane;
        Dane = Dane->kolejny_el;
delete pomocnicza;
}
 
void Suma2_el(Lista *&Dane)
{
 int liczba1,liczba2;
                 liczba1 = Dane->liczba;
                 usun_el(Dane);
                 liczba2 = Dane->liczba;
                 usun_el(Dane);
                 liczba1 = liczba1+liczba2;
                 dodaj_el(Dane,liczba1);
 
}
void zamiana_el(Lista *&Dane,int przesun)
{
Lista *ide,*pom1;
int dalej = przesun;
        ide  = pom1 = Dane;
 
                for(int i=1;i<dalej;i++)         //idzie po liscie do elementu na zamiane
                   ide = ide->kolejny_el;
 
        Dane = pom1->kolejny_el;
        pom1->kolejny_el = ide->kolejny_el;
        ide->kolejny_el = pom1;
 
}
int convertNaInt(int buffor[],int dlug)
{
int liczba=0;
int pom[10]={0};
int k=1;
        for(int i=dlug,j=0;i>=0;i--,j++)
                pom[j] = buffor[i];
        for(int i=0;i<10;i++){
                liczba = liczba+pom[i]*k;
                k=k*10;
        }
 
return liczba/10;
}
void czyscbuffor(int buffor[])
{
for(int i=0;i<10;i++)
        buffor[i]=0;
}
bool wczytaj_dane()
{
        char znak;
        int buffor[10]={0};
        char buff[1000]={' '};
        int i=0;
        char *licznikbuffora;
        int liczba;
        Lista *nowy=NULL;
        int ilosc_el =0;
 
          while(fgets(buff,1000,stdin))
          {
                licznikbuffora = &buff[0];
                while(*licznikbuffora!='\n')
                        {
                        znak = *licznikbuffora;
                        licznikbuffora++;
                                if(znak >= '0' && znak<='9')
                                {
                                        buffor[i] = znak-48;
                                        i++;
                                }else if(znak >= '0' && znak<='9' && i>0)
                                                        {
                                                                buffor[i] = znak-48;
                                                                i++;
                                                        }else {
                                                                if(i==0)
                                                                        {
                                                                        if(znak == 'q'){return 0;}
                                                                        else czynnosci(nowy,znak,ilosc_el);
                                                                }else
                                                                        {
                                                                        liczba = convertNaInt(buffor,i);
                                                                        czyscbuffor(buffor);
                                                                        dodaj_el(nowy,liczba);
                                                                        ilosc_el++;
                                                                        czynnosci(nowy,znak,ilosc_el);
                                                                        i=0;
                                                                        }
 
                                                        }
 
                        }
          }
   return 0;
}
