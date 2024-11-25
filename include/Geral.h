#ifndef GERAL_H
#define GERAL_H
#include <iostream>
#include <string>
using namespace std;

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
    virtual ~Geral() = default;

    // A função descricao é virtual, permitindo que seja sobrescrita nas subclasses
    virtual void descricao() const = 0; 
    // int getCodigo() const { return ano; }  // Usando o ano como código (ou qualquer outro campo único)
    int getCodigo() const { return ano; }  // Simula código como ano
    bool isDisponivel() const { return disponivel; } 
};

#endif // GERAL_H
