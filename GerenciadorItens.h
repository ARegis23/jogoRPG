#ifndef GERENCIADOR_ITENS_H
#define GERENCIADOR_ITENS_H

#include <string>
#include <map>
#include <vector>
#include "Personagem.h"

class GerenciadorItens {
private:
    std::map<std::string, int> inventario;

public:
    void adicionarItem(const std::string& nome, int quantidade = 1);
    void usarItem(const std::string& nome, Personagem& personagem);
    void listarItens() const;
};

#endif
