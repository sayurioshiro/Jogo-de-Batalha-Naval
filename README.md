# 🚢 Batalha Naval em C — Nível Mestre

## 👑 Habilidades Especiais e Áreas de Efeito

Este projeto representa o nível mestre do jogo Batalha Naval em C.  
Nesta etapa, foram implementadas habilidades especiais com diferentes formatos de área de efeito.

## 📌 Funcionalidades

- Tabuleiro 10x10 representado por matriz bidimensional
- Posicionamento de navio no tabuleiro
- Criação de três habilidades especiais:
  - Cone
  - Cruz
  - Octaedro (formato de losango)
- Construção dinâmica das matrizes de habilidade utilizando loops aninhados e condicionais
- Sobreposição da área de efeito no tabuleiro
- Exibição visual no console

## 🗺️ Representação no Tabuleiro

- `~` → Água  
- `N` → Navio  
- `*` → Área afetada pela habilidade  

## 💻 Como compilar e executar

```bash
gcc nivel_mestre.c -o nivel_mestre
./nivel_mestre
