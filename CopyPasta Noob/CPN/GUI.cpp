#include <d3d9.h>
#include <string>
#include <Windows.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx9.h"

#include "Base/Config/Config.h"
#include "GUI.h"
#include "Base/Hooks/Hooks.h"
#include "imgui/imgui_internal.h"

bool isGuiOpen = false;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool GUI_handleInput(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (GetAsyncKeyState(VK_INSERT) & 1) {
        isGuiOpen = !isGuiOpen;
    }
    if (isGuiOpen && !ImGui_ImplWin32_WndProcHandler(window, msg, wParam, lParam))
        return true;
    return false;
}

void StyleColorsCusom()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.80f);
    colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
    colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
    colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
    colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

    style.Alpha = 1.0f;                                 // Глобальная альфа относится ко всему в ImGui
    style.WindowPadding = ImVec2(8, 8);                 // Заполнение в окне
    style.WindowRounding = 7.0f;                        // Радиус скругления углов окна. Установите 0.0f, чтобы иметь прямоугольные окна
    style.WindowBorderSize = 1.0f;                      // Толщина границы вокруг окон. Обычно устанавливается на 0,0f или 1,0f. Другие значения недостаточно хорошо проверены.
    style.WindowMinSize = ImVec2(32, 32);               // Минимальный размер окна
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);        // Выравнивание текста строки заголовка
    style.WindowMenuButtonPosition = ImGuiDir_Left;     // Положение кнопки свертывания / закрепления в строке заголовка (влево / вправо). По умолчанию ImGuiDir_Left.
    style.ChildRounding = 0.0f;                         // Радиус скругления углов дочерних окон. Установите 0.0f, чтобы иметь прямоугольные дочерние окна
    style.ChildBorderSize = 1.0f;                       // Толщина границы вокруг дочерних окон. Обычно устанавливается на 0,0f или 1,0f. Другие значения недостаточно хорошо проверены.
    style.PopupRounding = 0.0f;                         // Радиус округления углов всплывающего окна. Установите 0.0f, чтобы иметь прямоугольные дочерние окна
    style.PopupBorderSize = 1.0f;                       // Толщина границы вокруг всплывающих окон или всплывающих окон. Обычно устанавливается на 0,0f или 1,0f. Другие значения недостаточно хорошо проверены.
    style.FramePadding = ImVec2(4, 3);                  // Заполнение внутри рамочного прямоугольника (используется большинством виджетов)
    style.FrameRounding = 0.0f;                         // Радиус скругления углов рамы. Установите 0.0f для прямоугольных рамок (используется большинством виджетов).
    style.FrameBorderSize = 0.0f;                       // Толщина границы вокруг кадров. Обычно устанавливается на 0,0f или 1,0f. Другие значения недостаточно хорошо проверены.
    style.ItemSpacing = ImVec2(8, 4);                   // Горизонтальное и вертикальное расстояние между виджетами / линиями
    style.ItemInnerSpacing = ImVec2(4, 4);              // Горизонтальный и вертикальный интервал между элементами составного виджета (например, слайдер и его метка)
    style.TouchExtraPadding = ImVec2(0, 0);             // Расширяем реактивную ограничивающую рамку для сенсорной системы, где положение касания недостаточно точное. К сожалению, мы не сортируем виджеты, поэтому приоритет наложению всегда будет отдаваться первому виджету. Так что не выращивайте это слишком сильно!
    style.IndentSpacing = 21.0f;                        // Расстояние по горизонтали, например, когда вход в узел дерева. Обычно == (FontSize + FramePadding.x * 2).
    style.ColumnsMinSpacing = 6.0f;                     // Минимальный горизонтальный интервал между двумя столбцами. Предпочтительно> (FramePadding.x + 1).
    style.ScrollbarSize = 14.0f;                        // Ширина вертикальной полосы прокрутки, Высота горизонтальной полосы прокрутки
    style.ScrollbarRounding = 9.0f;                     // Радиус скругления углов захвата для полосы прокрутки
    style.GrabMinSize = 10.0f;                          // Минимальная ширина / высота окна захвата для ползунка / полосы прокрутки
    style.GrabRounding = 0.0f;                          // Радиус закругления углов захвата. Установите 0.0f, чтобы иметь прямоугольные ползунки.
    style.TabRounding = 4.0f;                           // Радиус верхних углов таб. Установите 0.0f, чтобы иметь прямоугольные вкладки.
    style.TabBorderSize = 0.0f;                         // Толщина границы вокруг вкладок.
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);         // Выравнивание текста кнопки, когда кнопка больше текста.
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);     // Выравнивание выбираемого текста, когда кнопка больше текста.
    style.DisplayWindowPadding = ImVec2(19, 19);        // Положение окна ограничено, чтобы быть видимым в области отображения, по крайней мере, на эту величину. Относится только к обычным окнам.
    style.DisplaySafeAreaPadding = ImVec2(3, 3);        // Если вы не видите края экрана (например, на телевизоре), увеличьте отступ в безопасной области. Охватывает всплывающие окна / всплывающие подсказки, а также обычные окна.
    style.MouseCursorScale = 1.0f;                      // Масштабирование курсора мыши, отображаемого программным обеспечением (когда io.MouseDrawCursor включен). Может быть удален позже.
    style.AntiAliasedLines = true;                      // Включить сглаживание на линиях / границах. Отключите, если вам действительно не хватает CPU / GPU.
    style.AntiAliasedFill = true;                       // Включить сглаживание на заполненных фигурах (прямоугольники со скругленными углами, круги и т. Д.)
    style.CurveTessellationTol = 1.25f;                 // Допуск тесселяции при использовании PathBezierCurveTo () без определенного количества сегментов. Уменьшение кривых с высокой тесселяцией (более высокое качество, больше полигонов), увеличение для снижения качества.
}

