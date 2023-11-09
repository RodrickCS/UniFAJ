import tkinter as tk

class Circulo:
    def __init__(self):
        self.raio = 0
        self.perimetro = 0
        self.area = 0

    def calcular_perimetro(self):
        self.perimetro = 2 * 3.14 * self.raio

    def calcular_area(self):
        self.area = 3.14 * (self.raio * self.raio)

def calcular_perimetro_area():
    circulo.raio = float(raio_entry.get())
    circulo.calcular_perimetro()
    circulo.calcular_area()
    perimetro_var.set(f"O perímetro é {round(circulo.perimetro,2)}")
    area_var.set(f"A área é {round(circulo.area, 2)}")

circulo = Circulo()

janela = tk.Tk()
janela.title("Calculadora de Perímetro e Área de Círculo")

raio_label = tk.Label(janela, text="Raio:")
raio_label.grid(row=0, column=0, padx=10, pady=10)

raio_entry = tk.Entry(janela)
raio_entry.grid(row=0, column=1, padx=10, pady=10)

calcular_botao = tk.Button(janela, text="Calcular Perímetro e Área", command=calcular_perimetro_area)
calcular_botao.grid(row=1, column=0, columnspan=2, pady=10)

perimetro_var = tk.StringVar()
area_var = tk.StringVar()

perimetro_label = tk.Label(janela, textvariable=perimetro_var)
perimetro_label.grid(row=2, column=0, columnspan=2, pady=10)

area_label = tk.Label(janela, textvariable=area_var)
area_label.grid(row=3, column=0, columnspan=2, pady=10)

janela.mainloop()
