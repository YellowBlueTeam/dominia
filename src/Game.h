//
// Created by kotleni on 7/19/25.
//

#ifndef GAME_H
#define GAME_H

#include <GL/gl.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_timer.h>
#include <stdlib.h>

#include <cstdlib>

// TODO: Move somewhere else
const int TARGET_FPS = 60;
const int FRAME_DELAY = 1000 / TARGET_FPS;

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
