from src.services.BookServices import BookServices
from src.services.ClientServices import ClientServices
from src.services.RentalServices import RentalServices
from src.domain.BookValidator import BookValidator
from src.domain.ClientValidator import ClientValidator
from src.domain.RentalValidator import RentalValidator

class UI():
    def __init__(self, book_repo, client_repo, rental_repo, operations_history):
        self.__undo_redo_service = operations_history
        self.__book_repo = book_repo
        self.__client_repo = client_repo
        self.__rental_repo = rental_repo
        self.__rental_services = RentalServices(self.__book_repo, self.__client_repo, self.__rental_repo, RentalValidator(), self.__undo_redo_service)
        self.__book_services = BookServices(self.__book_repo, BookValidator(), self.__rental_services, self.__undo_redo_service)
        self.__client_services = ClientServices(self.__client_repo, ClientValidator(), self.__rental_services, self.__undo_redo_service)


    @staticmethod
    def __menu():
        print("1) Books")
        print("2) Clients")
        print("3) Rentals")
        print("4) Statistics")
        print("5) Undo")
        print("6) Redo")
        print("7) Exit")


    @staticmethod
    def __books_menu():
        print("a) Add\n"
              "b) Remove\n"
              "c) Update\n"
              "d) List\n"
              "e) Filter\n"
              "f) Exit\n")


    @staticmethod
    def __clients_menu():
        print("a) Add\n"
              "b) Remove\n"
              "c) Update\n"
              "d) List\n"
              "e) Filter\n"
              "f) Exit")


    @staticmethod
    def __rentals_menu():
        print("a) Rent\n"
              "b) Return\n"
              "c) List\n"
              "d) Exit\n")


    @staticmethod
    def __statistics_menu():
        print("a) Most rented books\n"
              "b) Most active clients\n"
              "c) Most rented authors\n"
              "d) Exit\n")


    def __add_book_ui(self):
        try:
            book_id = input("book id = ").upper().strip()
            book_title = input("book title = ").upper().strip()
            book_author = input("book author = ").upper().strip()
            self.__book_services.add_book_service(book_id, book_title, book_author)
        except Exception as e:
            print(e)


    def __remove_book_ui(self):
        try:
            book_id = input("book id = ").upper().strip()
            book_title = input("book title = ").upper().strip()
            book_author = input("book author = ").upper().strip()
            self.__book_services.remove_book_service(book_id, book_title, book_author)
        except Exception as e:
            print(e)


    def __update_book_ui(self):
        try:
            old_book_id = input("old book id = ").upper().strip()
            old_book_title = input("old book title = ").upper().strip()
            old_book_author = input("old book author = ").upper().strip()
            new_book_title = input("new book title = ").upper().strip()
            new_book_author = input("new book author = ").upper().strip()
            self.__book_services.update_book_service(old_book_id, old_book_title, old_book_author, new_book_title, new_book_author)
        except Exception as e:
            print(e)


    def __list_books_ui(self):
        try:
            books = self.__book_services.list_books_service()
            for book in books:
                print(book)
        except Exception as e:
            print(e)


    def __filter_books_ui(self):
        try:
            book_id = input("book id = ").upper().strip()
            book_title = input("book title = ").upper().strip()
            book_author = input("book author = ").upper().strip()
            if book_id == "": book_id = None
            if book_title == "":book_title = None
            if book_author == "":book_author = None
            books = self.__book_services.filter_books_service(book_id, book_title, book_author)
            for book in books:
                print(book)
        except Exception as e:
            print(e)


    def __add_client_ui(self):
        try:
            client_id = input("client id = ").upper().strip()
            client_name = input("client name = ").upper().strip()
            self.__client_services.add_client_service(client_id, client_name)
        except Exception as e:
            print(e)


    def __remove_client_ui(self):
        try:
            client_id = input("client id = ").upper().strip()
            client_name = input("client name = ").upper().strip()
            self.__client_services.remove_client_service(client_id, client_name)
        except Exception as e:
            print(e)


    def __update_client_ui(self):
        try:
            old_client_id = input("old client id = ").upper().strip()
            old_client_name = input("old client name = ").upper().strip()
            new_client_name = input("new client name = ").upper().strip()
            self.__client_services.update_client_service(old_client_id, old_client_name, new_client_name)
        except Exception as e:
            print(e)


    def __list_clients_ui(self):
        try:
            clients = self.__client_services.list_clients_service()
            for client in clients:
                print(client)
        except Exception as e:
            print(e)


    def __filter_clients_ui(self):
        try:
            client_id = input("client id = ").upper().strip()
            client_name = input("client name = ").upper().strip()
            if client_id == "":client_id = None
            if client_name == "":client_name = None
            clients = self.__client_services.filter_clients_service(client_id, client_name)
            for client in clients:
                print(client)
        except Exception as e:
            print(e)


    def __rent_book_ui(self):
        try:
            rental_id = input("rental id = ").upper().strip()
            book_id = input("book id = ").upper().strip()
            client_id = input("client id = ").upper().strip()
            rented_date = input("rented date = ").upper().strip()
            self.__rental_services.rent_book_service(rental_id, book_id, client_id, rented_date)
        except Exception as e:
            print(e)


    def __return_book_ui(self):
        try:
            rental_id = input("rental id = ").upper().strip()
            book_id = input("book id = ").upper().strip()
            client_id = input("client id = ").upper().strip()
            rented_date = input("rented date = ").upper().strip()
            returned_date = input("returned date = ").upper().strip()
            self.__rental_services.return_book_service(rental_id, book_id, client_id, rented_date, returned_date)
        except Exception as e:
            print(e)


    def __list_rentals_ui(self):
        try:
            rentals = self.__rental_services.list_rentals_service()
            for rental in rentals:
                print(rental)
        except Exception as e:
            print(e)


    def __most_rented_books_ui(self):
        try:
            books = self.__rental_services.most_rented_books()
            for book in books:
                print(book)
        except Exception as e:
            print(e)


    def __most_active_clients_ui(self):
        try:
            clients = self.__rental_services.most_active_clients()
            for client in clients:
                print(client)
        except Exception as e:
            print(e)


    def __most_rented_authors_ui(self):
        try:
            authors = self.__rental_services.most_rented_authors()
            for author in authors:
                print(author)
        except Exception as e:
            print(e)


    def __books_start(self):
        while True:
            self.__books_menu()
            option = input("option = ").lower().strip()
            if option == "a":
                self.__add_book_ui()
            elif option == "b":
                self.__remove_book_ui()
            elif option == "c":
                self.__update_book_ui()
            elif option == "d":
                self.__list_books_ui()
            elif option == "e":
                self.__filter_books_ui()
            elif option == "f":
                return
            else:
                print("Bad command!")



    def __clients_start(self):
        while True:
            self.__clients_menu()
            option = input("option = ").lower().strip()
            if option == "a":
                self.__add_client_ui()
            elif option == "b":
                self.__remove_client_ui()
            elif option == "c":
                self.__update_client_ui()
            elif option == "d":
                self.__list_clients_ui()
            elif option == "e":
                self.__filter_clients_ui()
            elif option == "f":
                return
            else:
                print("Bad command!")


    def __rentals_start(self):
        while True:
            self.__rentals_menu()
            option = input("option = ").lower().strip()
            if option == "a":
                self.__rent_book_ui()
            elif option == "b":
                self.__return_book_ui()
            elif option == "c":
                self.__list_rentals_ui()
            elif option == "d":
                return
            else:
                print("Bad command!")


    def __statistics_start(self):
        while True:
            self.__statistics_menu()
            option = input("option = ").lower().strip()
            if option == "a":
                self.__most_rented_books_ui()
            elif option == "b":
                self.__most_active_clients_ui()
            elif option == "c":
                self.__most_rented_authors_ui()
            elif option == "d":
                return
            else:
                print("Bad command!")


    def start(self):

        while True:
            self.__menu()
            option = input("option = ").lower().strip()
            if option == "1":
                self.__books_start()
            elif option == "2":
                self.__clients_start()
            elif option == "3":
                self.__rentals_start()
            elif option == "4":
                self.__statistics_start()
            elif option == "5":
                try:
                    self.__undo_redo_service.undo()
                except Exception as e:
                    print(e)
            elif option == "6":
                try:
                    self.__undo_redo_service.redo()
                except Exception as e:
                    print(e)
            elif option == "7":
                break
            else:
                print("Bad command!")
