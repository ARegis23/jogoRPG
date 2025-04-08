#ifndef MAGO_H
#define MAGO_H

#include "Personagem.h"

class Mago : public Personagem {
public:
    Mago(const std::string& nome);
    void atacar(Personagem& alvo) override;
};

#endif
