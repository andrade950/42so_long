<div align="center">

# 🎮 so_long

**A small 2D game built with MiniLibX in C**

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Library](https://img.shields.io/badge/Graphics-MiniLibX-orange.svg)](#installation)
[![Norm](https://img.shields.io/badge/42-Norminette-brightgreen.svg)](#)

[Leia em Português](README.pt.md)

</div>

---

## 📌 Overview

`so_long` is a top-down 2D game where the player navigates a tile-based map, collects every item, and reaches the exit. Built entirely in C using the **MiniLibX** graphics library.

---

## 🕹️ Gameplay

- Collect **all collectibles** before the exit unlocks
- Reach the **exit** to win
- Move with **W A S D** or the **arrow keys**
- Press **ESC** or close the window to quit
- Your **move count** is tracked throughout the game

### Base version
![Base game](https://github.com/user-attachments/assets/2400dd41-7305-4377-a52f-55f22344e514)

### Bonus version
![Bonus game](https://github.com/user-attachments/assets/5922663e-7207-448f-8b00-86008818a07c)

**Bonus features:**
- Enemies that can defeat the player
- Character and item animations
- Move counter rendered directly on screen

---

## 🎨 Sprites

<div align="center">

| Player | Enemy | Collectible | Exit | Explosion | Wall | Floor |
|:------:|:-----:|:-----------:|:----:|:---------:|:----:|:-----:|
| ![](https://github.com/user-attachments/assets/337a5a60-af49-4a24-8bf2-7c9722c56791) | ![](https://github.com/user-attachments/assets/4b118944-a70c-4e5a-90f4-62b12fbc772a) | ![](https://github.com/user-attachments/assets/88f1dfe9-4676-4622-b52b-f127a3eecb46) | ![](https://github.com/user-attachments/assets/a61be625-d8ad-4dff-9f01-f454aa648dfa) | ![](https://github.com/user-attachments/assets/684743c0-6ce3-4954-a14e-0d28add3db4a) | ![](https://github.com/user-attachments/assets/eba7d8e0-17ff-458b-9bfb-64d2ed364e99) | ![](https://github.com/user-attachments/assets/4ec4d4e8-ea92-4201-b541-005adfc996be) |

</div>

---

## ⚙️ Installation & Compilation

### 1. Install MiniLibX

```bash
git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux
# Place it inside the libs folder:
# 42so_long/libs/minilibx-linux
```

### 2. Compile & Run

```bash
cd 42so_long

# Base game
make
./so_long maps/example_map.ber

# Bonus game
make bonus
./so_long_bonus maps_bonus/example_map.ber
```

---

## 🧪 Map Tester

A bash script is included to automatically test all maps in a given folder.

```bash
chmod +x map_tester.sh

# Base project
./test_maps.sh ./so_long ./maps

# Bonus project
./test_maps.sh ./so_long_bonus ./maps_bonus
```

---
