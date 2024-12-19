#define GLM_ENABLE_EXPERIMENTAL

#include "app/AppContext.h"
#include "gui/gui.h"
#include "renderContext/renderContext.h"
#include "scene/scene.h"
#include "inputHandler/InputHandler.h"

#ifndef __APPLE__
#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) uint32_t NvOptimusEnablement = 1;
__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;

#ifdef __cplusplus
}
#endif
#endif


// Main code
int main(int, char**)
{
    AppContext appContext;
    RenderContext renderContext(appContext);
    appContext.initFrameBufferManager();
    Gui gui(appContext, renderContext);
    Scene scene(appContext, renderContext);

    InputHandler inputHandler(appContext, renderContext);
    inputHandler.setupCallbacks();

    // Main loop
    while (!renderContext.shouldWindowClose())
    {
        renderContext.preRender();

        scene.update();
        scene.render();

        Gui::preRender();
        gui.draw();
        Gui::postRender();

        renderContext.postRender();
    }

    scene.destroy();
    return 0;
}