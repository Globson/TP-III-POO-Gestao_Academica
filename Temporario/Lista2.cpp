#include <iostream>
using namespace std;
// classe No
class No
{
private:
	int v[3][3];
	No* prox;
public:
	No(int v[][3]) // construtor
	{
    for(int i =0;i<3;i++)
      for(int j=0;j<3;j++){
        this->v[i][j] = v[i][j];
      }

		this->prox = NULL;
	}
  int obterValor(int i,int j){
    return v[i][j];
  }

	No* obterProx() // obtém o próximo No
	{
		return prox;
	}

	void setProx(No* p) // seta o próximo No
	{
		prox = p;
	}
};

// classe Lista
class Lista
{
private:
	No* cabeca; // primeiro elemento
	No* cauda; // último elemento

public:
	Lista()
	{
		// se não passar elemento, então cabeca e cauda são NULL
		cabeca = NULL;
		cauda = NULL;
	}

	Lista(int v[][3])
	{
		// se passar elemento, então cria novo No
		cabeca = new No(v);
		cauda = cabeca;
	}

	virtual ~Lista() // destrutor
	{
		delete cabeca;
	}

	void mostrar() // mostra todos os elementos da lista
	{
		cout << "\nImprimindo todos os elementos...\n";
		No* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(c) // percorre a lista
			{
        for(int i =0;i<3;i++){
          cout<<endl;
          for(int j=0;j<3;j++){
            cout << c->obterValor(i,j) << endl;
          }}
        cout<<endl<<endl;
				c = c->obterProx();
			}
			cout << endl;
		}
	}

	bool vazia() // verifica se a lista está vazia
	{
		return (cabeca == NULL);
	}

	// insere no início (semelhante a push_front da list)
	void inserir_inicio(int v[][3])
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			novo_no->setProx(cabeca);
			cabeca = novo_no;
		}
	}

	// insere no final (semelhante a push_back da list)
	void inserir_final(int v[][3])
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			cauda->setProx(novo_no);
			cauda = novo_no;
		}
	}

	// retorna o tamanho da lista
	int tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		No* c = cabeca;
		int tam = 0;

		// percorre a lista
		do
		{
			c = c->obterProx();
			tam++;
		}
		while(c);

		return tam;
	}

	// verifica se um elemento existe na lista
	bool existe(int v[][3])
	{
		No* c = cabeca;
    int aux =0;
		while(c)
		{
      for(int i =0;i<3;i++)
        for(int j=0;j<3;j++){
			if(c->obterValor(i,j) == v[i][j]){
        aux++;
      }}
      if(aux<9){
			c = c->obterProx();}
      else{
        return true;
      }
		}
		return false;
	}

	// remove da lista, remoção do final (semelhante a pop_back da list)
	void remover()
	{
		if(!vazia())
		{
			// se houver só 1 elemento
			if(cabeca->obterProx() == NULL)
				cabeca = NULL;
			else if(cabeca->obterProx()->obterProx() == NULL) // 2 elementos
				cabeca->setProx(NULL);
			else // > 2 elementos
			{
				No* ant_ant = cabeca;
				No* ant = cabeca->obterProx();
				No* corrente = cabeca->obterProx()->obterProx();

				while(corrente)
				{
					No* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->obterProx();
				}
				delete ant_ant->obterProx(); // libera memória
				ant_ant->setProx(NULL); // seta o prox como NULL
				cauda = ant_ant; // atualiza a cauda
			}
		}
	}
};
