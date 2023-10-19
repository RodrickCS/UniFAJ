numero = int(input("Digite um número: "))
fatorial = 1
contador = 1

while contador <= numero:
    fatorial *= numero
    contador += 1
print(f"O valor será: {fatorial}")
