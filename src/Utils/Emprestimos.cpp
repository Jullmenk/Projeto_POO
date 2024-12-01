#include "../../include/Utils/Emprestimos.h"
#include <cstring> 

Emprestimo::Emprestimo(string NIFLeitor, string nomeLeitor, string categoriaLivro, 
                string tituloLivro, time_t dataEmprestimo, time_t dataDevolucao,bool recebido):NIFLeitor(NIFLeitor), nomeLeitor(nomeLeitor), categoriaLivro(categoriaLivro),
            tituloLivro(tituloLivro), dataEmprestimo(dataEmprestimo), dataDevolucao(dataDevolucao), recebido(recebido) {}

Emprestimo::~Emprestimo(){

}; 

void Emprestimo::Descricao() const {
    // Removendo a nova linha gerada por ctime() ao imprimir a data
    char* dataEmprestimoStr = ctime(&dataEmprestimo);
    dataEmprestimoStr[strlen(dataEmprestimoStr) - 1] = '\0';

    char* dataDevolucaoStr = ctime(&dataDevolucao);
    dataDevolucaoStr[strlen(dataDevolucaoStr) - 1] = '\0'; 

    cout << "NIF: " << NIFLeitor
         << " | Nome do leitor: " << nomeLeitor
         << " | Categoria do leitor: " << categoriaLivro
         << " | Categoria de Livro: " << categoriaLivro
         << " | Titulo: " << tituloLivro
         << " | Data de Emprestimo: " << dataEmprestimoStr
         << " | Data de Devolucao: " << dataDevolucaoStr << endl;
}

string Emprestimo::getNif() const{
    return NIFLeitor;
}