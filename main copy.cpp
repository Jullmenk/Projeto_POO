#include <iostream>

using namespace std;

#include "include/Geral.h"
#include "include/LivroCientifico.h"
#include "include/Biblioteca.h"
#include "include/LivroFiccao.h"
#include "include/menu.h"


int main() {
    Biblioteca biblioteca;

    // Criando livros (exemplo com uma subclasse LivroCientifico)
    Geral* livro1 = new LivroCientifico("A Origem das Especies", "Charles Darwin", 1859, true, 123, "Biologia");
    Geral* livro2 = new LivroCientifico("O Universo em uma Casca de Noz", "Stephen Hawking", 2001, true, 456, "Fisica");
    Geral* livro3 = new LivroCientifico("Principios de Quimica", "Linus Pauling", 1947, false, 789, "Quimica");
    Geral* livro4 = new LivroCientifico("Fly Squad", "Osh Shit", 1947, false, 339, "Quimica");

    // Adicionando livros a categorias
    biblioteca.adicionarLivro("Biologia", livro1);
    biblioteca.adicionarLivro("Fisica", livro2);
    biblioteca.adicionarLivro("Quimica", livro3);
    biblioteca.adicionarLivro("Quimica", livro4);

    // Listando todos os livros
    cout << "\n--- Todos os Livros ---\n";
    biblioteca.listarLivros();

    // Listando livros disponíveis
    cout << "\n--- Livros Disponiveis ---\n";
    biblioteca.listarLivrosDisponiveis();

    // Buscando um livro pelo código (ano como exemplo)
    int codigo = 1859;
    Geral* livroEncontrado = biblioteca.buscarLivro(codigo);
    if (livroEncontrado) {
        cout << "\n--- Livro Encontrado ---\n";
        livroEncontrado->descricao();
    } else {
        cout << "\nLivro com codigo " << codigo << " nao encontrado.\n";
    }

    // Relatório de uma categoria
    cout << "\n--- Relatorio: Categoria Fisica ---\n";
    biblioteca.RelatorioCategoria("Fisica");

    // Removendo um livro
    cout << "\n--- Removendo Livro: Quimica (1947) ---\n";
    biblioteca.removerLivro("Quimica", 1947);

    // Listando todos os livros novamente após a remoção
    cout << "\n--- Todos os Livros (Apos Remocao) ---\n";
    biblioteca.listarLivros();

    return 0;
}
