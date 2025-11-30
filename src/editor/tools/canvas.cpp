#include "canvas.h"
#include "imgui.h"

namespace CanvasUI {
    void RenderUI() {
        ImGui::Begin("Canvas", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
        ImGui::Text("Canvas");
        ImGui::End();
    }
}