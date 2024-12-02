#ifndef EMPRESTIMOS_H
#define EMPRESTIMOS_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Emprestimo {

private:
    string NIFLeitor;     // ID do leitor que realizou o empréstimo
    string nomeLeitor;   // Nome do leitor
    string categoriaLivro;
    string tituloLivro;
    time_t dataEmprestimo;
    time_t dataDevolucao;
    bool recebido;

public:
    Emprestimo(string NIFLeitor, string nomeLeitor, string categoriaLivro, string tituloLivro, time_t dataEmprestimo, time_t dataDevolucao,bool recebido);
    virtual ~Emprestimo(); 
    void Descricao() const;
    string getNif() const;
};

#endif
