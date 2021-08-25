#include "sg_main.h"

bool
sg_hero_drawsprite(struct sg_ctx *ctx, sg_hero_action_t action, sg_position_t pos)
{


	return true;
}

void
sg_hero_position(struct sg_ctx *ctx, unsigned int pos)
{
	struct sg_hero *hero = &ctx->hero;
	size_t inc = SG_HERO_INCREMENT;

	switch(pos) {
	case SG_HERO_POS_NE:
		hero->y -= inc;
		hero->x += inc;
		hero->diagnol = true;
		hero->surface_angle = SG_SURFACE_ANGLE_NE;
		break;
	case SG_HERO_POS_NW:
		hero->y -= inc;
		hero->x -= inc;
		hero->diagnol = true;
		hero->surface_angle = SG_SURFACE_ANGLE_NW;
		break;
	case SG_HERO_POS_SE:
		hero->y += inc;
		hero->x += inc;
		hero->diagnol = true;
		hero->surface_angle = SG_SURFACE_ANGLE_SE;
		break;
	case SG_HERO_POS_SW:
		hero->y += inc;
		hero->x -= inc;
		hero->diagnol = true;
		hero->surface_angle = SG_SURFACE_ANGLE_SW;
		break;
	}

	return;
}	
