#ifndef EMPRESTIMOS_H
#define EMPRESTIMOS_H

#include <string>
#include <iostream>
#include <ctime>
#include <fstream>



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
    // Métodos de acesso (marcados como const)
    string getNifEmprestimo() const;
    string getIDLivroEmprestimo() const;
    string getCategoriaLeitorEmprestimo() const;
    string getCategoriaLivroEmprestimo() const;
    time_t getDataDevolucaoEmprestimo() const;

    // Métodos adicionais
    void Descricao() const;
    bool escreverFicheiro(ofstream& file) const; // Tornado const

    // Operadores
    bool operator==(const Emprestimo& other) const;
};

#endif
