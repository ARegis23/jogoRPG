#include <iostream>
#include <memory>
#include <vector>
#include "Mago.h"
#include "Guerreiro.h"
#include "Elfo.h"
#include "Clerigo.h"
#include "GerenciadorItens.h"

using namespace std;

void mostrarMenuPersonagens() {
    cout << "Escolha seu personagem:\n";
    cout << "1. Mago\n";
    cout << "2. Guerreiro\n";
    cout << "3. Elfo\n";
    cout << "4. Clerigo\n";
    cout << "Opcao: ";
}

void menuBatalha() {
    cout << "\n=== Menu de Batalha ===\n";
    cout << "1. atacar\n";
    cout << "2. Usar item\n";
    cout << "3. Fugir\n";
    cout << "Escolha: ";
}

int main() {
    string nome;
    int escolha;

    cout << "Digite o nome do seu personagem: ";
    getline(cin, nome);

    unique_ptr<Personagem> jogador;

    mostrarMenuPersonagens();
    cin >> escolha;
    cin.ignore();

    switch (escolha) {
        case 1: jogador = make_unique<Mago>(nome); break;
        case 2: jogador = make_unique<Guerreiro>(nome); break;
        case 3: jogador = make_unique<Elfo>(nome); break;
        case 4: jogador = make_unique<Clerigo>(nome); break;
        default:
            cout << "Opcao invalida. Encerrando o jogo.\n";
            return 1;
    }

    GerenciadorItens inventario;
    inventario.adicionarItem("Pocao de Vida");
    inventario.adicionarItem("Espada de Fogo");

    unique_ptr<Personagem> inimigo = make_unique<Guerreiro>("Inimigo Generico");

    cout << "\nBatalha comecou contra " << inimigo->getNome() << "!\n";

    while (jogador->estaVivo() && inimigo->estaVivo()) {
        menuBatalha();
        int acao;
        cin >> acao;

        if (acao == 1) {
            jogador->atacar(*inimigo);
        } else if (acao == 2) {
            const auto& listaItens = inventario.getItens();
            if (!listaItens.empty()) {
                cout << "Itens disponiveis:\n";
                for (size_t i = 0; i < listaItens.size(); ++i) {
                    cout << i + 1 << ". " << listaItens[i] << "\n";
                }
                cout << "Escolha o numero do item: ";
                int itemEscolhido;
                cin >> itemEscolhido;
                if (itemEscolhido >= 1 && itemEscolhido <= listaItens.size()) {
                    string item = listaItens[itemEscolhido - 1];
                    inventario.usarItem(item, *jogador);
                    inventario.removerItem(item);
                } else {
                    cout << "Item invalido.\n";
                }
            } else {
                cout << "Inventario vazio.\n";
            }
        } else if (acao == 3) {
            cout << "Voce fugiu da batalha.\n";
            break;
        } else {
            cout << "Acao invalida.\n";
        }

        if (inimigo->estaVivo()) {
            inimigo->atacar(*jogador);
        }
    }

    if (!jogador->estaVivo()) {
        cout << "Voce foi derrotado...\n";
    } else if (!inimigo->estaVivo()) {
        cout << "Voce venceu a batalha!\n";
    }

    return 0;
}
