#include <iostream>
#include <vektor.h>
#include <grafika.h>
#define e 100
#define MH 64
int kVx[MH], kVy[MH];
int dx[8]={2, 1, -1, -2, -2, -1, 1, 2};
int dy[8]={1, 2, 2, 1, -1, -2, -2, -1};
int megoldas=0;
using namespace std;
void feltoltes()
{

    for(int i=0; i<64; i++)
    {
        kVx[i]=0;
        kVy[i]=0;
    }
}
void tabla(cGrafika &gr)
{
    int nr=0;
    for(int i=0; i<800; i+=e)
    {
        for(int j=0; j<800; j+=e)
        {
            if(nr%2==0)
            {
            cVektor a(i,j);
            cVektor b(i+e,j+e);
            gr.tegla(a,b,makecol(255,255,255));
            gr.kirajzol();
            }
            nr++;
        }
        nr++;
    }
}
void lovag(cGrafika &gr, int a, int b)
{
    cVektor kp((a*e+50),(b*e+50));
    gr.korong(kp,40,makecol(255,0,0));
    gr.kirajzol();
}
void bejartnegyzet(cGrafika &gr, int a, int b)
{
    cVektor pont((a*e+1),(b*e+1));
    cVektor pont2((a*e+e-1),(b*e+e-1));
    cVektor pont3((a*e),(b*e));
    cVektor pont4((a*e+e),(b*e+e));
    gr.tegla(pont,pont2,makecol(0,0,255));
    gr.teglalap(pont3,pont4,makecol(0,0,0));
    gr.kirajzol();
}
void kiir(cGrafika &gr)
{
    int nr=1;
    for(int i=0; i<MH; i++)
    {
        if(nr<10)
        {
        cout<<nr<<":  ";
        }
        else cout<<nr<<": ";
        cout<<"x="<<kVx[i]<<"    ";
        cout<<"y="<<kVy[i]<<"    ";
        cout<<endl;
        lovag(gr,kVx[i],kVy[i]);
        rest(300);
        bejartnegyzet(gr,kVx[i],kVy[i]);
            nr++;
    }
}
bool jo(int k)
{
    for(int i=0; i<k; i++)
    {
        if(kVx[i]==kVx[k])
        {
            if(kVy[i]==kVy[k]) return false;
        }
    }
    if(kVx[k]>7 || kVx[k]<0) return false;
    if(kVy[k]>7 || kVy[k]<0) return false;
    return true;
}
void back(cGrafika &gr, int k)
{
    if(k==MH)
    {
        kiir(gr);
        megoldas++;
        return;
    }
    if(megoldas==0)
    {
    for(int i=0; i<8; i++)
    {
        kVx[k]=kVx[k-1]+dx[i];
        kVy[k]=kVy[k-1]+dy[i];
        if(jo(k)) back(gr,k+1);
    }
    }
}
int main()
{
    cGrafika gr(800,800);
    tabla(gr);
    feltoltes();
    back(gr,1);
    cout<<"vege";
    readkey();
    return 0;
}END_OF_MAIN();
