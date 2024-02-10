import tkinter as tk
import webbrowser

class MapaApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Google Maps")
        self.geometry("800x600")
        self.inicializar_interface()

    def inicializar_interface(self):
        label = tk.Label(self, text="Digite um local:")
        label.pack(pady=20)

        self.entry_local = tk.Entry(self, width=40)
        self.entry_local.pack(pady=10)

        botao = tk.Button(self, text="Abrir Mapa", command=self.abrir_mapa)
        botao.pack(pady=20)

    def abrir_mapa(self):
        local = self.entry_local.get()
        if local:
            url = f"https://www.google.com/maps/place/{local}"
            webbrowser.open(url)

if __name__ == "__main__":
    app = MapaApp()
    app.mainloop()