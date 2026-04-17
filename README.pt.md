<div align="center">

# 🎮 so_long

**Um pequeno jogo 2D desenvolvido com MiniLibX em C**

[![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Biblioteca](https://img.shields.io/badge/Gráficos-MiniLibX-orange.svg)](#instalação)
[![Norm](https://img.shields.io/badge/42-Norminette-brightgreen.svg)](#)

[Read in English](README.md)

</div>

---

## 📌 Visão Geral

`so_long` é um jogo 2D de vista de cima onde o jogador navega por um mapa de tiles, recolhe todos os itens e alcança a saída. Desenvolvido inteiramente em C utilizando a biblioteca gráfica **MiniLibX**.

---

## 🕹️ Como Jogar

- Recolhe **todos os colecionáveis** antes de a saída desbloquear
- Chega à **saída** para ganhar
- Move-te com **W A S D** ou as **setas do teclado**
- Pressiona **ESC** ou fecha a janela para sair
- O teu **contador de movimentos** é registado ao longo do jogo

### Versão base
![Jogo base](https://github.com/user-attachments/assets/2400dd41-7305-4377-a52f-55f22344e514)

### Versão bónus
![Jogo bónus](https://github.com/user-attachments/assets/5922663e-7207-448f-8b00-86008818a07c)

**Funcionalidades bónus:**
- Inimigos que podem derrotar o jogador
- Animações para personagens e itens
- Contador de movimentos renderizado diretamente no ecrã

---

## 🎨 Sprites

<div align="center">

| Jogador | Inimigo | Colecionável | Saída | Explosão | Parede | Chão |
|:-------:|:-------:|:------------:|:-----:|:--------:|:------:|:----:|
| ![](https://github.com/user-attachments/assets/337a5a60-af49-4a24-8bf2-7c9722c56791) | ![](https://github.com/user-attachments/assets/4b118944-a70c-4e5a-90f4-62b12fbc772a) | ![](https://github.com/user-attachments/assets/88f1dfe9-4676-4622-b52b-f127a3eecb46) | ![](https://github.com/user-attachments/assets/a61be625-d8ad-4dff-9f01-f454aa648dfa) | ![](https://github.com/user-attachments/assets/684743c0-6ce3-4954-a14e-0d28add3db4a) | ![](https://github.com/user-attachments/assets/eba7d8e0-17ff-458b-9bfb-64d2ed364e99) | ![](https://github.com/user-attachments/assets/4ec4d4e8-ea92-4201-b541-005adfc996be) |

</div>

---

## ⚙️ Instalação e Compilação

### 1. Instalar a MiniLibX

```bash
git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux
# Colocar dentro da pasta libs:
# 42so_long/libs/minilibx-linux
```

### 2. Compilar e Executar

```bash
cd 42so_long

# Jogo base
make
./so_long maps/mapa_exemplo.ber

# Jogo bónus
make bonus
./so_long_bonus maps_bonus/mapa_exemplo.ber
```

---

## 🧪 Tester de Mapas

Está incluído um script bash para testar automaticamente todos os mapas numa pasta.

```bash
chmod +x map_tester.sh

# Projeto base
./test_maps.sh ./so_long ./maps

# Projeto bónus
./test_maps.sh ./so_long_bonus ./maps_bonus
```

---
