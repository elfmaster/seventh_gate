#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/queue.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "debug.h"

#define SG_SURFACE_PLAYER1	0
#define SG_SURFACE_PLAYER2	1
#define SG_SURFACE_NPC		2
#define SG_SURFACE_TILES	3
#define SG_SURFACE_BG		4
#define SG_SURFACE_FG		5

#define SG_SURFACE_MAX		10

/*
 * Internal structure
 * move to sg_internal.h
 */
struct sg_surface_node {
	SDL_Surface *surface;
	LIST_ENTRY(sg_surface_node) _linkage;
};

struct sg_save_node {
	char *savefile;
	LIST_ENTRY(sg_save_node) _linkage;
};

typedef struct sg_ctx {
	SDL_Window *window;
	SDL_Surface *screen;
	struct {
		LIST_HEAD(surface_list, sg_surface_node) surface[SG_SURFACE_MAX + 1];
		LIST_HEAD(save_list, sg_save_node) save;
	} list;
	char *savefile;
} sg_ctx_t;	
