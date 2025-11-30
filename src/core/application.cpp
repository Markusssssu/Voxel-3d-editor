#include "application.h"
#include "imgui.h"
#include "canvas.h"
#include "treeDir.h"
#include "debug.h"

namespace ApplicationUI {

    void LayoutUI() {

        ImGui::Begin("Layout UI");
        ImGui::Text("Layout Core");
        TreeScapeUI::LayoutUI();
        ImGui::End();
    }

    void CoreUI() {
        ImGui::Begin("Layout UI");
        CanvasUI::RenderUI();
        ImGui::Text("Layout Core");
        DebugUI::DebugToolsUI();
        ImGui::End();
    }
}