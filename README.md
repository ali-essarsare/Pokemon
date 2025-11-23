# Pokemon (minimal)

This small C++ project demonstrates simple card interactions (Pokemon, Energy, Trainer).

Build (PowerShell):

```powershell
g++ -std=c++17 -O2 -Wall Card.cpp EnergyCard.cpp PokemonCard.cpp TrainerCard.cpp Player.cpp main.cpp -o Pokemon.exe
.\Pokemon.exe
```

Notes:
- Headers renamed to `Card.h` and `EnergyCard.h` for consistency.
- If you prefer other file naming, I can rename them back or adjust includes.
