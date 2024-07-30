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
	
	// Se usa para crear un STUB que se usará luego para sobrescribir una función
	// original del juego.
	// * Params:
	// * type, functionName, argumentTypes...
	CREATE_DUMMY_STUB(int, __asm_nop_render, int, double, int, int, char);

	// In-Project reference to game's original function that is being modified by this one.
	// Referencia en el proyecto a la función original del juego que está siendo modificada.
	int OverrideCallToRenderer(uintptr_t gameRendererInstance, double argument, uint64_t relativeTicks, int argument2, char unknownByte ) {
		
		// Render the base game frame.											 / Renderizar el cuadro base del juego.
		// This include all the level and screen.								 / Esto incluye todo el nivel y la pantalla.
		// If something below crashes, the screen will crash at the first frame. / Si algo falla aquí, la pantalla fallará en el primer juego.
		// Dont do heavy executions on this function. 							 / No ejecutes operaciones pesadas en esta función.
		// Try use another function or ppu_thread instead.						 / Intenta usar otra función o ppu_thread en su lugar.
		int ret = __asm_nop_render(gameRendererInstance, argument, relativeTicks, argument2, unknownByte);
		
		
		
		// FJ haves functions for the renderer and misc ones. /		FJ tiene funciones para el renderizador y otras misceláneas.
		// Call draw text for showing basic wide strings (L)  /		Llamar a draw text para mostrar cadenas amplias básicas (L)
		// Arguments: textWide,x,y, color 					  /		Argumentos: textWide, x, y, color


		// this will render the following text on all frames ingame. / Esto renderizará el siguiente texto en todos los cuadros del juego,
		// at the top left corner (0,0) with the color -1 white.	/ en la esquina superior izquierda (0,0) con el color -1 blanco.

		fj::DrawText(L"Base launcher by D.s.j. for ur custom/private content!", 0, 0, -1L);
		

		// Arguments: textString, x,y, color, shadow(true/false)
		// Argumentos: textString, x, y, color, shadow (true/false)
		fj::DrawString("This is a red text!!!", 0, 10, color(155, 0, 0), false);

		fj::DrawString("This is a shadow text!!!", 0, 20, -1, true);


		
		return ret;
	}

	// Function for patch the original game function.
	// Función para parchear la función original del juego.
	void Write() {
		// hookfunction instruction for the ps3.
		// * Params:
		//  * Fixed address to function, override function address, stub function address
	
		// Instrucción hookfunction para la PS3.
		// * Params:
		//  * Dirección fija a la función, dirección de la función de sobrescritura, dirección de la función stub

		hookfunction(11154272, fn(OverrideCallToRenderer), fn(__asm_nop_render));
	}

}



