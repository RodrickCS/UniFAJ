import tkinter as tk

class ContaBancaria:
    def __init__(self, nome, saldo=0):
        self.nome = nome
        self.saldo = saldo

    def depositar(self, valor):
        self.saldo += valor
        return self.saldo

    def sacar(self, valor):
        if self.saldo >= valor:
            self.saldo -= valor
            return self.saldo
        else:
            print("Saldo insuficiente.")
            return None

    def verificar_saldo(self):
        return self.saldo

def depositar():
    valor = float(entry_valor.get())
    conta.depositar(valor)
    atualizar_saldo()

def sacar():
    valor = float(entry_valor.get())
    conta.sacar(valor)
    atualizar_saldo()

def atualizar_saldo():
    label_saldo.config(text=f"Saldo: R$ {conta.verificar_saldo()}")

conta = ContaBancaria("João", 1000)

root = tk.Tk()
root.title("Conta Bancária")

label_saldo = tk.Label(root, text=f"Saldo: R$ {conta.verificar_saldo()}")
label_saldo.pack(pady=10)

entry_valor = tk.Entry(root)
entry_valor.pack(pady=10)

botao_depositar = tk.Button(root, text="Depositar", command=depositar)
botao_depositar.pack()

botao_sacar = tk.Button(root, text="Sacar", command=sacar)
botao_sacar.pack()

root.mainloop()
