def localizar_pares(numero):
    if numero % 2 == 0:
        for numeros in range(0, numero, 2):
            print(numeros)
    else:
        print("Numero par por favor")
        digitar_numero()


def digitar_numero():
    n = int(input("Digite um número inteiro positivo: "))
    localizar_pares(n)

digitar_numero()