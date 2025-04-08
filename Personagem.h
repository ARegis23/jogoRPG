#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>

class Personagem {
private:
    std::string nome;
    int vida;
    int ataque;
    int defesa;

public:
    Personagem(std::string nome, int vida, int ataque, int defesa);

    std::string getNome() const;
    int getVida() const;
    int getAtaque() const;
    int getDefesa() const;
    void levarDano(int dano);
    bool estaVivo() const;
    void exibirStatus() const;
    void recuperarVida(int valor);
    void aumentarAtaque(int valor);
    void aumentarDefesa(int valor);
    virtual void usarItem(const std::string& item);
    virtual void atacar(Personagem& alvo) = 0;

};


#endif
