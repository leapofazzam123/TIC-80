// MIT License

// Copyright (c) 2017 Vadim Grigoruk @nesbox // grigoruk@gmail.com

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "stub.h"
#include "studio/studio.h"
#include "studio/system.h"
#include "studio/fs.h"
#include "studio/net.h"

typedef struct
{
    bool down;
    bool click;

    tic_point start;
    tic_point end;

} MouseState;

static struct
{
	tic_mem* tic;

	struct
    {
        MouseState state[3];
    } mouse;

    tic_fs* fs;

} stub;

Studio* studioInit(s32 argc, char **argv, s32 samplerate, const char* folder)
{
	stub.fs = tic_fs_create(folder, NULL);

	return NULL;
}

void setStudioMode(EditorMode mode)
{
	
}

EditorMode getStudioMode()
{
	return TIC_START_MODE;
}

void setCursor(tic_cursor id)
{
}

static inline bool pointInRect(const tic_point* pt, const tic_rect* rect)
{
    return (pt->x >= rect->x) 
        && (pt->x < (rect->x + rect->w)) 
        && (pt->y >= rect->y)
        && (pt->y < (rect->y + rect->h));
}

bool checkMousePos(const tic_rect* rect)
{
    tic_point pos = tic_api_mouse(stub.tic);
    return pointInRect(&pos, rect);
}

bool checkMouseClick(const tic_rect* rect, tic_mouse_btn button)
{
    MouseState* state = &stub.mouse.state[button];

    bool value = state->click
        && pointInRect(&state->start, rect)
        && pointInRect(&state->end, rect);

    if(value) state->click = false;

    return value;
}

bool checkMouseDown(const tic_rect* rect, tic_mouse_btn button)
{
    MouseState* state = &stub.mouse.state[button];

    return state->down && pointInRect(&state->start, rect);
}

void playSystemSfx(s32 id)
{
    // const tic_sample* effect = &impl.config->cart.bank0.sfx.samples.data[id];
    // tic_api_sfx(impl.studio.tic, id, effect->note, effect->octave, -1, 0, MAX_VOLUME, MAX_VOLUME, effect->speed);
}

void drawBitIcon(s32 id, s32 x, s32 y, u8 color)
{
    // tic_mem* tic = impl.studio.tic;

    // const tic_tile* tile = &getConfig()->cart->bank0.tiles.data[id];

    // for(s32 i = 0, sx = x, ex = sx + TIC_SPRITESIZE; i != TIC_SPRITESIZE * TIC_SPRITESIZE; ++i, ++x)
    // {
    //     if(x == ex)
    //     {
    //         x = sx;
    //         y++;
    //     }

    //     if(tic_tool_peek4(tile, i))
    //         tic_api_pix(tic, x, y, color, false);
    // }
}

tic_key* getKeymap()
{
    // return impl.keycodes;
    return NULL;
}

bool keyWasPressed(tic_key key)
{
    // tic_mem* tic = impl.studio.tic;
    // return tic_api_keyp(tic, key, KEYBOARD_HOLD, KEYBOARD_PERIOD);

    return false;
}

bool anyKeyWasPressed()
{
    // tic_mem* tic = impl.studio.tic;

    // for(s32 i = 0; i < TIC80_KEY_BUFFER; i++)
    // {
    //     tic_key key = tic->ram.input.keyboard.keys[i];

    //     if(tic_api_keyp(tic, key, KEYBOARD_HOLD, KEYBOARD_PERIOD))
    //         return true;
    // }

    return false;
}

void tic_net_get(tic_net* net, const char* path, net_get_callback callback, void* calldata) {}

void drawBGAnimation(tic_mem* tic, s32 ticks)
{

}

void drawBGAnimationScanline(tic_mem* tic, s32 row)
{
}

void exitGameMenu(){}

void hideGameMenu()
{
    // tic_core_resume(impl.studio.tic);
    // impl.mode = TIC_RUN_MODE;
}

void exitStudio() {}

void tiles2ram(tic_ram* ram, const tic_tiles* src)
{
    memcpy(ram->tiles.data, src, sizeof ram->tiles * TIC_SPRITE_BANKS);
}

void sfx_stop(tic_mem* tic, s32 channel)
{
    tic_api_sfx(tic, -1, 0, 0, -1, channel, MAX_VOLUME, MAX_VOLUME, SFX_DEF_SPEED);
}

const StudioConfig* getConfig()
{
    // return &impl.config->data;
    return NULL;
}
