#include "Personagem.h"
#include <iostream>
using namespace std;

Personagem::Personagem(string n, int v, int a, int d)
    : nome(n), vida(v), ataque(a), defesa(d) {}

string Personagem::getNome() const { return nome; }
int Personagem::getVida() const { return vida; }
int Personagem::getAtaque() const { return ataque; }
int Personagem::getDefesa() const { return defesa; }

void Personagem::levarDano(int dano) {
    int danoReal = dano - defesa;
    if (danoReal < 0) danoReal = 0;
    vida -= danoReal;
    if (vida < 0) vida = 0;
}

bool Personagem::estaVivo() const { return vida > 0; }

void Personagem::exibirStatus() const {
    cout << "\nStatus de " << nome << ":\n";
    cout << "Vida: " << vida << "\n";
    cout << "Ataque: " << ataque << "\n";
    cout << "Defesa: " << defesa << "\n";
}

void Personagem::recuperarVida(int valor) {
    vida += valor;
    cout << nome << " recuperou " << valor << " de vida.\n";
}

void Personagem::aumentarAtaque(int valor) {
    ataque += valor;
    cout << nome << " aumentou o ataque em " << valor << ".\n";
}

void Personagem::aumentarDefesa(int valor) {
    defesa += valor;
    cout << nome << " aumentou a defesa em " << valor << ".\n";
}

void Personagem::usarItem(const std::string& item) {
    if (item == "pocao") {
        vida += 20;
        if (vida > 100) vida = 100;
        std::cout << nome << " usou uma pocao e recuperou vida!" << std::endl;
    }
}

