#include "sg_main.h"
#include <assert.h>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGTH  374

void sg_quit(struct sg_ctx *ctx)
{
	SDL_DestroyRenderer(ctx->screen.renderer);
	SDL_DestroyWindow(ctx->screen.window);
	ctx->screen.window = NULL;
	ctx->screen.renderer = NULL;
	SDL_Quit();
}

static bool
sg_initialize(struct sg_ctx *ctx, uint32_t height, uint32_t width)
{
	int i;

	for (i = 0; i < SG_SURFACE_MAX; i++)
		LIST_INIT(&ctx->list.surface[i]);
	LIST_INIT(&ctx->list.save);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		sg_debug("SDL could not initialize! SDL_Error: %s\n",
		    SDL_GetError());
		return false;
	}
	/*
	 * Setup function pointers
	 */
	ctx->quit = sg_quit;
	/*
	 * Setup game status
	 */
	ctx->running = true;
	/*
	 * Setup screen
	 */
	ctx->screen.w = width;
	ctx->screen.h = height;
	ctx->screen.name = "Seventh Gate";
	ctx->screen.window = SDL_CreateWindow("Seventh Gate",
	    SDL_WINDOWPOS_UNDEFINED,
	    SDL_WINDOWPOS_UNDEFINED,
	    width,
	    height,
	    SDL_WINDOW_SHOWN);
	assert(ctx->screen.window != NULL);
	ctx->screen.renderer = SDL_CreateRenderer(ctx->screen.window, -1,
	    SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
}

bool sg_game_loop(sg_ctx_t *ctx)
{
	SDL_Event event;
	while (ctx->running) {
		if (SDL_PollEvent(&event)) {
			switch(event.type) {
			case SDL_QUIT:
				sg_debug("Game quit\n");
				ctx->running = SDL_FALSE;
				break;
			}
		}
	}
	SDL_RenderClear(ctx->screen.renderer);
	SDL_RenderPresent(ctx->screen.renderer);
	ctx->quit(ctx);
	return true;
}
					    
	    
int main(int argc, char **argv)
{
	sg_ctx_t ctx;

	sg_initialize(&ctx, SCREEN_HEIGTH, SCREEN_WIDTH);
	if (sg_game_loop(&ctx) == false) {
		sg_debug("Failed to begin game loop\n");
		exit(EXIT_FAILURE);
	}
}


