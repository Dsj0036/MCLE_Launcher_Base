

#include <cellstatus.h> // Default inclusion with two status definitions.
#include <sys/prx.h> // Default inclusion for declaring entry point.
#include "src\level_renderer.h" // Include for using GameRenderer namespace.



// SYS_MODULE_INFO(codename, attribute, minor, major)

SYS_MODULE_INFO( MCLE_Launcher_Base, 0, 1, 1);
SYS_MODULE_START( _MCLE_Launcher_Base_prx_entry );


// PRX Entry will be called when loaded.
extern "C" int _MCLE_Launcher_Base_prx_entry(void)
{
    // Wait 15.000 mills, (15 seconds.)
    sleep_for_real(15000);
    GameRenderer::Write(); // namespace for patching game renderer.
    return _SYS_PRX_STOP; // Terminate execution at the end of this function 
} // <-
