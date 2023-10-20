import tkinter as tk
from tkinter import *


def localizar():
    input = int(numero_entry.get())
    for i in range(input):
        if i % 2 != 0:
            resultado_label.configure(text=i)   

    
janela_principal = tk.Tk()
janela_principal.title("Localizar impares")
janela_principal.geometry("330x150")

janela_principal.columnconfigure(0, weight=1)
janela_principal.columnconfigure(1, weight=1)

numero_label = Label(janela_principal, text="Digite um número")
numero_label.grid(column=0, row=1)

numero_entry = Entry(janela_principal)
numero_entry.grid(column=1, row=1)

button_calcular = Button(janela_principal, text="Calcular", command=localizar)
button_calcular.grid(column=0, row=2)

resultado_label = Label(janela_principal, text="")
resultado_label.grid(column=1, row=2)

janela_principal.mainloop()
