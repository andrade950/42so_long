# so_long

[Read in English](README.md)

Este projeto consiste em um pequeno jogo 2D desenvolvido utilizando a biblioteca **MiniLibX**.

- **Objetivo**: Criar um jogo 2D onde o jogador deve coletar itens e alcançar a saída enquanto navega por um mapa.
- **Mecânica do Jogo**:
  - O jogador precisa coletar todos os colecionáveis antes de alcançar a saída.
  - O jogo exibe a contagem de movimentos.
  - A movimentação ocorre por meio das teclas **W, A, S, D** ou setas do teclado.
  - O jogo encerra corretamente ao pressionar **ESC** ou ao fechar a janela.
- **Versão Com Bônus**:
  - Inimigos podem derrotar o jogador.
  - Animações para os personagens e itens.
  - Contador de movimentos exibido diretamente na tela do jogo.

- **Demonstração**:
  - **Versão Sem Bônus**:
    ![Image](https://github.com/user-attachments/assets/2400dd41-7305-4377-a52f-55f22344e514)
  - **Versão Com Bônus**:
    ![Image](https://github.com/user-attachments/assets/5922663e-7207-448f-8b00-86008818a07c)

- **Elementos Gráficos**:
  - Todas as imagens utilizadas no jogo:

<div align="center">

  | Jogador | Inimigo | Coletável | Saída | Explosão | Parede | Chão |
  |---------|---------|-----------|-------|----------|--------|------|
  | ![Image](https://github.com/user-attachments/assets/337a5a60-af49-4a24-8bf2-7c9722c56791) | ![Image](https://github.com/user-attachments/assets/4b118944-a70c-4e5a-90f4-62b12fbc772a) | ![Image](https://github.com/user-attachments/assets/88f1dfe9-4676-4622-b52b-f127a3eecb46) | ![Image](https://github.com/user-attachments/assets/a61be625-d8ad-4dff-9f01-f454aa648dfa) | ![Image](https://github.com/user-attachments/assets/684743c0-6ce3-4954-a14e-0d28add3db4a) | ![Image](https://github.com/user-attachments/assets/eba7d8e0-17ff-458b-9bfb-64d2ed364e99) | ![Image](https://github.com/user-attachments/assets/4ec4d4e8-ea92-4201-b541-005adfc996be) |

</div>

- **Instalação e Compilação**:

  - **Instalar a MiniLibX**:
    ```bash
    # Clonar o repositório da MiniLibX na pasta libs
    git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux

    # Aceder à pasta da MiniLibX
    cd 42so_long/libs/minilibx-linux


    ```
  - **Compilar o Jogo**:
    ```bash
    # Navegar para a pasta do projeto
    cd 42so_long

    # Compilar o jogo base
    make

    # Executar o jogo com um mapa
    ./so_long maps/mapa_exemplo.ber

     # Compilar o jogo com bonus
    make bonus

    # Executar o jogo com um mapa
    ./so_long_bonus maps_bonus/mapa_exemplo.ber
    ```
---
