import random

randNumber = random.randint(0, 10)

userInput = int(input("Digite um número entre 0 a 10: "))

if userInput == randNumber:
    print(f"Acertou!, o número é {randNumber} :)")
else:
    print(f"Errou, o número era {randNumber} :(")
