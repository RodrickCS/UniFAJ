import tkinter as tk

class Carro:
    def __init__(self, marca, modelo, ano):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano

    def obter_info(self):
        return f"{self.marca} {self.modelo} ({self.ano})"

def listar_carros():
    lista_carros.delete(0, tk.END)
    for carro in carros:
        lista_carros.insert(tk.END, carro.obter_info())

carro1 = Carro("Volkswagen", "Fusca", "1965")
carro2 = Carro("Ford", "Mustang", "2022")

root = tk.Tk()
root.title("Lista de Carros")

carros = [carro1, carro2]

label = tk.Label(root, text="Carros:")
lista_carros = tk.Listbox(root)
botao_listar = tk.Button(root, text="Listar Carros", command=listar_carros)

label.pack(pady=10)
lista_carros.pack(pady=10)
botao_listar.pack()

root.mainloop()
