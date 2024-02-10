import tkinter as tk

class Livro:
    def __init__(self, titulo, autor, ano):
        self.titulo = titulo
        self.autor = autor
        self.ano = ano

    def retornar_livro(self):
        objeto = {
            "Título": self.titulo,
            "Autor": self.autor,
            "Publicação": self.ano
        }
        return objeto

def exibir_livro():
    info_livro = livro.retornar_livro()
    texto = f"Título: {info_livro['Título']}\nAutor: {info_livro['Autor']}\nPublicação: {info_livro['Publicação']}"
    label_info_livro.config(text=texto)

livro = Livro('Dom Casmurro', 'Machado de Assis', 1899)

root = tk.Tk()
root.title("Informações do Livro")

label_info_livro = tk.Label(root, text="")
label_info_livro.pack(pady=10)

botao_exibir_livro = tk.Button(root, text="Exibir Informações do Livro", command=exibir_livro)
botao_exibir_livro.pack()

root.mainloop()
