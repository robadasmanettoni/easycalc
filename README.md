# EasyCalc

**EasyCalc** è una semplice calcolatrice grafica per Windows, scritta interamente in C++ usando le **Win32 API**.  
Non richiede librerie esterne né framework. L'interfaccia è costruita a mano tramite `CreateWindow()`.

---

## 📦 Caratteristiche

- Pulsanti numerici da 0 a 9
- Operazioni: addizione, sottrazione, moltiplicazione, divisione
- Pulsante "=" per il risultato
- Interfaccia minimale e compatta
- Nessuna dipendenza esterna

---

## 🖥️ Compilazione

### ⚙️ Con Visual Studio
1. Crea un nuovo progetto *Win32 API* (non console) chiamato `EasyCalc`
2. Inserisci `main.cpp` nel progetto
3. Compila (`Ctrl + Shift + B`) e avvia (`F5`)

### 🛠️ Con Dev-C++
- Crea un nuovo progetto Windows GUI
- Inserisci `main.cpp`
- Compila e avvia

---

## 📷 Schermata

*(Puoi aggiungere qui un'immagine della finestra, se vuoi)*

---

## 📄 Licenza

Questo progetto è distribuito sotto licenza **MIT**.  
Sentiti libero di modificarlo, riutilizzarlo o ridistribuirlo con attribuzione.

---

## 🧠 Note

Questa è una base funzionale: l'interfaccia c'è, i pulsanti sono creati, ma la logica di calcolo è **ancora da implementare** all'interno dello `switch (wParam)` del messaggio `WM_COMMAND`.