void GUI_init(IDirect3DDevice9* device)
{
    ImGui::CreateContext();
    ImGui_ImplWin32_Init(FindWindowA("Valve001", NULL));
    ImGui_ImplDX9_Init(device);
    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    //style.WindowRounding = 5.0f;
    //style.WindowBorderSize = 0.0f;
    //style.ChildBorderSize = 0.0f;
    //style.GrabMinSize = 7.0f;
    //style.GrabRounding = 5.0f;
    //style.FrameRounding = 5.0f;
    //style.PopupRounding = 5.0f;

    StyleColorsCusom();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.LogFilename = nullptr;

    static ImWchar ranges[] = { 0x0020, 0x00FF, 0x0100, 0x017f, 0 };
    char buffer[MAX_PATH];
    if (GetWindowsDirectoryA(buffer, MAX_PATH))
        io.Fonts->AddFontFromFileTTF(strcat(buffer, "/Fonts/Tahoma.ttf"), 16.0f, nullptr, ranges);
}

static struct {
    bool triggerbot{ false };
    bool glow{ false };
    bool esp{ false };
    bool misc{ false };
    bool config{ false };
    bool style{ false };
} window;

static void renderMenuBar() noexcept
{
    if (ImGui::BeginMainMenuBar()) {
        //ImGui::MenuItem("Triggerbot", nullptr, &window.triggerbot);
        //ImGui::MenuItem("Glow", nullptr, &window.glow);
        //ImGui::MenuItem("Esp", nullptr, &window.esp);
        ImGui::MenuItem("Misc", nullptr, &window.misc);
        ImGui::MenuItem("Config", nullptr, &window.config);
        ImGui::MenuItem("Style", nullptr, &window.style);
        ImGui::EndMainMenuBar();
    }
}

static constexpr auto windowFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize
| ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;

static void keybind(int& key) noexcept
{
    key ? ImGui::Text("[ 0x%x ]", key) : ImGui::TextUnformatted("[ key ]");
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Press any key to change keybind");
        ImGuiIO& io = ImGui::GetIO();
        for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++)
            if (ImGui::IsKeyPressed(i))
                key = i != VK_ESCAPE ? i : 0;

        for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
            if (ImGui::IsMouseDown(i))
                key = i + (i > 1 ? 2 : 1);
    }
}

