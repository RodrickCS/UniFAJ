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

def abrir_janela_pesquisa():
    janela_pesquisa = tk.Toplevel(janela_principal)
    janela_pesquisa.title("Pesquisar Usuários")
    janela_pesquisa.geometry("400x200")

    termo_pesquisa_label = Label(janela_pesquisa, text="Termo de Pesquisa:")
    termo_pesquisa_label.grid(column=0, row=0)

    termo_pesquisa_field = Entry(janela_pesquisa)
    termo_pesquisa_field.grid(column=1, row=0)

    campo_pesquisa_label = Label(janela_pesquisa, text="Campo de Pesquisa:")
    campo_pesquisa_label.grid(column=0, row=1)

    campo_pesquisa_var = StringVar(janela_pesquisa)
    campo_pesquisa_var.set("Nome")  # Valor padrão
    campo_pesquisa_menu = OptionMenu(janela_pesquisa, campo_pesquisa_var, "Nome", "Email")
    campo_pesquisa_menu.grid(column=1, row=1)

    botao_pesquisar = Button(janela_pesquisa, text="Pesquisar", command=lambda: pesquisar_usuario(termo_pesquisa_field.get(), campo_pesquisa_var.get()))
    botao_pesquisar.grid(column=1, row=2)

    janela_pesquisa.mainloop()

def pesquisar_usuario(termo_pesquisa, campo_pesquisa):
    try:
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

def abrir_pagina_edicao():
    pagina_edicao = tk.Toplevel(janela_principal)
    pagina_edicao.title("Editar Usuários")
    pagina_edicao.geometry("400x300")

    codigo_label = Label(pagina_edicao, text="Código do Usuário:")
    codigo_label.grid(column=0, row=0)

    codigo_field = Entry(pagina_edicao)
    codigo_field.grid(column=1, row=0)

    botao_editar = Button(pagina_edicao, text="Editar Usuário", command=lambda: abrir_janela_edicao(codigo_field.get()))
    botao_editar.grid(column=1, row=1)

    pagina_edicao.mainloop()

def abrir_janela_edicao(codigo):
    try:
        codigo_editar = codigo
        with open("usuarios.csv", "r", encoding="UTF8") as f:
            reader = csv.reader(f)
            encontrado = False
            for row in reader:
                if len(row) >= 3 and row[0] == codigo_editar:
                    janela_edicao = tk.Toplevel(janela_principal)
                    janela_edicao.title("Editar Usuário")
                    janela_edicao.geometry("400x200")

                    nome_label = Label(janela_edicao, text="Nome:")
                    nome_label.grid(column=0, row=0)

                    nome_field = Entry(janela_edicao)
                    nome_field.grid(column=1, row=0)
                    nome_field.insert(0, row[1])

                    email_label = Label(janela_edicao, text="Email:")
                    email_label.grid(column=0, row=1)

                    email_field = Entry(janela_edicao)
                    email_field.grid(column=1, row=1)
                    email_field.insert(0, row[2])

                    botao_salvar = Button(janela_edicao, text="Salvar", command=lambda: salvar_edicao(codigo_editar, nome_field.get(), email_field.get()))
                    botao_salvar.grid(column=1, row=2)

                    encontrado = True
                    break

            if not encontrado:
                label_informacao.configure(text="Nenhum usuário encontrado com o código fornecido.")
    except Exception as e:
        print("Ocorreu um erro:", str(e))

def salvar_edicao(codigo, novo_nome, novo_email):
    try:
        linhas = []
        with open("usuarios.csv", "r", encoding="UTF8") as f:
            reader = csv.reader(f)
            for row in reader:
                if len(row) >= 3 and row[0] == codigo:
                    row[1] = novo_nome
                    row[2] = novo_email
                linhas.append(row)

        with open("usuarios.csv", "w", encoding="UTF8", newline="") as f:
            writer = csv.writer(f)
            writer.writerows(linhas)

        label_informacao.configure(text="Usuário editado com sucesso.")
    except Exception as e:
        print("Ocorreu um erro:", str(e))

# Configuração da janela principal
janela_principal = tk.Tk()
janela_principal.title("APSI")
janela_principal.geometry("400x300")

janela_principal.columnconfigure(0, weight=1)
janela_principal.columnconfigure(1, weight=1)

nome_label = Label(janela_principal, text="Nome:")
nome_label.grid(column=0, row=1)

nome_label_field = Entry(janela_principal)
nome_label_field.grid(column=1, row=1)

email_label = Label(janela_principal, text="Email:")
email_label.grid(column=0, row=2)

email_label_field = Entry(janela_principal)
email_label_field.grid(column=1, row=2)

botao_cadastrar = Button(janela_principal, text="Clique para cadastrar", command=escrever_usuario_csv)
botao_cadastrar.grid(column=1, row=3)

botao_abrir_pagina_edicao = Button(janela_principal, text="Editar Usuários", command=abrir_pagina_edicao)
botao_abrir_pagina_edicao.grid(column=1, row=4)

botao_pesquisar = Button(janela_principal, text="Pesquisar Usuários", command=abrir_janela_pesquisa)
botao_pesquisar.grid(column=1, row=5)

label_informacao = Label(janela_principal, text="")
label_informacao.grid(column=0, row=6)

janela_principal.mainloop()
