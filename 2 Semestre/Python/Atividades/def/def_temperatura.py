def conversor(celsius):
    formula = (celsius * 9/5) + 32
    print(f"A conversão de {celsius} graus celsius para Fahrenheit é de {formula} ")

userInput = int(input("Digite uma temperatura: "))
conversor(userInput)