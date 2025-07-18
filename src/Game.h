//
// Created by kotleni on 7/19/25.
//

#ifndef GAME_H
#define GAME_H

#include <GL/gl.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_video.h>
#include <stdlib.h>

#include <cstdlib>

namespace dominia {
class Game {
 private:
  SDL_Window* window;
  SDL_GLContext glcontext;
  bool isRunning = false;

  void update();
  void render();

 public:
  void init();
  void run();
  void shutdown();
};
}  // namespace dominia

#endif  // GAME_H
