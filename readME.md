# RPG de Terminal - Projeto em C++

Este é um projeto de RPG simples feito em C++ com foco em **Programação Orientada a Objetos (POO)**. O jogo é executado no terminal e envolve a escolha de uma classe de personagem, batalhas contra inimigos e o uso de itens do inventário.

---

## 🎯 Objetivos do Projeto

- Praticar os pilares da POO: herança, encapsulamento e polimorfismo.
- Utilizar arquivos `.h` e `.cpp` para modularizar o código.
- Simular um combate com inventário e ações básicas em C++.

---

## 📦 Estrutura das Classes

### 🧬 Classe Pai

#### `Personagem` (classe base abstrata)
Define os atributos e comportamentos comuns a todos os personagens.

- **Atributos**:
  - `nome`
  - `vida`
  - `ataque`
  - `defesa`

- **Métodos**:
  - `receberDano(int dano)`
  - `estaVivo()`
  - `getNome(), getVida(), getAtaque(), getDefesa()`
  - `usarItem(string item)` — genérico
  - `virtual void exibirInfo()` — sobrescrito nas subclasses

---

### 🧙‍♂️ Subclasses de Personagem

Cada uma dessas herda de `Personagem` e implementa seu próprio construtor e comportamento ao usar itens:

#### `Mago`
- Mais frágil, mas poderoso com magias.
- Itens: `Poção de Mana`, `Poção de Cura`

#### `Guerreiro`
- Alto ataque e defesa.
- Itens: `Espada Sagrada`, `Poção de Cura`

#### `Elfo`
- Equilibrado e ágil.
- Itens: `Arco de Energia`, `Poção de Cura`

#### `Clerigo`
- Suporte, com cura mais eficaz.
- Itens: `Bênção Divina`, `Poção de Cura`

---

### 🧰 Classe de Gerenciamento

#### `GerenciadorItens`
- Responsável por controlar o inventário do jogador.

- **Atributos**:
  - `std::vector<std::string> itens`

- **Métodos**:
  - `adicionarItem(string item)`
  - `exibirItens()`
  - `bool possuiItem(string item)`
  - `void removerItem(string item)`
  - `vector<string> getItens()`

---

## 🎮 Fluxo do Jogo (main.cpp)

1. Jogador escolhe a classe e define um nome.
2. Recebe um inventário inicial com dois itens.
3. Enfrenta um inimigo aleatório (subclasse de `Personagem`).
4. Durante a batalha, pode:
   - Atacar
   - Usar item (selecionando por número na lista)
   - Fugir ou encerrar o jogo

---

## 🔧 Tecnologias Utilizadas

- Linguagem: **C++**
- Compilador: `g++`
- Terminal/Console para entrada e saída

---

## ✅ Funcionalidades Implementadas

- Herança e polimorfismo
- Inventário com seleção por índice
- Batalhas com escolha de ações
- Sistema de vida e dano
- Interface simplificada via terminal (sem acentos para compatibilidade ampla)

---

## 🗂️ Arquivos do Projeto

├── main.cpp 
├── Personagem.h / .cpp 
├── Mago.h / .cpp 
├── Guerreiro.h / .cpp 
├── Elfo.h / .cpp 
├── Clerigo.h / .cpp 
├── GerenciadorItens.h / .cpp
