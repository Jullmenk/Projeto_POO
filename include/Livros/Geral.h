#ifndef GERAL_H
#define GERAL_H
#include <iostream>
#include <string>
using namespace std;
#include <fstream>


class Geral
{
    protected:
    string titulo;
    string autor;
    int ano;
    bool disponivel;
    string categoria;

public:
    Geral(string titulo, string autor, int ano, bool disponivel);
    virtual ~Geral();

    virtual void descricao() const = 0; 
    virtual string getCodigo() const = 0;
    virtual bool escreverFicheiro(ofstream& file); 

    string getCategoria();
    string getTitulo();    

    bool isDisponivel();
    void setDisponivel();
    void setInDisponivel();
};

#endif // GERAL_H
