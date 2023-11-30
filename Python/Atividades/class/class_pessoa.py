import tkinter as tk

class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def retornar_pessoa(self):
        objeto = {
            "Nome": self.nome,
            "Idade": self.idade
        }
        return objeto

def exibir_pessoa():
    info_pessoa = pessoa.retornar_pessoa()
    texto = f"Nome: {info_pessoa['Nome']}\nIdade: {info_pessoa['Idade']}"
    label_info_pessoa.config(text=texto)

pessoa = Pessoa("João", 31)

root = tk.Tk()
root.title("Informações da Pessoa")

label_info_pessoa = tk.Label(root, text="")
label_info_pessoa.pack(pady=10)

botao_exibir_pessoa = tk.Button(root, text="Exibir Informações da Pessoa", command=exibir_pessoa)
botao_exibir_pessoa.pack()

root.mainloop()
