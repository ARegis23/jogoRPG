#ifndef ELFO_H
#define ELFO_H

#include "Personagem.h"

class Elfo : public Personagem {
public:
    Elfo(const std::string& nome);
    void atacar(Personagem& alvo) override;
};

#endif
