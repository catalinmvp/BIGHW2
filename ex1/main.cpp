#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");
ifstream f("believe.in");
struct nod
{
    int nr;
    char name[20];
    char nameproj[20];
    nod *urm;
    nod *prev;
}*p,*u;
int rand(void);
int n,k;//nr of stud and proj

struct sth{

char project[20];

}y[10];
int x[10];

char* speciala(int z)
{
    return y[z].project;
}



void citire()
{

    nod *q;
    for(int i=0;i<n;i++)
    {
        fin.get();

        q=new nod;
        fin.getline(q->name,20);
        q->nr=rand() % 2 + 1;
        q->urm=NULL;
        q->prev=NULL;

        if(p==NULL)
            p=u=q;

        else
        {
            u->urm=q;
            q->prev=u;
            u=q;
        }
    }



}
void afisare()
{
    nod *q;
    q=p;
    while(q!=NULL)
    {
        fout<<q->name<<" "<<q->nr<<" ";
        q=q->urm;

    }
    fout<<endl;
}


void afis(int k1)
{
    nod *q=p;



    for(int i=0 ; i < k1 ; i++)
    {
        if(x[0]==x[1]&&x[0]==x[2])
            break;
        fout<<q->name<<" "<<speciala(x[i])<<" ";
        q=q->urm;
    }
   fout <<endl;
}


void back(int k1)
{

    for(int i = 0; i <k ; i++)
    {
        x[k1-1]=i;
        if(k1 == n)
            afis(k1);
        else
            back(k1+1);
    }
}
void inserare(int wanted)
{
    nod *c,*q;
    c=new nod;
    f.getline(c->name,20);
    f.getline(c->nameproj,20);
    c->nr=3;

    if(wanted==1)
    {
        c->urm=p;
        p=c;
    }
    else
    {
        q=p;
        while(q->urm!=NULL)
            q=q->urm;
        c->urm=NULL;
        q->urm=c;
    }

}

void delete1(int case1)
{

    char wanted[20];
    f.getline(wanted,20);
    if(case1==1)
    {
      nod *q=p;
        while(q!=NULL&&strcmp(q->name,wanted)==0)
        {
            nod *to_delete=q;
            q=q->urm;
            delete to_delete;
        }
        while(q!=NULL && q->urm!=NULL)
        {
            if(strcmp(q->urm->name,wanted)==0)
            {
                nod *to_delete=q->urm;
                q->urm=to_delete->urm;

              if(to_delete->urm)
                    to_delete->urm->prev=q;

            delete to_delete;
            }
            q=q->urm;
        }
    }
    else
        if(case1==2)
        {
            nod *q=p;
        while(q!=NULL)
        {

            if(strcmp(q->nameproj,wanted)==0)
            {
                char s[20];
                f.getline(s,20);
                strcpy(q->nameproj,s);
            }
            q=q->urm;
        }
        }
        else
            cout<<"ERROR";

}

int main()
{
    fin>>n>>k;
    citire();
    afisare();
    fout<<endl;

    for(int i=0;i<k;i++)
    {
        fin.getline(y[i].project,20);
    }
    fout<<"here: ";
     for(int i=0;i<k;i++)
    {
        fout<<i<<":"<<y[i].project<<" ";
    }
    fout<<endl;
    back(1);
    fout<<endl;
    inserare(1);
    afisare();
    delete1(1);
    afisare();

    return 0;

    fin.close();
    fout.close();
}
