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
void infixa ( nodo *tree )
{
    if ( tree != NULL )
    {
        infixa(tree->esquerda ); ///perc sub-arvore esquerda
        cout << tree->informacao << " ";
        infixa(tree->direita); ///perc rec. sub-arvore direita
    }
}

void busca ( nodo *tree){
    if (tree == NULL){
        cout << "esse valor nao existe" << endl;
    }
    else
    {
        if(tree < tree->informacao){
            busca(tree->esquerda);
        }
    }
}
int main()   //freopen("arvore.in","r",stdin);
{
    nodo *raiz = 0;
    TIPO valor;
    int elementos;
    cin >> elementos;
    while (elementos--)
    {
        cin >> valor;
        raiz = insere ( raiz, valor );
    }
    int nOpcao;

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
        break;
    case 2:

    }

    infixa (raiz);
    cout << endl;
    return 0;
}
