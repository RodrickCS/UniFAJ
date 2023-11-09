import tkinter as tk

class Retangulo:
    def __init__(self):
        self.base = 0
        self.altura = 0
        self.area = 0
        self.perimetro = 0

    def calcularArea(self):
        self.area = self.base * self.altura
        
    def calcularPerimetro(self):
        self.perimetro = self.base * 2 + self.altura * 2
        
    

def calcular_resultados():
    retangulo.base = float(base_entry.get())
    retangulo.altura = float(altura_entry.get())
    retangulo.calcularArea()
    retangulo.calcularPerimetro()
    resultado_var.set(f"A área é {round(retangulo.area, 2)} e o perímetro é {round(retangulo.perimetro, 2)}")

retangulo = Retangulo()

janela = tk.Tk()
janela.title("Calculadora de Área de Retângulo")

base_label = tk.Label(janela, text="Base:")
base_label.grid(row=0, column=0, padx=10, pady=10)

base_entry = tk.Entry(janela)
base_entry.grid(row=0, column=1, padx=10, pady=10)

altura_label = tk.Label(janela, text="Altura:")
altura_label.grid(row=1, column=0, padx=10, pady=10)

altura_entry = tk.Entry(janela)
altura_entry.grid(row=1, column=1, padx=10, pady=10)

calcular_botao = tk.Button(janela, text="Calcular", command=calcular_resultados)
calcular_botao.grid(row=2, column=0, columnspan=2, pady=10)

resultado_var = tk.StringVar()

resultado_label = tk.Label(janela, textvariable=resultado_var)
resultado_label.grid(row=3, column=0, columnspan=2, pady=10)

janela.mainloop()
