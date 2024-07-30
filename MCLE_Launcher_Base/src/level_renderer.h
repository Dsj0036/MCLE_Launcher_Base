// Level renderer patches


#pragma once
#include "System.h" // for using system utilities and types.
#include "game.h" //  minecraft dk

namespace GameRenderer
{
	// Used for creating an STUB that will be used next for overriding an original 
	// game function.
	// * Params:
	// * type, functionName, argumentTypes...
	CREATE_DUMMY_STUB(int, __asm_nop_render, int, double, int, int, char);

	// In-Project reference to game's original function that is being modified by this one.
	int OverrideCallToRenderer(uintptr_t gameRendererInstance, double argument, uint64_t relativeTicks, int argument2, char unknownByte ) {
		
		// Render the base game frame.
		// This include all the level and screen.
		// If something below crashes, the screen will crash at the first game.
		// Dont do heavy executions on this function. 
		// Try use another function or ppu_thread instead.
		int ret = __asm_nop_render(gameRendererInstance, argument, relativeTicks, argument2, unknownByte);
		
		
		
		// FJ haves functions for the renderer and misc ones.
		// Call draw text for showing basic wide strings (L)
		// Arguments: textWide,x,y, color 


		// this will render the following text on all frames ingame.
		// at the top left corner (0,0) with the color -1 white.
		fj::DrawText(L"Base launcher by D.s.j. for ur custom/private content!", 0, 0, -1L);
		

		// Arguments: textString, x,y, color, shadow(true/false)
		fj::DrawString("This is a red text!!!", 0, 10, color(155, 0, 0), false);

		fj::DrawString("This is a shadow text!!!", 0, 20, -1, true);


		
		return ret;
	}

	// Function for patch the original game function.
	void Write() {
		// hookfunction instruction for the ps3.
		// * Params:
		//  * Fixed address to function, override function address, stub function address
		hookfunction(11154272, fn(OverrideCallToRenderer), fn(__asm_nop_render));
	}

}



