#include "Elfo.h"
#include <iostream>
using namespace std;

Elfo::Elfo(string nome)
    : Personagem(nome, 80, 20, 8) {}

void Elfo::atacar(Personagem& alvo) {
    int dano = getAtaque();
    cout << getNome() << " dispara uma flecha precisa!\n";
    alvo.levarDano(dano);
}
