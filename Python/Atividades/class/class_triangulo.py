import tkinter as tk
import math

class Triangulo:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def perimetro(self):
        return self.a + self.b + self.c

    def area(self):
        s = (self.a + self.b + self.c) / 2
        area = math.sqrt(s * (s - self.a) * (s - self.b) * (s - self.c))
        return area

def exibir_informacoes_triangulo():
    try:
        lado_a = float(entry_lado_a.get())
        lado_b = float(entry_lado_b.get())
        lado_c = float(entry_lado_c.get())

        triangulo = Triangulo(lado_a, lado_b, lado_c)

        texto = f"Perímetro: {triangulo.perimetro()}\nÁrea: {triangulo.area()}"
        label_info_triangulo.config(text=texto)
    except ValueError:
        label_info_triangulo.config(text="Por favor, insira valores numéricos para os lados do triângulo.")

root = tk.Tk()
root.title("Informações do Triângulo")

label_lado_a = tk.Label(root, text="Lado A:")
label_lado_a.pack(pady=5)
entry_lado_a = tk.Entry(root)
entry_lado_a.pack(pady=5)

label_lado_b = tk.Label(root, text="Lado B:")
label_lado_b.pack(pady=5)
entry_lado_b = tk.Entry(root)
entry_lado_b.pack(pady=5)

label_lado_c = tk.Label(root, text="Lado C:")
label_lado_c.pack(pady=5)
entry_lado_c = tk.Entry(root)
entry_lado_c.pack(pady=5)

label_info_triangulo = tk.Label(root, text="")
label_info_triangulo.pack(pady=10)

botao_exibir_triangulo = tk.Button(root, text="Exibir Informações do Triângulo", command=exibir_informacoes_triangulo)
botao_exibir_triangulo.pack()

root.mainloop()
