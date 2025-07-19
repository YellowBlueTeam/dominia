#include <Game.h>

int main() {
  auto game = dominia::Game();
  game.init();
  game.run();
  game.shutdown();

  return 0;
}