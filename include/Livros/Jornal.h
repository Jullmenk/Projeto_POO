#ifndef JORNAL_H
#define JORNAL_H

#include "Geral.h"


class Jornal : public Geral
{
    private:
    string issn; // Identificar unico para Jornal
    string Seccao; //Política, esportes, economia, cultura, etc.
    
    public:
        Jornal(string categoria,string titulo, string autor, int ano, bool disponivel,string issn, string Seccao);
        virtual ~Jornal();
        void descricao() const override;
        string getCodigo() const override; 
        bool escreverFicheiro(ofstream& file) override;
        void AlterarInformacaoDoLivro() override;
};

#endif // Jornal_H