static void checkboxedColorPicker(const std::string& name, bool* enable, float* color) noexcept
{
    ImGui::Checkbox(("##" + name).c_str(), enable);
    ImGui::SameLine(0.0f, 5.0f);
    ImGui::PushID(0);
    bool openPopup = ImGui::ColorButton(("##" + name).c_str(), ImColor{ color[0], color[1], color[2] }, ImGuiColorEditFlags_NoTooltip);
    ImGui::PopID();
    ImGui::SameLine(0.0f, 5.0f);
    ImGui::TextUnformatted(name.c_str());
    ImGui::PushID(1);
    if (openPopup)
        ImGui::OpenPopup(("##" + name).c_str());
    if (ImGui::BeginPopup(("##" + name).c_str())) {
        ImGui::PushID(2);
        ImGui::ColorPicker3(("##" + name).c_str(), color, ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_NoSidePreview);
        ImGui::PopID();
        ImGui::EndPopup();
    }
    ImGui::PopID();
}

void ColorPicker(const char* name, float* color) noexcept
{
    ImGui::PushID(name);
    bool openPopup = ImGui::ColorButton("##btn", ImColor{ color[0], color[1], color[2] }, ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoAlpha);
    if (ImGui::BeginDragDropTarget()) {
        if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(IMGUI_PAYLOAD_TYPE_COLOR_3F))
            std::copy((float*)payload->Data, (float*)payload->Data + 3, color);
        ImGui::EndDragDropTarget();
    }
    ImGui::SameLine(0.0f, 5.0f);
    ImGui::TextUnformatted(name);

    if (openPopup)
        ImGui::OpenPopup("##popup");

    if (ImGui::BeginPopup("##popup")) {
        ImGui::ColorPicker3("##picker", color, ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_NoSidePreview);

        ImGui::EndPopup();
    }
    ImGui::PopID();
}

