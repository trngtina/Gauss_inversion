#include <iostream>
using namespace std;


const int dim = 3;

void echanger(float t[dim][dim], int ligne1, int ligne2)
{
    for (int i=0; i<dim; i = i+1)
    {
        float temp;
        temp = t[ligne1][i];
        t[ligne1][i] = t[ligne2][i];
        t[ligne2][i] = temp;
    }
}

void multiplier(float t[dim][dim], int ligne, float a)
{
    for (int i=0; i<dim; i = i+1)
    {
        t[ligne][i] = t[ligne][i]*a;
    }
}

void ajout(float t[dim][dim], int ligne1, int ligne2, float a)
{
    for (int i=0; i<dim; i = i+1)
    {
        t[ligne1][i] = t[ligne1][i] - a*t[ligne2][i];
    }
}

void afficher(float t[dim][dim])
{
    for (int i=0; i<dim; i = i+1)
    {
        for (int j=0; j<dim; j = j+1)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "La dimension de la matrice à inverser est : " << dim << endl;
    cout << "Entrez les valeurs de la matrice à inverser" << endl;
    
    float tab[dim][dim];
    float tab_id[dim][dim] = {0,0};
    
    for (int i=0; i<dim; i = i+1)
    {
        for (int j= 0; j<dim; j = j+1)
        {
            int a;
            cin >> a;
            tab[i][j] = a;
        }
        tab_id[i][i] = 1;
    }
    
    cout << "Inversons la matrice: " << endl;
    afficher(tab);
    cout << endl;
    cout << "Avec la matrice identité: " << endl;
    afficher(tab_id);
    cout << endl;
    
    int flag = 1;
    int k = 0;
    
    while ((k < dim)&&(flag ==1))
    {
        int curseur = k;
        float coeff = 0;
        
        for (int i=k; i < dim; i = i+1)
        {
            if ((coeff == 0)&&(tab[i][k]!=0))
            {
                coeff = tab[i][k];
                curseur = i;
            }
        }
        
        if (coeff ==0)
        {
            cout << "Matrice non inversible" << endl;
            flag = 0;
        }
        else
        {
            echanger(tab_id, k, curseur);
            echanger(tab, k, curseur);
            
            multiplier(tab_id, k, 1/tab[k][k]);
            multiplier(tab, k, 1/tab[k][k]);
            
            for (int j=0; j<dim; j=j+1)
            {
                if (j!=k)
                {
                    ajout(tab_id, j, k, tab[j][k]);
                    ajout(tab, j, k, tab[j][k]);
                }
            }
        }
        
        k = k+1;
    }
    
    if (flag == 1)
    {
        cout << "La matrice inverse est: " << endl;
        afficher(tab_id);
        cout << endl;
    }
}
