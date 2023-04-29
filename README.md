# visual-computing-22

This project is a game engine for a 2D game. It is completely written in C++ and only uses [SFML](https://github.com/SFML/SFML) and [tinyxml2](https://github.com/leethomason/tinyxml2)

All texture/sprite assets used are taken from [Pixel Frogs - Pixel Adventure](https://pixelfrog-assets.itch.io/pixel-adventure-1)

## Main Features

-   Rendering (Sprites, Text, Shapes. Done via SFML)
-   Phase based game loop
-   Entity and MetaEntity system (XML based)
-   Event/Listener system (Callbacks)
-   Collision detection
-   Input handling
-   Map system (XML based. Supports multiple maps)
-   Point/Score system
-   Highscore system (Persistent across restarts, but currently just only one highscore for all maps)

-   Fully playable game demo (Turtle Maze)

## Map Editor

To easily create maps for the game, a map editor was created. It is written in Javascript and needs Node.js to run. It can be found here: [visual-computing-22-mapgen](https://github.com/TKSpectro/visual-computing-22-mapgen)

There also exists a visual editor, which can be used in addition to the map editor. It is available as a [codepen](https://codepen.io/tkspectro/pen/YzJxNvY)
(For more information check the README of the map editor)
