//
// Created by kotleni on 7/19/25.
//

#include "Game.h"


void dominia::Game::init() {
  SDL_Init(SDL_INIT_VIDEO);

  this->window = SDL_CreateWindow("dominia", 640, 480, SDL_WINDOW_OPENGL);

  if (window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    exit(1);
  }

  this->glcontext = SDL_GL_CreateContext(window);
}

void dominia::Game::run() {
  this->isRunning = true;

  while (this->isRunning) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        this->isRunning = false;
      }
    }

    this->update();
    this->render();
    SDL_GL_SwapWindow(window);
  }
}

void dominia::Game::update() {

}

void dominia::Game::render() {
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
}

void dominia::Game::shutdown() {
  SDL_GL_DestroyContext(glcontext);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