/*static void renderTriggerbotWindow(bool contentOnly) noexcept
{
    if (!contentOnly) {
        if (!window.triggerbot)
            return;
        ImGui::SetNextWindowSize({ 0.0f, 0.0f });
        ImGui::Begin("Triggerbot", &window.triggerbot, windowFlags);
    }

    static int currentCategory{ 0 };
    ImGui::PushItemWidth(110.0f);
    ImGui::PushID(0);
    ImGui::Combo("", &currentCategory, "All\0Pistols\0Heavy\0SMG\0Rifles\0");
    ImGui::PopID();
    ImGui::SameLine();
    static int currentWeapon{ 0 };
    ImGui::PushID(1);
    switch (currentCategory) {
    case 0:
        currentWeapon = 0;
        ImGui::NewLine();
        break;
    case 1: {
        static int currentPistol{ 0 };
        ImGui::Combo("", &currentPistol, "Glock-18\0P2000\0USP-S\0Dual Berettas\0P250\0Tec-9\0Five-Seven\0CZ-75\0Desert Eagle\0Revolver\0");
        currentWeapon = currentPistol + 1;
        break;
    }
    case 2: {
        static int currentHeavy{ 0 };
        ImGui::Combo("", &currentHeavy, "Nova\0XM1014\0Sawed-off\0MAG-7\0M249\0Negev\0");
        currentWeapon = currentHeavy + 11;
        break;
    }
    case 3: {
        static int currentSmg{ 0 };
        ImGui::Combo("", &currentSmg, "Mac-10\0MP9\0MP7\0MP5-SD\0UMP-45\0P90\0PP-Bizon\0");
        currentWeapon = currentSmg + 17;
        break;
    }
    case 4: {
        static int currentRifle{ 0 };
        ImGui::Combo("", &currentRifle, "Galil AR\0Famas\0AK-47\0M4A4\0M4A1-S\0SSG-08\0SG-553\0AUG\0AWP\0G3SG1\0SCAR-20\0");
        currentWeapon = currentRifle + 24;
        break;
    }
    }
    ImGui::PopID();
    ImGui::SameLine();
    ImGui::Checkbox("Enabled", &config.triggerbot[currentWeapon].enabled);
    ImGui::Separator();
    ImGui::Checkbox("On key", &config.triggerbot[currentWeapon].onKey);
    ImGui::SameLine();
    keybind(config.triggerbot[currentWeapon].key);
    ImGui::Checkbox("Friendly fire", &config.triggerbot[currentWeapon].friendlyFire);
    ImGui::Checkbox("Scoped only", &config.triggerbot[currentWeapon].scopedOnly);
    ImGui::Checkbox("Ignore flash", &config.triggerbot[currentWeapon].ignoreFlash);
    ImGui::Checkbox("Ignore smoke", &config.triggerbot[currentWeapon].ignoreSmoke);
    ImGui::PushItemWidth(85.0f);
    ImGui::Combo("Hitgroup", &config.triggerbot[currentWeapon].hitgroup, "All\0Head\0Chest\0Stomach\0Left arm\0Right arm\0Left leg\0Right leg\0");
    ImGui::PushItemWidth(220.0f);
    ImGui::SliderInt("Shot delay", &config.triggerbot[currentWeapon].shotDelay, 0, 250, "%d ms");
    ImGui::InputInt("Min damage", &config.triggerbot[currentWeapon].minDamage);
    config.triggerbot[currentWeapon].minDamage = max(min(config.triggerbot[currentWeapon].minDamage, 250), 0);
    ImGui::Checkbox("Killshot", &config.triggerbot[currentWeapon].killshot);
    if (!contentOnly)
        ImGui::End();
}

static void renderGlowWindow(bool contentOnly) noexcept
{
    if (!contentOnly) {
        if (!window.glow)
            return;
        ImGui::SetNextWindowSize({ 450.0f, 0.0f });
        ImGui::Begin("Glow", &window.glow, windowFlags);
    }

    static int currentCategory{ 0 };
    ImGui::PushItemWidth(110.0f);
    ImGui::PushID(0);
    ImGui::Combo("", &currentCategory, "Allies\0Enemies\0Planting\0Defusing\0Local player\0Weapons\0C4\0Planted C4\0Chickens\0");
    ImGui::PopID();
    static int currentItem{ 0 };
    if (currentCategory <= 3) {
        ImGui::SameLine();
        static int currentType{ 0 };
        ImGui::PushID(1);
        ImGui::Combo("", &currentType, "All\0Visible\0Occluded\0");
        ImGui::PopID();
        currentItem = currentCategory * 3 + currentType;
    }
    else {
        currentItem = currentCategory + 8;
    }

    ImGui::SameLine();
    ImGui::Checkbox("Enabled", &config.glow[currentItem].enabled);
    ImGui::Separator();
    ImGui::Columns(2, nullptr, false);
    ImGui::SetColumnOffset(1, 0.0f); /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ImGui::Checkbox("Health based", &config.glow[currentItem].healthBased);
    ImGui::Checkbox("Rainbow", &config.glow[currentItem].rainbow);
    bool openPopup = ImGui::ColorButton("Color", ImVec4{ config.glow[currentItem].color }, ImGuiColorEditFlags_NoTooltip);
    ImGui::SameLine(0.0f, 5.0f);
    ImGui::Text("Color");
    ImGui::PushID(2);
    if (openPopup)
        ImGui::OpenPopup("");
    if (ImGui::BeginPopup("")) {
        ImGui::PushID(3);
        ImGui::ColorPicker3("", config.glow[currentItem].color, ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_NoSidePreview);
        ImGui::PopID();
        ImGui::EndPopup();
    }
    ImGui::PopID();
    ImGui::NextColumn();
    ImGui::PushItemWidth(220.0f);
    ImGui::SliderFloat("Thickness", &config.glow[currentItem].thickness, 0.0f, 1.0f, "%.2f");
    ImGui::SliderFloat("Alpha", &config.glow[currentItem].alpha, 0.0f, 1.0f, "%.2f");
    ImGui::InputInt("Style", &config.glow[currentItem].style, 1, 1);
    config.glow[currentItem].style = max(min(config.glow[currentItem].style, 3), 0);
    if (!contentOnly)
        ImGui::End();
}

static void renderEspWindow(bool contentOnly) noexcept
{
    if (!contentOnly) {
        if (!window.esp)
            return;
        ImGui::SetNextWindowSize({ 0.0f, 0.0f });
        ImGui::Begin("Esp", &window.esp, windowFlags);
    }

    static int currentCategory{ 0 };
    ImGui::PushItemWidth(110.0f);
    ImGui::PushID(0);
    ImGui::Combo("", &currentCategory, "Allies\0Enemies\0Weapons");
    ImGui::PopID();
    ImGui::SameLine();

    if (currentCategory < 2) {
        static int currentType{ 0 };
        ImGui::PushID(1);
        ImGui::Combo("", &currentType, "All\0Visible\0Occluded\0");
        ImGui::PopID();
        int currentItem = currentCategory * 3 + currentType;
        ImGui::SameLine();
        ImGui::Checkbox("Enabled", &config.esp.players[currentItem].enabled);
        ImGui::Separator();

        checkboxedColorPicker("Box", &config.esp.players[currentItem].box, config.esp.players[currentItem].boxColor);
    }
    else {
        ImGui::Checkbox("Enabled", &config.esp.weapon.enabled);
        ImGui::Separator();

        checkboxedColorPicker("Box", &config.esp.weapon.box, config.esp.weapon.boxColor);
        ImGui::SameLine();
        ImGui::Combo("", &config.esp.weapon.boxType, "2D\0""3D\0");
        checkboxedColorPicker("Snap line", &config.esp.weapon.snapLine, config.esp.weapon.snapLineColor);
        checkboxedColorPicker("Name", &config.esp.weapon.name, config.esp.weapon.nameColor);
    }
    if (!contentOnly)
        ImGui::End();
}*/

