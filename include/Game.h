//
// Created by kotleni on 7/19/25.
//

#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL_video.h>

// TODO: Move somewhere else
const bool USE_VSYNC = true;
const int TARGET_FPS = 60;
const int FRAME_DELAY = 1000 / TARGET_FPS;

namespace dominia {
class Game {
 public:
  void init();
  void run();
  void shutdown();

 private:
  void update();
  void render();

  SDL_Window* window;
  SDL_GLContext glcontext;
  bool isRunning = false;
};
}  // namespace dominia

#endif  // GAME_H
