#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <list>
#include <map>
#include "Pessoas/Pessoa.h"
#include "Livros/Geral.h"
#include "Utils/Emprestimos.h"
using namespace std;
#include <cstdlib>

class Biblioteca {
private:
    // Armazena os livros organizados por categoria
    map<string, list<Geral*>> livrosPorCategoria;
    map<string, list<Emprestimo>> emprestimosPorCategoria;
    map<string, list<Emprestimo>> reservasPorCategoria;
    map<string, list<Pessoa*>> leitores;

public:
    Biblioteca() = default;
    virtual ~Biblioteca();
    //File
    bool SaveToFile(const string& nf);
    bool LoadFile(const string& nf);

    //Livro
    map<string, list<Geral*>>& getLivrosPorCategoria();
    map<string, list<Pessoa*>>& getleitores();

    void listarLivrosDisponiveis() const;
    void adicionarLivro(const string& categoria, Geral* livro);
    Geral* buscarLivro(string codigo);
    void removerLivro(const string& categoria, string codigo);
    bool listarLivrosComPaginacao(bool forSearch,string categoria);

    //Leitor
    void adicionarLeitor(string categoria,Pessoa* leitor);
    bool listarLeitores(bool forSearch,string categoria);
    Pessoa* buscarLeitor(string NIF) const;

    //Emprestimo
    void registrarEmprestimo(Pessoa* leitor, Geral* livro, time_t dataEmprestimo);
    void RelatorioEmprestimosTipoDeLivro(string cat);
    void RelatorioMultasPendentes();
    void Prorrogacao_Emprestimos();
    void Sistema_Notificacoes_Atraso();
    void registrarReserva(Pessoa* leitor, Geral* livro);
    void transformarReservaEmEmprestimo(Pessoa* leitor, Geral* livro); 



};

#endif // BIBLIOTECA_H
