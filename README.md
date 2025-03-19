# so_long

[Leia em Português](README.pt.md)

This project consists of a small 2D game developed using the **MiniLibX** library.

- **Objective**: Create a 2D game where the player must collect items and reach the exit while navigating a map.
- **Game Mechanics**:
  - The player needs to collect all collectibles before reaching the exit.
  - The game displays the move count.
  - Movement occurs using the **W, A, S, D** keys or the arrow keys.
  - The game ends correctly when pressing **ESC** or closing the window.
- **Version With Bonus**:
  - Enemies can defeat the player.
  - Animations for characters and items.
  - Move counter displayed directly on the game screen.

- **Demonstration**:
  - **Version Without Bonus**:
    ![Image](https://github.com/user-attachments/assets/2400dd41-7305-4377-a52f-55f22344e514)
  - **Version With Bonus**:
    ![Image](https://github.com/user-attachments/assets/5922663e-7207-448f-8b00-86008818a07c)
    
- **Graphic Elements**:
  - All the images used in the game:

<div align="center">

  | Player | Enemy | Collectible | Exit | Explosion | Wall | Floor |
  |--------|-------|-------------|------|-----------|------|-------|
  | ![Image](https://github.com/user-attachments/assets/337a5a60-af49-4a24-8bf2-7c9722c56791) | ![Image](https://github.com/user-attachments/assets/4b118944-a70c-4e5a-90f4-62b12fbc772a) | ![Image](https://github.com/user-attachments/assets/88f1dfe9-4676-4622-b52b-f127a3eecb46) | ![Image](https://github.com/user-attachments/assets/a61be625-d8ad-4dff-9f01-f454aa648dfa) | ![Image](https://github.com/user-attachments/assets/684743c0-6ce3-4954-a14e-0d28add3db4a) | ![Image](https://github.com/user-attachments/assets/eba7d8e0-17ff-458b-9bfb-64d2ed364e99) | ![Image](https://github.com/user-attachments/assets/4ec4d4e8-ea92-4201-b541-005adfc996be) |

</div>

- **Installation and Compilation**:

  - **Install MiniLibX**:
    ```bash
    # Clone the MiniLibX repository
    git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux

    # The MiniLibX must be in the libs folder
    cd 42so_long/libs/minilibx-linux
    ```

  - **Compile the Game**:
    ```bash
    # Navigate to the project folder
    cd 42so_long

    # Compile the base game
    make

    # Run the game with a map
    ./so_long maps/example_map.ber

    # Compile the game with bonus features
    make bonus

    # Run the game with a map
    ./so_long_bonus maps_bonus/example_map.ber
    ```

- **Tester**

  A bash script is provided to automatically test all maps in a specified folder:
  
  ```bash
  # Make it executable
  chmod +x map_tester.sh
  # Run the tester on your maps folder
  # Base project 
  ./test_maps.sh ./so_long ./maps
  # Bonus project
  ./test_maps.sh ./so_long_bonus ./maps_bonus
   ```

---
