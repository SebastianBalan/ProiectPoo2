#include <iostream>

using namespace std;

class Vector
{

private:
    int *arr;
    int dim;


public:

    ///constructor parametrizat de initializare
    Vector(int d)
    {
        dim=d;
        arr=new int[dim];
    }

    ///constructor parametrizat de copiere
    Vector(Vector &v)
    {
        dim=v.dim;
        arr=new int[dim];
        for(int i=0; i<dim; i++)
            arr[i]=v.arr[i];
    }

    ///destructor
    ~Vector()
    {
        delete [] arr;
    }

    friend istream &operator >>(istream &input,Vector &v)
    {
        for(int i=0; i<v.dim; i++)
        {
            cout<<"Element ";
            input >> v.arr[i];
        }
        return input;
    }

    friend ostream &operator <<(ostream &output,Vector &v)
    {
        output <<"Numarul este ";
        for(int i=0; i<v.dim; i++)
        {
            output<<v.arr[i];
        }
        return output;
    }


    /*void afisare()
    {
        for(int i=0;i<dim;i++)
            cout<<arr[i]<<" ";
    }*/


};

class NrNaturalMare
{

private:
    int *arr;
    int dim;


public:

    ///constructor parametrizat de initializare
    NrNaturalMare(int d)
    {
        dim=d;
        arr=new int[dim];
    }

    ///constructor parametrizat de copiere
    NrNaturalMare(NrNaturalMare &v)
    {
        dim=v.dim;
        arr=new int[dim];
        for(int i=0; i<dim; i++)
            arr[i]=v.arr[i];
    }

    NrNaturalMare() {}

    ///destructor
    ~NrNaturalMare()
    {
        delete [] arr;
    }

    friend istream &operator >>(istream &input,NrNaturalMare &v)
    {
        for(int i=0; i<v.dim; i++)
        {
            cout<<"Element ";
            input >> v.arr[i];
        }
        return input;
    }

    friend ostream &operator <<(ostream &output,NrNaturalMare &v)
    {
        output <<"Numarul este ";
        for(int i=0; i<v.dim; i++)
        {
            output<<v.arr[i];
        }
        return output;
    }

};

class NumarFibonacciMare: public NrNaturalMare
{

private:
    int *arr;
    int dim;


public:

    ///constructor parametrizat de initializare
    NumarFibonacciMare(int d):NrNaturalMare(d)
    {
        dim=d;
        arr=new int[dim];
    }
    NumarFibonacciMare():NrNaturalMare() {}

    ///constructor parametrizat de copiere
    NumarFibonacciMare(NumarFibonacciMare &v):NrNaturalMare(v)
    {
        dim=v.dim;
        arr=new int[dim];
        for(int i=0; i<dim; i++)
            arr[i]=v.arr[i];
    }

    ///destructor
    ~NumarFibonacciMare()
    {
        delete [] arr;
    }

    friend istream &operator >>(istream &input,NumarFibonacciMare &v)
    {
        for(int i=0; i<v.dim; i++)
        {
            cout<<"Element ";
            input >> v.arr[i];
        }
        return input;
    }

    friend ostream &operator <<(ostream &output,NumarFibonacciMare &v)
    {
        output <<"Numarul este ";
        for(int i=0; i<v.dim; i++)
        {
            output<<v.arr[i];
        }
        output<<endl;
        return output;
    }


    bool verifFibonacci(int n,NumarFibonacciMare &nr)
    {
        ///de refacut
        NumarFibonacciMare x,y,z;
        int nrCifre=1;
        x.dim=y.dim=z.dim=n+1;
        x.arr=y.arr=z.arr=new int[n+1];

        ///o sa compar ultimul element din z cu ultimul element din numarul pe care vreau sa il verific
        ///am alocat un element in plus in caz ca se trece peste unitate la finalul codului(la inceputul vectorului)


        x.arr[x.dim-nrCifre]=0;printf("x=%d\n",x.arr[x.dim-nrCifre]);
        y.arr[x.dim-nrCifre]=1;printf("y=%d\n",y.arr[x.dim-nrCifre]);
        z.arr[x.dim-nrCifre]=0;printf("z=%d\n",z.arr[x.dim-nrCifre]);
        if(n==1 && nr.arr[0]==0)
            return true;
        else
        {x.arr[x.dim-nrCifre]=0;printf("x=%d\n",x.arr[x.dim-nrCifre]);
        y.arr[x.dim-nrCifre]=1;printf("y=%d\n",y.arr[x.dim-nrCifre]);
        z.arr[x.dim-nrCifre]=0;printf("z=%d\n",z.arr[x.dim-nrCifre]);
            while(n>nrCifre)
            {
                while(nr.arr[n-nrCifre]>z.arr[x.dim-nrCifre])
                {
                    z.arr[x.dim-nrCifre]=x.arr[x.dim-nrCifre]+y.arr[x.dim-nrCifre];
                    printf("y=%d\n",y.arr[x.dim-nrCifre]);///are val 0 :(
                    x.arr[x.dim-nrCifre]=y.arr[x.dim-nrCifre];
                    y.arr[x.dim-nrCifre]=z.arr[x.dim-nrCifre];
                }
                nrCifre++;
                printf("%d",z.arr[x.dim-nrCifre]);
            }
        }

return false;
    }


};


int main()
{
    int n;
    printf("Dati numarul de elemente ale numarului ");
    scanf("%d",&n);
    ///NrNaturalMare nr(n);
    NumarFibonacciMare nr(n);
    cin>>nr;
    cout<<nr;
    if(nr.verifFibonacci(n,nr)==1)
        printf("Bomba\n");
    else
        printf("Aiurea\n");
    return 0;
}
