#pragma once

#include "D3DFont.hpp"
#include "../source-sdk/misc/color.hpp"
#include "../_Objects/Objects.hpp"
//#include "../_Objects/Utils.hpp"

#define GET_D3DCOLOR_ALPHA(x) (( x >> 24) & 255)
#define COL2DWORD(x) (D3DCOLOR_ARGB(x.alpha, x.red, x.green, x.blue))

enum GradientType;

class DrawManager
{
public: // Function members
    // Basic non-drawing functions

    DrawManager();

    void InitDeviceObjects      (LPDIRECT3DDEVICE9 pDevice);
    void RestoreDeviceObjects   (LPDIRECT3DDEVICE9 pDevice);
    void InvalidateDeviceObjects();
    void SetupRenderStates      ();


    // Drawing functions

    void Line   (Vec2 vecPos1, Vec2 vecPos2, color color)					 const;
    void Line   (float posx1, float posy1, float posx2, float posy2, color color)	 const;
    void Rect   (Vec2 vecPos1, Vec2 vecPos2, color color)					 const;
    void Rect   (float posx1, float posy1, float posx2, float posy2, color color)	 const;
    void RectFilled          (Vec2 vecPos1, Vec2 vecPos2, color color)		 const;
    void RectFilled          (float posx1, float posy1, float posx2, float posy2, color color)	 const;
    void Triangle            (Vec2 pos1, Vec2 pos2, Vec2 pos3, color color)			 const;
    void TriangleFilled      (Vec2 pos1, Vec2 pos2, Vec2 pos3, color color)			 const;
    void RectFilledGradient  (Vec2 vecPos1, Vec2 vecPos2, color col1, color col2, GradientType type) const;
    void RectFilledMultiColor(const Vec2& vecPos1, const Vec2& vecPos2, color col1, color col2, color col3, color col4) const;

    void String (Vec2 vecPos, DWORD dwFlags, color color, CD3DFont * pFont, const char * szText, ...)		 const;
    void String (float posx, float posy, DWORD dwFlags, color color, CD3DFont* pFont, const char* szText, ...)	 const;


    // Helpers
    Vec2 GetScreenCenter();

private: // Variable members
    LPDIRECT3DDEVICE9 pDevice;
    D3DVIEWPORT9      pViewPort;
    
};
extern DrawManager g_Render;


struct Fonts
{
public:
    void DeleteDeviceObjects()
    {
        console::log("Deleting device objects...");
        HRESULT hr;
        hr = pFontTahoma8->DeleteDeviceObjects();
        if (FAILED(hr)) { console::log("Deleting proceture failed for font Tahoma 8"); }
        hr = pFontTahoma10->DeleteDeviceObjects();
        if (FAILED(hr)) { console::log("Deleting proceture failed for font Tahoma 10"); }
    };

    void InvalidateDeviceObjects()
    {
        HRESULT hr;
        hr = pFontTahoma8->InvalidateDeviceObjects();
        if (FAILED(hr)) { console::log("Invalidating failed for font Tahoma 8"); }
        hr = pFontTahoma10->InvalidateDeviceObjects();
        if (FAILED(hr)) { console::log("Invalidating failed for font Tahoma 10"); }
    };

    void InitDeviceObjects(LPDIRECT3DDEVICE9 pDevice)
    {
        HRESULT hr;
        hr = pFontTahoma8->InitDeviceObjects(pDevice);
        if (FAILED(hr)) { std::cout << (hr) << std::endl; }
        hr = pFontTahoma8->RestoreDeviceObjects();
        if (FAILED(hr)) { std::cout << (hr) << std::endl;; }

        hr = pFontTahoma10->InitDeviceObjects(pDevice);
        if (FAILED(hr)) { std::cout << (hr) << std::endl;; }
        hr = pFontTahoma10->RestoreDeviceObjects();
        if (FAILED(hr)) { std::cout << (hr) << std::endl;; }
    };

    // Fonts
    std::unique_ptr<CD3DFont> pFontTahoma8;
    std::unique_ptr<CD3DFont> pFontTahoma10;
};
extern Fonts g_Fonts;


enum GradientType
{
    GRADIENT_VERTICAL,
    GRADIENT_HORIZONTAL
};
