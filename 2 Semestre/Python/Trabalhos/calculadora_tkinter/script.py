import tkinter as tk

def atualizar_visor(valor):
    visor_var.set(visor_var.get() + str(valor))

def calcular():
    try:
        resultado = eval(visor_var.get())
        visor_var.set(resultado)
    except Exception as e:
        visor_var.set("Erro")

def limpar():
    visor_var.set("")

janela = tk.Tk()
janela.title("Calculadora")

visor_var = tk.StringVar()
visor_var.set("")

visor = tk.Entry(janela, textvariable=visor_var, font=("Arial", 18))
visor.grid(row=0, column=0, columnspan=4)

botoes = [
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    '0', '.', '=', '+'
]

row_val = 1
col_val = 0

for botao in botoes:
    tk.Button(janela, text=botao, padx=20, pady=20, font=("Arial", 14), command=lambda valor=botao: atualizar_visor(valor)).grid(row=row_val, column=col_val)
    col_val += 1
    if col_val > 3:
        col_val = 0
        row_val += 1

tk.Button(janela, text="C", padx=20, pady=20, font=("Arial", 14), command=limpar).grid(row=row_val, column=col_val)

tk.Button(janela, text="=", padx=20, pady=20, font=("Arial", 14), command=calcular).grid(row=row_val, column=col_val + 1)

janela.mainloop()
