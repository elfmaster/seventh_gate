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
#define SG_SURFACE_WINDOW	6
#define SG_SURFACE_ENEMY	7
#define SG_SURFACE_MAX		10

#define SG_SURFACE_ANGLE_MAX 8

struct surface_angle {
	SDL_Surface *image[SG_SURFACE_ANGLE_MAX];
	size_t sz[SG_SURFACE_ANGLE_MAX];
};

struct player_stats {
	size_t level;
	size_t nextlevel;
	size_t mp;
	size_t max_mp;
	size_t hp;
	size_t max_hp;
	size_t gold;
	size_t exp;
};

struct sg_hero {
	int x, y;
	struct player_stats stats;
	struct surface_angle walk[SG_SURFACE_ANGLE_MAX];
};

/*
 * Internal structure
 * move to sg_internal.h
 */
struct sg_surface_node {
	unsigned int type;
	SDL_Surface *surface;
	LIST_ENTRY(sg_surface_node) _linkage;
};

struct sg_save_node {
	char *savefile;
	LIST_ENTRY(sg_save_node) _linkage;
};

typedef struct sg_ctx {
	SDL_bool running;
	struct {
		size_t w;
		size_t h;
		const char *name;
		SDL_Window *window;
		SDL_Surface *screen;
		SDL_Renderer *renderer;
	} screen;
	struct {
		LIST_HEAD(surface_list, sg_surface_node) surface[SG_SURFACE_MAX + 1];
		LIST_HEAD(save_list, sg_save_node) save;
	} list;
	char *savefile;
	struct sg_hero hero;

	void (*quit)(struct sg_ctx *);
	bool (*draw_hero)(struct sg_ctx *);
} sg_ctx_t;
