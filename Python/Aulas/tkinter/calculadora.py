import tkinter as tk
from tkinter import simpledialog


def calcular_media():
    numero1 = simpledialog.askfloat("Digite os números", "Digite o primeiro número")
    numero2 = simpledialog.askfloat("Digite os números", "Digite o segundo número")

    if numero1 is not None and numero2 is not None:
        media = (numero1 + numero2) / 2
        resultado_label.config(text=f"A media dos numeros é: {media:.2f}")

    else:
        resultado_label.config(text="Preencha ambos os números")


janela = tk.Tk()
janela.title("Calculadora de média")
resultado_label = tk.Label(janela, text="")
resultado_label.pack(padx=20, pady=20)


botao = tk.Button(janela, text="Calcular", command=calcular_media)
botao.pack(padx=12, pady=12)


janela.mainloop()
