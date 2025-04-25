#pragma once

#include <string>
#include <vector>
// Temel Windows başlıkları
#include <windows.h>

namespace Ratel {

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool Initialize(const std::string& windowTitle, int width, int height);
    void Shutdown();

    void BeginFrame();
    void EndFrame();

    // Temel render işlemleri
    void Clear(COLORREF color = RGB(0, 0, 0));
    void DrawRect(int x, int y, int width, int height, COLORREF color);
    void DrawText(int x, int y, const std::string& text, COLORREF color);

    // Pencere işlemleri
    bool ShouldClose() const;
    void SwapBuffers();
    void PollEvents();

    // Getter metodları
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    float GetAspectRatio() const { return static_cast<float>(m_width) / static_cast<float>(m_height); }

private:
    int m_width;
    int m_height;
    HWND m_window;
    HDC m_hdc;
};

} // namespace Ratel