static void renderMiscWindow(bool contentOnly) noexcept
{
    if (!contentOnly) {
        if (!window.misc)
            return;
        ImGui::SetNextWindowSize({ 0.0f, 0.0f });
        ImGui::Begin("Misc", &window.misc, windowFlags);
    }

    //ImGui::SetNextWindowSize({ 0.0f, 0.0f });
    //ImGui::Begin("Misc", &window.misc, windowFlags);
    ImGui::Checkbox("Auto strafe", &config.misc.autostrafe);
    ImGui::Checkbox("Bunnyhop", &config.misc.bunnyhop);
    ImGui::Checkbox("Moonwalk", &config.misc.moonwalk);
    ImGui::Checkbox("sv_cheats", &config.misc.sv_cheats);
    if (ImGui::Button("Unhook"))
        Hooks_restore();
    if (!contentOnly)
        ImGui::End();
}

void updateColors() noexcept
{
    switch (config.style.menuColors) {
    case 0: ImGui::StyleColorsDark(); break;
    case 1: ImGui::StyleColorsLight(); break;
    case 2: ImGui::StyleColorsClassic(); break;
    }
}

static void renderConfigWindow(bool contentOnly) noexcept
{
    if (!contentOnly) {
        if (!window.config)
            return;
        ImGui::SetNextWindowSize({ 290.0f, 190.0f });
        ImGui::Begin("Config", &window.config, windowFlags);

        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnOffset(1, 170.0f);

        ImGui::PushItemWidth(160.0f);
    }

    //ImGui::Columns(2, nullptr, false);
    //ImGui::SetColumnOffset(1, 170.0f);

    ImGui::PushItemWidth(160.0f);

    static int currentConfig = -1;

    if (static_cast<size_t>(currentConfig) >= config.count)
        currentConfig = -1;

    static char buffer[16];

    if (ImGui::ListBox("", &currentConfig, [](void* data, int idx, const char** out_text) {
        *out_text = static_cast<const char**>(data)[idx];
        return true;
    }, config.names, config.count, 5) && currentConfig != -1)
    strcpy(buffer, config.names[currentConfig]);

    ImGui::PushID(0);
    if (ImGui::InputText("", buffer, IM_ARRAYSIZE(buffer), ImGuiInputTextFlags_EnterReturnsTrue)) {
        if (currentConfig != -1)
            Config_rename(currentConfig, buffer);
    }
    ImGui::PopID();
    //ImGui::NextColumn();

    ImGui::PushItemWidth(100.0f);

    if (ImGui::Button("Create config", { 100.0f, 25.0f }))
        Config_add(buffer);

    if (ImGui::Button("Reset config", { 100.0f, 25.0f }))
        Config_reset();

    if (currentConfig != -1) {
        if (ImGui::Button("Load selected", { 100.0f, 25.0f })) {
            Config_load(currentConfig);
            updateColors();
        }
        if (ImGui::Button("Save selected", { 100.0f, 25.0f }))
            Config_save(currentConfig);
        if (ImGui::Button("Delete selected", { 100.0f, 25.0f }))
            Config_remove(currentConfig);
    }

    if (!contentOnly)
        ImGui::End();
}

