import tkinter as tk

class ContaBancaria:
    def __init__(self, nome, saldo=0):
        self.nome = nome
        self.saldo = saldo

    def depositar(self, valor):
        self.saldo += valor
        return self.saldo

    def verificar_saldo(self):
        return self.saldo

class ContaCorrente(ContaBancaria):
    def __init__(self, nome, saldo=0, limite_credito=0):
        super().__init__(nome, saldo)
        self.limite_credito = limite_credito

    def sacar(self, valor):
        if self.saldo >= valor:
            self.saldo -= valor
            return self.saldo
        elif self.limite_credito >= valor:
            self.limite_credito -= valor
            self.saldo -= valor
            return self.saldo
        else:
            print("Saldo insuficiente e limite de crédito excedido.")
            return None

    def verificar_limite_credito(self):
        return self.limite_credito

def depositar():
    valor = float(entry_valor.get())
    conta_corrente.depositar(valor)
    atualizar_saldo_limite()

def sacar():
    valor = float(entry_valor.get())
    conta_corrente.sacar(valor)
    atualizar_saldo_limite()

def atualizar_saldo_limite():
    label_saldo.config(text=f"Saldo: R$ {conta_corrente.verificar_saldo()}")
    label_limite_credito.config(text=f"Limite de Crédito: R$ {conta_corrente.verificar_limite_credito()}")

conta_corrente = ContaCorrente("Maria", 10, 2000)

# Criar janela
root = tk.Tk()
root.title("Conta Corrente")

label_saldo = tk.Label(root, text=f"Saldo: R$ {conta_corrente.verificar_saldo()}")
label_saldo.pack(pady=10)

label_limite_credito = tk.Label(root, text=f"Limite de Crédito: R$ {conta_corrente.verificar_limite_credito()}")
label_limite_credito.pack(pady=10)

entry_valor = tk.Entry(root)
entry_valor.pack(pady=10)

botao_depositar = tk.Button(root, text="Depositar", command=depositar)
botao_depositar.pack()

botao_sacar = tk.Button(root, text="Sacar", command=sacar)
botao_sacar.pack()

root.mainloop()
