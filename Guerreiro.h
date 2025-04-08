#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "Personagem.h"

class Guerreiro : public Personagem {
public:
    Guerreiro(const std::string& nome);
    void atacar(Personagem& alvo) override;
};

#endif
