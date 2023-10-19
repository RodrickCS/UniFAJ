import tkinter as tk


def mostrar_mensagem():
    mensagem.config(text="Clicou")


janela = tk.Tk()

janela.title("Exemplo")

mensagem = tk.Label(janela, text="Clique no botão")
# mensagem.grid(column=0, row=0)
mensagem.pack(padx=20, pady=20)

botao = tk.Button(janela, text="Clique aqui", command=mostrar_mensagem)
botao.pack(padx=25, pady=25)

janela.mainloop()
