#include "../../include/Livros/Geral.h"

Geral::Geral(string categoria,string titulo,  string autor, int ano, bool disponivel):categoria(categoria), titulo(titulo), autor(autor), ano(ano), disponivel(disponivel) {}

Geral::~Geral(){

};

void Geral::descricao() const {
    cout
        << "Título: " << titulo
        << " | Autor: " << autor
        << " | Ano: " << ano
        << " | Disponibilidade: " << (disponivel ? "Disponível" : "Indisponível");
}

string Geral::getCategoria() { return categoria; }
string Geral::getTitulo() { return titulo; }
bool Geral::isDisponivel() { return disponivel; } 

void Geral::setDisponivel(){
    disponivel=true;
};
void Geral::setInDisponivel(){
    disponivel=false;
}

bool Geral::escreverFicheiro(ofstream& file){
    if (!file.is_open()) {
        return false;
    }
    file<< categoria << " ; "
    << titulo << " ; "
    << autor << " ; "
    << ano << " ; "
    << disponivel << " ; ";
} 