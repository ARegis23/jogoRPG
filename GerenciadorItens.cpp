#include "GerenciadorItens.h"
#include <iostream>
#include <algorithm>
using namespace std;

void GerenciadorItens::adicionarItem(const string& item) {
    itens.push_back(item);
}

void GerenciadorItens::listarItens() const {
    cout << "\n--- Inventario ---\n";
    if (itens.empty()) {
        cout << "Voce nao possui itens.\n";
    } else {
        for (size_t i = 0; i < itens.size(); ++i) {
            cout << i + 1 << ". " << itens[i] << "\n";
        }
    }
}

void GerenciadorItens::usarItem(const string& item, Personagem& personagem) {
    if (item == "Pocao de Vida") {
        personagem.recuperarVida(30);
        cout << "Voce usou uma Pocao de Vida e recuperou 30 de HP!\n";
    } else if (item == "Espada de Fogo") {
        personagem.aumentarAtaque(10);
        cout << "Voce equipou a Espada de Fogo! (+10 ATK)\n";
    } else if (item == "Armadura de Aco") {
        personagem.aumentarDefesa(10);
        cout << "Voce equipou a Armadura de Aco! (+10 DEF)\n";
    } else {
        cout << "Item desconhecido.\n";
        return;
    }
}

const std::vector<std::string>& GerenciadorItens::getItens() const {
    return itens;
}

void GerenciadorItens::removerItem(const std::string& item) {
    auto it = std::find(itens.begin(), itens.end(), item);
    if (it != itens.end()) {
        itens.erase(it);
    }
}
