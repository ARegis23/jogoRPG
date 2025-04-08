#include "Guerreiro.h"
#include <iostream>
using namespace std;

Guerreiro::Guerreiro(string nome)
    : Personagem(nome, 100, 15, 10) {}

void Guerreiro::atacar(Personagem& alvo) {
    int dano = getAtaque();
    cout << getNome() << " desfere um golpe com sua espada!\n";
    alvo.levarDano(dano);
}
