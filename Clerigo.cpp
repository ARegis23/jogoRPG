#include "Clerigo.h"
#include <iostream>
using namespace std;

Clerigo::Clerigo(string nome)
    : Personagem(nome, 90, 10, 12) {}

void Clerigo::atacar(Personagem& alvo) {
    int dano = getAtaque();
    cout << getNome() << " invoca luz sagrada contra o inimigo!\n";
    alvo.levarDano(dano);
}
