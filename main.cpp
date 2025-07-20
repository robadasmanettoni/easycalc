#include <windows.h>

HWND button0, button1, button2, button3, button4, button5, button6, button7, button8, button9;
HWND buttonAdd, buttonSubtract, buttonMultiply, buttonDivide, buttonDecimal, buttonEquals;
HWND textBoxOutput;
HWND labelResult;

HFONT hFont1 = CreateFontW(34, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
    switch(Message) {
        case WM_CREATE: {
            // Creazione dei pulsanti numerici
            button0 = CreateWindow("BUTTON", "0", WS_VISIBLE | WS_CHILD,
                 10, 290, 50, 50, hwnd, (HMENU)0, NULL, NULL);
            button1 = CreateWindow("BUTTON", "1", WS_VISIBLE | WS_CHILD,
                 10, 230, 50, 50, hwnd, (HMENU)1, NULL, NULL);
            button2 = CreateWindow("BUTTON", "2", WS_VISIBLE | WS_CHILD,
                 70, 230, 50, 50, hwnd, (HMENU)2, NULL, NULL);
            button3 = CreateWindow("BUTTON", "3", WS_VISIBLE | WS_CHILD,
                 130, 230, 50, 50, hwnd, (HMENU)3, NULL, NULL);
            button4 = CreateWindow("BUTTON", "4", WS_VISIBLE | WS_CHILD,
                 10, 170, 50, 50, hwnd, (HMENU)4, NULL, NULL);
            button5 = CreateWindow("BUTTON", "5", WS_VISIBLE | WS_CHILD,
                 70, 170, 50, 50, hwnd, (HMENU)5, NULL, NULL);
            button6 = CreateWindow("BUTTON", "6", WS_VISIBLE | WS_CHILD,
                 130, 170, 50, 50, hwnd, (HMENU)6, NULL, NULL);
            button7 = CreateWindow("BUTTON", "7", WS_VISIBLE | WS_CHILD,
                 10, 110, 50, 50, hwnd, (HMENU)7, NULL, NULL);
            button8 = CreateWindow("BUTTON", "8", WS_VISIBLE | WS_CHILD,
                 70, 110, 50, 50, hwnd, (HMENU)8, NULL, NULL);
            button9 = CreateWindow("BUTTON", "9", WS_VISIBLE | WS_CHILD,
                 130, 110, 50, 50, hwnd, (HMENU)9, NULL, NULL);
            
            // Creazione dei pulsanti delle operazioni aritmetiche
            buttonAdd = CreateWindow("BUTTON", "+", WS_VISIBLE | WS_CHILD,
                 190, 290, 50, 50, hwnd, (HMENU)10, NULL, NULL);
            buttonSubtract = CreateWindow("BUTTON", "-", WS_VISIBLE | WS_CHILD,
                 190, 230, 50, 50, hwnd, (HMENU)11, NULL, NULL);
            buttonMultiply = CreateWindow("BUTTON", "*", WS_VISIBLE | WS_CHILD,
                 190, 170, 50, 50, hwnd, (HMENU)12, NULL, NULL);
            buttonDivide = CreateWindow("BUTTON", "/", WS_VISIBLE | WS_CHILD,
                 190, 110, 50, 50, hwnd, (HMENU)13, NULL, NULL);
            
            // Creazione dei pulsanti per la virgola e l'uguaglianza
            buttonDecimal = CreateWindow("BUTTON", ",", WS_VISIBLE | WS_CHILD,
                 70, 290, 50, 50, hwnd, (HMENU)14, NULL, NULL);
            buttonEquals = CreateWindow("BUTTON", "=", WS_VISIBLE | WS_CHILD,
                 130, 290, 50, 50, hwnd, (HMENU)15, NULL, NULL);
            
            // Creazione dell'etichetta contenente l'operazione corrente
            labelResult = CreateWindow("STATIC", "-", WS_VISIBLE | WS_CHILD | SS_RIGHT,
                 10, 20, 230, 20, hwnd, (HMENU)16, NULL, NULL);
            
            // Creazione della casella di testo col risultato corrente
            textBoxOutput = CreateWindow("EDIT", "0", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY | ES_RIGHT,
                 10, 50, 230, 40, hwnd, (HMENU)17, NULL, NULL);
            SendMessage(textBoxOutput, WM_SETFONT, (WPARAM)hFont1, TRUE);
            
            break;
        }

        case WM_COMMAND:
            switch (wParam) {
                case 0: // Pulsante "0" premuto
                    // Gestisci l'input del numero 0
                    break;
                case 1: // Pulsante "1" premuto
                    // Gestisci l'input del numero 1
                    break;
                // Aggiungi gestori per gli altri pulsanti numerici e operazioni aritmetiche
                // ...
                case 15: // Pulsante "=" premuto
                    // Esegui il calcolo e visualizza il risultato
                    break;
            }
            break;

        case WM_DESTROY:
            // Libera il font prima di uscire per evitare memory leaks
            DeleteObject(hFont1);
            
            // Quando la finestra viene distrutta, usciamo dall'applicazione
            PostQuitMessage(0);
            
            break;

        default:
            // Gestione dei messaggi non gestiti
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc; // Struttura per la classe della finestra
    HWND hwnd;     // Handle della finestra principale
    MSG msg;       // Struttura per i messaggi

    // Inizializzazione dei membri della struttura wc con zeri
    memset(&wc, 0, sizeof(wc));

    // Impostazione dei membri della struttura wc
    wc.cbSize        = sizeof(WNDCLASSEX);              // Dimensione della struttura WNDCLASSEX
    wc.lpfnWndProc   = WndProc;                         // Puntatore alla funzione di gestione dei messaggi della finestra
    wc.hInstance     = hInstance;                       // Handle dell'istanza dell'applicazione
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);     // Imposta il cursore predefinito

    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);          // Imposta lo sfondo della finestra
    wc.lpszClassName = "WindowClass";                   // Nome della classe della finestra
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION); // Icona grande della finestra
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION); // Icona piccola della finestra

    // Registra la classe della finestra
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "ATTENZIONE: Registrazione della finestra fallita!", "ERRORE", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Crea la finestra principale
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "EasyCalc", WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, /* pos. x */
        CW_USEDEFAULT, /* pos. y */
        260,           /* dim. larghezza */
        380,           /* dim. altezza */
        NULL, NULL, hInstance, NULL);

    // Verifica se la creazione della finestra ha avuto successo
    if (hwnd == NULL) {
        MessageBox(NULL, "ATTENZIONE: Creazione della finestra fallita!", "ERRORE", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Loop principale per gestire i messaggi della finestra
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg); // Traduci i messaggi da tastiera
        DispatchMessage(&msg);  // Invia i messaggi al gestore dei messaggi
    }

    return msg.wParam; // Restituisce il parametro wParam del messaggio di uscita
}
