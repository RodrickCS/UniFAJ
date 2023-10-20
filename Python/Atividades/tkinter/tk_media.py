import tkinter as tk
from tkinter import *


def calcular_media():
    pri = primeiro_numero_entry.get()
    seg = segundo_numero_entry.get()
    ter = terceiro_numero_entry.get()
    if pri.isdigit() and seg.isdigit() and ter.isdigit() :
        soma = float(pri) + float(seg) + float(ter)
        media = round(soma / 3, 2)
        resultado_label.configure(text=f"sua média é {media}")
    else:
        resultado_label.configure(text="Digite apenas números")
    

janela_principal = tk.Tk()
janela_principal.title("Media")
janela_principal.geometry("300x300")

janela_principal.columnconfigure(0, weight=1)
janela_principal.columnconfigure(1, weight=1)

primeiro_numero_label = Label(janela_principal, text="Primeiro Numero")
primeiro_numero_label.grid(column=0, row=1)

primeiro_numero_entry = Entry(janela_principal)
primeiro_numero_entry.grid(column=1, row=1)

segundo_numero_label = Label(janela_principal, text="Segundo Numero")
segundo_numero_label.grid(column=0, row=2)

segundo_numero_entry = Entry(janela_principal)
segundo_numero_entry.grid(column=1, row=2)

terceiro_numero_label = Label(janela_principal, text="Terceiro Numero")
terceiro_numero_label.grid(column=0, row=3)

terceiro_numero_entry = Entry(janela_principal)
terceiro_numero_entry.grid(column=1, row=3)

resultado_label = Label(janela_principal, text="")
resultado_label.grid(column=1, row=5)

button_calcular = Button(janela_principal, text="Calcular", command=calcular_media)
button_calcular.grid(column=0, row=4)

janela_principal.mainloop()
