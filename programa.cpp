#include <iostream>
#include <cstdlib>
#define TIPO int
using namespace std;
struct nodo
{
    nodo *esquerda;
    TIPO informacao;
    nodo *direita;
    nodo ( TIPO info ) :
        informacao (info),
        esquerda (0),
        direita (0) {}
};
nodo *P;
struct nodo *insere ( nodo *tree, TIPO informacao )
{
    if ( tree == NULL )
        tree = new nodo (informacao);
    else if ( informacao < tree->informacao )
        tree->esquerda = insere(tree->esquerda, informacao);
    else if ( informacao > tree->informacao )
        tree->direita = insere(tree->direita, informacao);
    return tree;
}
struct nodo *GetMax(nodo *tree)
{
    if (tree->direita == NULL)
    {
        P=tree;
        tree = tree->esquerda;
    }
    else
    {
        tree->direita = GetMax(tree->direita);
    }
    return tree;
}
struct nodo *retira(nodo *tree, TIPO informacao)   // Preencha
{
    if (tree==NULL)
    {
        cout << "Elemento nao encontrado" << endl;
    }
    else
    {
        if (informacao==tree->informacao)
        {
            if (tree->esquerda==NULL)
            {
                tree = tree->direita;
            }
            else
            {
                if (tree->direita==NULL)
                {
                    tree = tree->esquerda;
                }
                else
                {
                    tree->esquerda = GetMax(tree->esquerda);
                    tree->informacao = P->informacao;
                }
                free(P);
            }
        }
        else
        {
            if ( informacao < tree->informacao)
            {
                tree->esquerda = retira(tree->esquerda, informacao);
            }
            else
            {
                tree->direita = retira(tree->direita, informacao);
            }
        }
    }
    return tree;
}

//////////////////////INFIXA
void infixa ( nodo *tree )
{
    if ( tree != NULL )
    {
        infixa(tree->esquerda ); ///perc sub-arvore esquerda
        cout << tree->informacao << " ";
        infixa(tree->direita); ///perc rec. sub-arvore direita
    }
}

/////////////////////POSFIXA
void posfixa ( nodo *tree )
{
    if ( tree != NULL)
    {
        posfixa(tree -> esquerda);
        posfixa(tree -> direita);
        cout << tree -> informacao << " ";
    }

}
////////////////////PREFIXA
void prefixa ( nodo *tree )
{
    if ( tree != NULL )
    {
        cout << tree -> informacao << " ";
        prefixa(tree -> esquerda);
        prefixa(tree -> direita);
    }
}


// ///////////////////////BUSCA
    int i = 0;
    bool existe = false;
    int caminho[100];
struct nodo *busca(nodo *tree, TIPO informacao)
{

    if(tree == NULL)
    {
        cout << informacao << " nao existe" << endl;
        return NULL;

    }
    else
    {
        existe = false;
        caminho[i]= tree->informacao;
        i++;
        if(tree->informacao > informacao)
        {
            busca(tree->esquerda, informacao);
        }
        else if(tree->informacao < informacao)
        {
            busca(tree->direita, informacao);

        }
        else
        {
            cout << informacao << " existe. Caminho: ";
            existe=true;

            if(existe==true)
            {
                for(int i = 0; i < 100; i++)
                {
                    cout << caminho[i] << " ";
                    if (caminho[i] == tree ->informacao){
                        cout << endl;
                        break;
                    }

                }
                cout << endl;
            }

        }
    }
}
int main()   //freopen("arvore.in","r",stdin);
{
    nodo *raiz = 0;
    TIPO valor;
    int elementos;
    cout << "Para comecar, insira quantas valores serao inseridos na arvore:" << endl;
    //cin >> elementos;
    elementos = 7;
    while (elementos--)
    {
        cin >> valor;
        raiz = insere ( raiz, valor );
    }
    int nOpcao;
    bool tru = true;

    while (tru)
    {
        cout << "Digite a opcao desejada na arvore:" << endl;
        cout << "1 - Insercao" << endl;
        cout << "2 - Busca" << endl;
        cout << "3 - Retirada" << endl;
        cout << "4 - Listagem Prefixa" << endl;
        cout << "5 - Listagem Infixa" << endl;
        cout << "6 - Listagem Posfixa" << endl;
        cout << "Outro Numero - Sair" << endl;

        cin >> nOpcao;

        switch (nOpcao)
        {
        case 1:
            cout << "Digite o valor que deseja inserir:" << endl;
            TIPO nElementoAInserir;
            cin >> nElementoAInserir;
            raiz = insere ( raiz, nElementoAInserir );
            cout << endl;
            break;
        case 2:
            cout << "Digite o elemento que deseja buscar:" << endl;
            TIPO nElementoABuscar;
            cin >> nElementoABuscar;

            busca( raiz, nElementoABuscar );
            cout << endl;
            break;
        case 3:
            cout << "Digite o elemento que deseja retirar da arvore: " << endl;
            TIPO nElementoARetirar;
            cin >> nElementoARetirar;
            raiz = retira( raiz, nElementoARetirar );
            break;
        case 4:
            prefixa(raiz);
            cout << endl;
            break;
        case 5:
            infixa(raiz);
            cout << endl;
            break;
        case 6:
            posfixa(raiz);
            cout << endl;
            break;
        default:
            tru = false;
            break;
        }
    }

   // infixa (raiz);
   // cout << endl;
    return 0;
}
