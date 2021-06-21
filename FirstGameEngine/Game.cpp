#include "Game.h"


Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_OPENGL | flags); // flags);

		if (window) {
			std::cout << "Window created." << std::endl;
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(window);

		if (glContext) {
			std::cout << "GL context created." << std::endl;
		}

		GLenum error = glewInit();
		if (error == GLEW_OK) {
			std::cout << "Glew initialized." << std::endl;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

		/*renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created." << std::endl;
		}*/

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::handleEvents() {
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {

}

void Game::render() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.5f, 0.3f);
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);




	glEnd();

	SDL_GL_SwapWindow(window);

	//SDL_RenderClear(renderer);

	//SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned." << std::endl;
}
