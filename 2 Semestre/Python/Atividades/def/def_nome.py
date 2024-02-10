def listar_nome(nome):
    print(f"Olá, {nome}!")


def escrever_nome():
    nome = str(input("Qual seu nome? "))
    listar_nome(nome)

escrever_nome()