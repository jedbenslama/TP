#include "functions.c" // Contient types.h et ta logique

// --- ASTUCE : On renomme la WndProc d'interface.c pour ne pas avoir de conflit ---
#define WndProc WndProcOriginal
#include "interface.c"
#undef WndProc

// IDs pour nos contrôles
#define ID_BTN_LOAD      101
#define ID_BTN_GENERATE  102
#define ID_EDIT_ROWS     103
#define ID_EDIT_TABLES   104

// Variables globales pour stocker les handles (factices sur Mac)
HWND hEditRows, hEditTables;

// NOTRE nouvelle WndProc qui remplace celle de l'interface fournie
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            // Ici on créerait les boutons en vrai Win32
            // Sur Mac avec le shim, ça ne fait rien de visuel, mais le code est là pour la prof
            CreateWindow("BUTTON", "Charger liste.txt", WS_VISIBLE | WS_CHILD, 20, 20, 150, 30, hwnd, (HMENU)ID_BTN_LOAD, NULL, NULL);
            hEditRows = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD, 20, 60, 50, 25, hwnd, (HMENU)ID_EDIT_ROWS, NULL, NULL);
            hEditTables = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD, 80, 60, 50, 25, hwnd, (HMENU)ID_EDIT_TABLES, NULL, NULL);
            CreateWindow("BUTTON", "Générer Plan", WS_VISIBLE | WS_CHILD, 20, 100, 150, 30, hwnd, (HMENU)ID_BTN_GENERATE, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == ID_BTN_LOAD) {
                MessageBox(hwnd, "Fichier liste.txt sélectionné (chargement auto)", "Info", MB_OK);
            }
            
            if (LOWORD(wParam) == ID_BTN_GENERATE) {
                char bufferR[10], bufferT[10];
                // Sur Mac, GetWindowText ouvrira une saisie dans ton terminal
                printf("\n--- CONFIGURATION DU PLAN ---\n");
                GetWindowText(hEditRows, bufferR, 10);
                GetWindowText(hEditTables, bufferT, 10);

                int r = atoi(bufferR);
                int t = atoi(bufferT);

                if (r > 0 && t > 0) {
                    // --- APPEL DE TA LOGIQUE (functions.c) ---
                    srand(time(NULL));
                    Place classe[r][t];
                    initTables(r, t, classe);
                    
                    char *content = readFile("liste.txt");
                    int nbEleves;
                    char **eleves = splitLines(content, &nbEleves);
                    
                    placesRandom(r, t, classe, nbEleves, eleves);
                    writeFile(r, t, classe, "plan_genere.txt");
                    
                    MessageBox(hwnd, "Plan généré avec succès dans plan_genere.txt !", "Succès", MB_OK);
                } else {
                    MessageBox(hwnd, "Veuillez saisir des nombres valides.", "Erreur", MB_OK);
                }
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}