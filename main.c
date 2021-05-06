#include "sg_main.h"
#include <assert.h>

#define SCREEN_WIDTH = 800
#define SCREEN_HEIGTH = 374

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
	ctx->window = SDL_CreateWindow("Seventh Gate",
	    SDL_WINDOWPOS_UNDEFINED,
	    SDL_WINDOWPOS_UNDEFINED,
	    width,
	    height,
	    SDL_WINDOW_SHOWN);
	assert(ctx->window != NULL);
}
	    
int main(int argc, char **argv)
{
	sg_ctx_t ctx;

}


