import tkinter as tk
from tkinter import *
import csv

def obter_proximo_id():
    try:
        with open("usuarios.csv", "r", encoding="UTF8") as f:
            reader = csv.reader(f)
            ids = [int(row[0]) for row in reader if len(row) >= 1]
            if ids:
                return max(ids) + 1
            else:
                return 1
    except Exception as e:
        print("Ocorreu um erro ao obter o próximo ID:", str(e))
        return None

def escrever_usuario_csv():
    try:
        with open("usuarios.csv", "a", encoding="UTF8", newline="") as f:
            writer = csv.writer(f)
            nome = nome_label_field.get()
            email = email_label_field.get()
            proximo_id = obter_proximo_id()
            if proximo_id is not None:
                writer.writerow([proximo_id, nome, email])  # Escreve o ID na primeira posição
                label_informacao.configure(text=f"Usuário escrito com sucesso no arquivo 'usuarios.csv' com ID: {proximo_id}")
            else:
                print("Não foi possível obter o próximo ID.")
    except Exception as e:
        print("Ocorreu um erro:", str(e))

def pesquisar_usuario():
    try:
        termo_pesquisa = termo_pesquisa_field.get()
        campo_pesquisa = campo_pesquisa_var.get()
        
        with open("usuarios.csv", "r", encoding="UTF8") as f:
            reader = csv.reader(f)
            encontrado = False
            for row in reader:
                if len(row) >= 3:
                    if campo_pesquisa == "Nome" and termo_pesquisa.lower() == row[1].lower():
                        label_informacao.configure(text=f"Código: {row[0]}, Nome: {row[1]}, Email: {row[2]}")
                        encontrado = True
                    elif campo_pesquisa == "Email" and termo_pesquisa.lower() == row[2].lower():
                        label_informacao.configure(text=f"Código: {row[0]}, Nome: {row[1]}, Email: {row[2]}")
                        encontrado = True
            
            if not encontrado:
                label_informacao.configure(text=f"Nenhum usuário encontrado com o nome fornecido.")
    except Exception as e:
        print("Ocorreu um erro:", str(e))

janela_principal = tk.Tk()
janela_principal.title("APSI")
janela_principal.geometry("400x300")

janela_principal.columnconfigure(0, weight=1)
janela_principal.columnconfigure(1, weight=1)

nome_label = Label(janela_principal, text="Nome:")
nome_label.grid(column=0, row=1)

nome_label_field = Entry()
nome_label_field.grid(column=1, row=1)

email_label = Label(janela_principal, text="Email:")
email_label.grid(column=0, row=2)

email_label_field = Entry()
email_label_field.grid(column=1, row=2)

botao_cadastrar = Button(janela_principal, text="Clique para cadastrar", command=escrever_usuario_csv)
botao_cadastrar.grid(column=1, row=3)

termo_pesquisa_label = Label(janela_principal, text="Termo de Pesquisa:")
termo_pesquisa_label.grid(column=0, row=5)

termo_pesquisa_field = Entry()
termo_pesquisa_field.grid(column=1, row=4)

campo_pesquisa_label = Label(janela_principal, text="Campo de Pesquisa:")
campo_pesquisa_label.grid(column=0, row=4)

campo_pesquisa_var = StringVar(janela_principal)
campo_pesquisa_var.set("Nome")  # Valor padrão
campo_pesquisa_menu = OptionMenu(janela_principal, campo_pesquisa_var, "Nome", "Email")
campo_pesquisa_menu.grid(column=1, row=5)

botao_pesquisar = Button(janela_principal, text="Pesquisar", command=pesquisar_usuario)
botao_pesquisar.grid(column=1, row=6)

label_informacao = Label(janela_principal, text="")
label_informacao.grid(column=0, row=7)

janela_principal.mainloop()
