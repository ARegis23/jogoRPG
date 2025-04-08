#ifndef CLERIGO_H
#define CLERIGO_H

#include "Personagem.h"

class Clerigo : public Personagem {
public:
    Clerigo(const std::string& nome);
    void atacar(Personagem& alvo) override;
};

#endif
