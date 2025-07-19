//
// Created by kotleni on 7/19/25.
//

#include "../include/Game.h"

#include <GL/gl.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <stdlib.h>

#include <cstdio>
#include <cstdlib>

namespace dominia {
void Game::init() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetLogPriorities(SDL_LOG_PRIORITY_INFO);

  this->window = SDL_CreateWindow("dominia", WINDOW_W, WINDOW_H, SDL_WINDOW_OPENGL);

  if (window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    exit(1);
  }

  this->glcontext = SDL_GL_CreateContext(window);

  // Toggle VSync
  SDL_GL_SetSwapInterval(USE_VSYNC);
}

void Game::run() {
  this->isRunning = true;

  int frameCount = 0;
  Uint32 lastTime = SDL_GetTicks();
  int fps = 0;

  while (this->isRunning) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        this->isRunning = false;
      }
    }

    this->update();
    this->render();
    SDL_GL_SwapWindow(window);

    frameCount++;
    Uint32 currentTime = SDL_GetTicks();

    // Calculate & show FPS in window title
    if (currentTime - lastTime >= 1000) {
      fps = frameCount;

      char title[50];
      snprintf(title, 50, "dominia - FPS: %d", fps);
      SDL_SetWindowTitle(window, title);

      frameCount = 0;
      lastTime = currentTime;
    }

    auto frameTime = currentTime - frameStart;
    // Cap FPS if vsync disabled
    if (!USE_VSYNC && FRAME_DELAY > frameTime) {
      SDL_Delay(FRAME_DELAY - frameTime);
    }
  }
}

void Game::update() {}

void Game::render() {
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Game::shutdown() {
  SDL_GL_DestroyContext(glcontext);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
}  // namespace dominia