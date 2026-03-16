#ifndef WINDOWS_H
#define WINDOWS_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <string.h>

typedef void* HWND;
typedef void* HINSTANCE;
typedef void* HMENU;
typedef void* LPVOID;
typedef const char* LPCSTR;
typedef char* LPSTR;
typedef long long LRESULT;
typedef unsigned int UINT;
typedef unsigned long long WPARAM;
typedef long long LPARAM;
typedef int BOOL;

#define CALLBACK
#define WINAPI
#define FALSE 0
#define TRUE 1

#define WM_CREATE      0x0001
#define WM_DESTROY     0x0002
#define WM_COMMAND     0x0111
#define MB_OK          0x00000000L
#define WS_OVERLAPPED  0x00000000L
#define WS_CAPTION     0x00C00000L
#define WS_SYSMENU     0x00080000L
#define WS_CHILD       0x40000000L
#define WS_VISIBLE     0x10000000L
#define CW_USEDEFAULT  ((int)0x80000000)
#define IDC_ARROW      ((char*)32512)

#define LOWORD(l) ((unsigned short)((unsigned long)(l) & 0xffff))

typedef struct tagWNDCLASS {
    UINT style;
    LRESULT (CALLBACK *lpfnWndProc)(HWND, UINT, WPARAM, LPARAM);
    int cbClsExtra; int cbWndExtra;
    HINSTANCE hInstance; void* hIcon; void* hCursor; void* hbrBackground;
    LPCSTR lpszMenuName; LPCSTR lpszClassName;
} WNDCLASS;

typedef struct tagMSG { HWND hwnd; UINT message; WPARAM wParam; LPARAM lParam; unsigned int time; } MSG;

static LRESULT (CALLBACK *g_CurrentWndProc)(HWND, UINT, WPARAM, LPARAM) = NULL;
static bool g_QuitRequested = false;

static inline void PostQuitMessage(int e) { g_QuitRequested = true; }
static inline LRESULT DefWindowProc(HWND h, UINT m, WPARAM w, LPARAM l) { return 0; }
static inline void RegisterClass(const WNDCLASS* wc) { g_CurrentWndProc = wc->lpfnWndProc; }
static inline void* LoadCursor(void* h, char* c) { return NULL; }

static inline HWND CreateWindow(LPCSTR cn, LPCSTR wn, unsigned int s, int x, int y, int w, int h, HWND p, HMENU m, HINSTANCE hi, LPVOID lp) {
    if (!(s & WS_CHILD)) { // Si c'est la fenêtre principale
        if (SDL_Init(SDL_INIT_VIDEO) < 0) return NULL;
        HWND win = (HWND)SDL_CreateWindow(wn, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
        // On simule WM_CREATE
        if (g_CurrentWndProc) g_CurrentWndProc(win, WM_CREATE, 0, 0);
        return win;
    }
    return (HWND)0xDEAD; // Dummy handle pour les boutons/champs sur Mac
}

static inline void ShowWindow(HWND h, int n) {}
static inline int MessageBox(HWND h, LPCSTR t, LPCSTR c, UINT u) {
    return SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, c, t, (SDL_Window*)h);
}

// Simule la lecture de texte (pour les champs de saisie) via le terminal sur Mac
static inline int GetWindowText(HWND h, LPSTR lp, int n) {
    printf("Saisie console (Simulée pour Mac) > ");
    fgets(lp, n, stdin);
    lp[strcspn(lp, "\n")] = 0;
    return strlen(lp);
}

static inline BOOL GetMessage(MSG* m, HWND h, UINT min, UINT max) {
    if (g_QuitRequested) return FALSE;
    SDL_Event e;
    if (SDL_WaitEvent(&e)) {
        if (e.type == SDL_QUIT) { m->message = WM_DESTROY; return TRUE; }
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_l) { m->message = WM_COMMAND; m->wParam = 101; return TRUE; } // L pour Liste
            if (e.key.keysym.sym == SDLK_g) { m->message = WM_COMMAND; m->wParam = 102; return TRUE; } // G pour Générer
        }
        return TRUE;
    }
    return FALSE;
}

static inline BOOL TranslateMessage(const MSG* m) { return TRUE; }
static inline LRESULT DispatchMessage(const MSG* m) {
    if (g_CurrentWndProc && m->message != 0) return g_CurrentWndProc(m->hwnd, m->message, m->wParam, m->lParam);
    return 0;
}

int WINAPI WinMain_Internal(HINSTANCE h, HINSTANCE hp, LPSTR lp, int n);
#define WinMain WinMain_Internal
int main(int argc, char** argv) { return WinMain_Internal((HINSTANCE)0, NULL, (LPSTR)"", 1); }

#endif