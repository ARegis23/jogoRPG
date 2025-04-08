#include "Mago.h"

Mago::Mago(const std::string& nome)
    : Personagem(nome, 80, 40) // menos vida, mais ataque
{}

void Mago::atacar(Personagem& alvo) {
    std::cout << nome << " lança uma bola de fogo em " << alvo.getNome() << ", causando " << ataque << " de dano mágico!\n";
    alvo.receberDano(ataque);
}
