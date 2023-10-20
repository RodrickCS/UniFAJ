import tkinter as tk
from tkinter import *


def converter():
    celcius = numero_celcius.get()
    if celcius.isdigit():
        conversor = (float(celcius) * 9 // 5) + 32
        resultado_label.configure(text=f"{celcius}C° para Fahrenheit é {conversor}")
    else:
        resultado_label.configure(text=f"Ultilize apenas números")
        
    
janela_principal = tk.Tk()
janela_principal.title("Celcius para Fahrenheit")
janela_principal.geometry("330x150")

janela_principal.columnconfigure(0, weight=1)
janela_principal.columnconfigure(1, weight=1)

numero_celcius = Label(janela_principal, text="Digite uma temperatura em C°")
numero_celcius.grid(column=0, row=1)

numero_celcius = Entry(janela_principal)
numero_celcius.grid(column=1, row=1)

button_calcular = Button(janela_principal, text="Calcular", command=converter)
button_calcular.grid(column=0, row=2)

resultado_label = Label(janela_principal, text="")
resultado_label.grid(column=1, row=2)

janela_principal.mainloop()
