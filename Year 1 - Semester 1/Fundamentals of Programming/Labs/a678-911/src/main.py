from src.repository.BookRepository import BookRepository
from src.repository.ClientRepository import ClientRepository
from src.repository.RentalRepository import RentalRepository
from src.repository.BookFileRepository import BookFileRepository
from src.repository.ClientFileRepository import ClientFileRepository
from src.repository.RentalFileRepository import RentalFileRepository
from src.repository.BookBinaryRepository import BookBinaryRepository
from src.repository.ClientBinaryRepository import ClientBinaryRepository
from src.repository.RentalBinaryRepository import RentalBinaryRepository
from src.repository.HistoryOperationsRepository import OperationsHistory
from src.ui.UI import UI
from src.gui.LibraryX import GUI


with open("files/settings.properties", "r") as file:
    repo_type = file.readline().strip().casefold().split()[2]

    book_repo = file.readline().strip().split()[2]
    book_repo = book_repo[1:len(book_repo)-1]

    client_repo = file.readline().strip().split()[2]
    client_repo = client_repo[1:len(client_repo)-1]

    rental_repo = file.readline().strip().split()[2]
    rental_repo = rental_repo[1:len(rental_repo)-1]

    start_method = file.readline().strip().casefold().split()[2]


Operations_History_Repo = OperationsHistory()

if repo_type == "inmemmory":
    Book_Repo = BookRepository()
    Client_Repo = ClientRepository()
    Rental_Repo = RentalRepository()
    Book_Repo.generate_books()
    Client_Repo.generate_clients()
    Rental_Repo.generate_rentals(Client_Repo, Book_Repo)
elif repo_type == "textfiles":
    Book_Repo = BookFileRepository(book_repo)
    Client_Repo = ClientFileRepository(client_repo)
    Rental_Repo = RentalFileRepository(rental_repo)
    Book_Repo.read_file()
    Client_Repo.read_file()
    Rental_Repo.read_file()
elif repo_type == "binaryfiles":
    Book_Repo = BookBinaryRepository(book_repo)
    Client_Repo = ClientBinaryRepository(client_repo)
    Rental_Repo = RentalBinaryRepository(rental_repo)
    Book_Repo.read_file()
    Client_Repo.read_file()
    Rental_Repo.read_file()
if start_method == "ui":
    start1 = UI(Book_Repo, Client_Repo, Rental_Repo, Operations_History_Repo)
    start1.start()
elif start_method == "gui":
    from tkinter import *
    root = Tk()
    start2 = GUI(root, Book_Repo, Client_Repo, Rental_Repo, Operations_History_Repo)
    start2.start()
    root.mainloop()

if repo_type == "textfiles":
    Book_Repo.save_file()
    Client_Repo.save_file()
    Rental_Repo.save_file()
elif repo_type == "binaryfiles":
    Book_Repo.save_file()
    Client_Repo.save_file()
    Rental_Repo.save_file()
