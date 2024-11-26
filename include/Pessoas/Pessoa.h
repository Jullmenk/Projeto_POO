#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <iostream>
using namespace std;



class Pessoa
{
    protected:
    string nome;
    string id;
    int livrosMaximos; // Número máximo de livros que pode requisitar
    double descontoMulta; // Desconto em multas (0.0 a 1.0)

    public:
        Pessoa(string nome, string id, int livrosMaximos, double descontoMulta);
        virtual ~Pessoa();
        virtual void descricao() const ;
 
        string getNome() const;
        string getId() const;
        int getLivrosMaximos() const;
        double getDescontoMulta() const;
    private:
};

#endif // PESSOA_H
