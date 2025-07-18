#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <GL/gl.h>

#include <iostream>

int main() {
  SDL_Window* window;
  bool done = false;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("dominia",
                            640,
                            480,
                            SDL_WINDOW_OPENGL
  );

  if (window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  SDL_GLContext glcontext = SDL_GL_CreateContext(window);

  while (!done) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        done = true;
      }
    }

    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DestroyContext(glcontext);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}