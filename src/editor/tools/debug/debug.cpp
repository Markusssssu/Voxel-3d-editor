#include "debug.h"
#include "imgui.h"

namespace DebugUI {
    void DebugToolsUI() {
        ImGui::Begin("Debug Tools", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
        ImGui::ShowDebugLogWindow(nullptr);
        ImGui::End();
    }
}