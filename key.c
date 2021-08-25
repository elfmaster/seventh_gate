#include "sg_main.h"

bool
sg_keytest(SDL_Keycode key)
{
	const uint8_t *keystate = SDL_GetKeyboardState(NULL);
	if (key < 0 || key >= 322) {
		sg_debug("invalid key\n");
		return false;
	}
	return keystate[key];
}