static void renderStyleWindow(bool contentOnly) noexcept
{
    if (!contentOnly) {
        if (!window.style)
            return;
        ImGui::SetNextWindowSize({ 0.0f, 0.0f });
        ImGui::Begin("Style", &window.style, windowFlags);
    }

    ImGui::PushItemWidth(150.0f);
    if (ImGui::Combo("Menu style", &config.style.menuStyle, "One window\0Classic\0"))
        window = { };
    if (ImGui::Combo("Menu colors", &config.style.menuColors, "Dark\0Light\0Classic\0Custom\0"))
        updateColors();
    ImGui::PopItemWidth();

    if (config.style.menuColors == 3) {
        ImGuiStyle& style = ImGui::GetStyle();
        for (int i = 0; i < ImGuiCol_COUNT; i++) {
            if (i && i & 3) ImGui::SameLine(220.0f * (i & 3));

            ColorPicker(ImGui::GetStyleColorName(i), (float*)&style.Colors[i]);
        }
    }

    if (!contentOnly)
        ImGui::End();
}

/*void GUI_render()
{
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    renderMenuBar();
    renderTriggerbotWindow();
    renderGlowWindow();
    renderEspWindow();
    renderMiscWindow();
    renderConfigWindow();

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}*/

void GUI_render()
{
    if (config.style.menuStyle) {
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        renderMenuBar();
        //renderTriggerbotWindow(false);
        //renderGlowWindow(false);
        //renderEspWindow(false);
        renderMiscWindow(false);
        renderConfigWindow(false);
        renderStyleWindow(false);

        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
    }
    else {
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        renderGuiStyle2();

        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
    }
}

void GUI_invalidateDeviceObjects(void)
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
}

void GUI_createDeviceObjects(void)
{
    ImGui_ImplDX9_CreateDeviceObjects();
}

void renderGuiStyle2()
{
    ImGui::SetNextWindowSize({ 800.0f, 0.0f });
    ImGui::Begin("CopyPastaNoob's", nullptr, windowFlags | ImGuiWindowFlags_NoTitleBar);

    if (ImGui::BeginTabBar("TabBar", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_NoTooltip)) {
        //if (ImGui::BeginTabItem("Triggerbot")) {
        //    renderTriggerbotWindow(true);
        //    ImGui::EndTabItem();
        //}
        //if (ImGui::BeginTabItem("Glow")) {
        //    renderGlowWindow(true);
        //    ImGui::EndTabItem();
        //}
        //if (ImGui::BeginTabItem("Esp")) {
        //    renderEspWindow(true);
        //    ImGui::EndTabItem();
        //}
        if (ImGui::BeginTabItem("Misc")) {
            renderMiscWindow(true);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Config")) {
            renderConfigWindow(true);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Style")) {
            renderStyleWindow(true);
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }

    ImGui::End();
}