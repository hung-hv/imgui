#include <iostream>

#include <fmt/format.h>
#include <imgui.h>
#include <implot.h>

#include "render.hpp"

void WindowClass::Draw(std::string_view label)
{
    constexpr static auto window_flags =
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
    constexpr static auto window_size = ImVec2(1280.0F, 720.0F);
    constexpr static auto window_pos = ImVec2(0.0F, 0.0F);

    ImGui::SetNextWindowSize(window_size);
    ImGui::SetNextWindowPos(window_pos);

    ImGui::Begin(label.data(), nullptr, window_flags);

    DrawMenu();
    DrawContent();
    DrawActions();
    DrawFilter();

    ImGui::End();
}

void WindowClass::DrawMenu() {
    if (ImGui::Button("Go up")) {
        if (currentPath.has_parent_path()) {
            currentPath = currentPath.parent_path();
        } else {
            /*do nothing */
        }
    }
    ImGui::SameLine();
    ImGui::Text("Directory: %s", currentPath.string().c_str());
}

void WindowClass::DrawContent() {
    ImGui::Text("Menu");
}

void WindowClass::DrawActions() {
    ImGui::Text("Menu");
}

void WindowClass::DrawFilter() {
    ImGui::Text("Menu");
}

void render(WindowClass &window_obj)
{
    window_obj.Draw("Label");
}
