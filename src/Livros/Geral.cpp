#include "../../include/Livros/Geral.h"

Geral::Geral(string titulo,  string autor, int ano, bool disponivel): titulo(titulo), autor(autor), ano(ano), disponivel(disponivel) {}

Geral::~Geral(){

};

void Geral::descricao() const {
    cout << "Titulo: " << titulo
         << " | Autor: " << autor
         << " | Ano: " << ano
         << " | Disponibilidade: " << (disponivel ? "Disponivel" : "Indisponivel");
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