#include "Core/Game.hpp"

Game *game = nullptr;

int main() {

    game = new Game();

    game->init(1920, 1080, "Game");
    game->viewport(1920, 1080);
    game->update();
    game->clean();

    return 0;
}