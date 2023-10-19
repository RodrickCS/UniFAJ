lista = []


def calcular_media():
    i = 0
    soma = 0
    media = 0
    tamanho = len(lista)
    while i < tamanho:
        soma = soma + lista[i]
        i += 1
    media = soma / tamanho
    return media


def inserir_numeros():
    i = 0
    while i < 5:
        numero = int(input("Insira um número: "))
        lista.append(numero)
        i += 1


def executar():
    inserir_numeros()
    media = calcular_media()
    print(f"Sua média é {media}")


executar()
