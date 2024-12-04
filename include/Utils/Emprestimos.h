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
    string categoriaLeitor;
    string tituloLivro;
    string idLivro;
    time_t dataEmprestimo;
    time_t dataDevolucao;

public:
    Emprestimo(string NIFLeitor, string nomeLeitor, string categoriaLivro, string tituloLivro, time_t dataEmprestimo, time_t dataDevolucao,string idLivro,string categoriaLeitor);
    virtual ~Emprestimo(); 
    void Descricao() const;
    string getNif() const;
    string getIDLivro() const;
    string getCategoriaLeitor()const;
    string getCategoriaLivro() const;
    time_t getDataDevolucao() const;
        bool operator==(const Emprestimo& other) const {
        return (this->getNif() == other.getNif() &&
                this->getIDLivro() == other.getIDLivro() &&
                this->getCategoriaLivro() == other.getCategoriaLivro());
    }

};

#endif
