limite = int(input("Digite um limite: "))
a = 0
b = 1

while a <= limite:
    print(a, end="")  # função end mantém os números na mesma linha
    a, b = b, a + b
