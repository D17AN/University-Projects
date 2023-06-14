from src.services.BookServices import BookServices
from src.services.ClientServices import ClientServices
from src.services.RentalServices import RentalServices
from src.domain.BookValidator import BookValidator
from src.domain.ClientValidator import ClientValidator
from src.domain.RentalValidator import RentalValidator
from tkinter import *
from tkinter import ttk, messagebox

class GUI:
    def __init__(self, master, book_repo, client_repo, rental_repo, operations_history):
        # Conection with the services and repo
        self.__undo_redo_service = operations_history
        self.__book_repo = book_repo
        self.__client_repo = client_repo
        self.__rental_repo = rental_repo
        self.__rental_services = RentalServices(self.__book_repo, self.__client_repo, self.__rental_repo,
                                                RentalValidator(), self.__undo_redo_service)
        self.__book_services = BookServices(self.__book_repo, BookValidator(), self.__rental_services,
                                            self.__undo_redo_service)
        self.__client_services = ClientServices(self.__client_repo, ClientValidator(), self.__rental_services,
                                                self.__undo_redo_service)

        #GUI PART
        self.root = master
        self.root.title("LibraryX")

        #Notebook
        self.notebook = ttk.Notebook(master)
        self.notebook.grid()

        self.frame1 = Frame(self.notebook, width = 500, height = 300, bg = "white")
        self.frame1.grid()
        self.notebook.add(self.frame1, text = "Main Menu")

        self.frame2 = Frame(self.notebook, width = 500, height = 300, bg = "white")
        self.frame2.grid()
        self.notebook.add(self.frame2, text = "Books Services")

        self.frame3 = Frame(self.notebook, width=500, height=300, bg="white")
        self.frame3.grid()
        self.notebook.add(self.frame3, text = "Client Services")

        self.frame4 = Frame(self.notebook, width=500, height=300, bg="white")
        self.frame4.grid()
        self.notebook.add(self.frame4, text="Rental Services")


    """ Book GUI implementation """
    def books_view_tree(self, data):
        """
        :param data: a list of list which contains the data for the view tree. each list from an index has a: book id, book name, book author
        :return: a view tree
        """
        level1 = Toplevel()
        level1.geometry("500x400")

        # create a tree
        my_tree = ttk.Treeview(level1)
        my_tree['columns'] = ("BOOK ID", "BOOK NAME", "BOOK AUTHOR")

        # create columns
        my_tree.column("#0", width = 0, stretch = NO)
        my_tree.column("BOOK ID", anchor = W, width = 100)
        my_tree.column("BOOK NAME", anchor = CENTER, width = 200)
        my_tree.column("BOOK AUTHOR", anchor = E, width = 160)

        # create headings
        my_tree.heading("#0", text = "", anchor = W)
        my_tree.heading("BOOK ID", text = "ID", anchor = W)
        my_tree.heading("BOOK NAME", text="BOOK NAME", anchor=W)
        my_tree.heading("BOOK AUTHOR", text="BOOK AUTHOR", anchor=W)
        # grid to the the screen
        my_tree.grid()
        for index, el in enumerate(data):
            my_tree.insert(parent='', index='end', iid=index, values=(el.book_id, el.book_title, el.book_author))

        # adding a scroll bar to the tree
        scrollbar = Scrollbar(level1, orient=VERTICAL, command=lambda: my_tree.yview)
        my_tree.configure(yscroll=scrollbar.set)
        scrollbar.grid(row=0, column=1, sticky='ns')

        close_button = Button(level1, text = "Close", command = lambda: level1.destroy())
        close_button.grid(column=1, row = 12)


    def add_book_gui(self, book_id, book_title, book_author):
        try:
            if "" not in (book_id.get().strip(), book_title.get().strip(), book_author.get().strip()):
                self.__book_services.add_book_service(book_id.get().strip().upper(), book_title.get().strip().upper(),
                                                    book_author.get().strip().upper())
                messagebox.showinfo("info", "Book added succesfully!")
        except Exception as e:
            messagebox.showerror("error", e)


    def add_book_button(self, book_id, book_title, book_author):
        add_button = Button(self.frame2, text="Add", command=lambda: self.add_book_gui(book_id, book_title, book_author))
        add_button.grid(column = 7, row = 0)


    def remove_book_gui(self, book_id, book_title, book_author):
        try:
            if "" not in (book_id.get().strip(), book_title.get().strip(), book_author.get().strip()):
                self.__book_services.remove_book_service(book_id.get().strip().upper(), book_title.get().strip().upper(),
                                                    book_author.get().strip().upper())
                messagebox.showinfo("info", "Book removed succesfully!")
        except Exception as e:
            messagebox.showerror("error", e)


    def remove_book_button(self, book_id, book_title, book_author):
        remove_button = Button(self.frame2, text = "Remove", command = lambda: self.remove_book_gui( book_id, book_title, book_author))
        remove_button.grid(column = 8, row = 0)



    def update_book_gui2(self, top, old_book_id, old_book_title, old_book_author, new_book_title, new_book_author):
        try:
            if "" not in (new_book_title.get().strip(), new_book_author.get().strip()):
                self.__book_services.update_book_service(old_book_id.get().strip().upper(),
                                                         old_book_title.get().strip().upper(),
                                                         old_book_author.get().strip().upper(),
                                                         new_book_title.get().strip().upper(),
                                                         new_book_author.get().strip().upper())
            top.destroy()
        except Exception as e:
            messagebox.showerror("error", e)
        else:
            messagebox.showinfo("info", "Book updated succesfully!")




    def update_book_gui1(self, old_book_id, old_book_title, old_book_author):
        """
        Entries and input boxex for the new parameters of a book
        :param old_book_id: the old book id entry of the book
        :param old_book_title: the old book title entry of the book
        :param old_book_author: the old book author entry of the book
        """
        try:
            if "" not in(old_book_id.get().strip(), old_book_title.get().strip(), old_book_author.get().strip()):
                top = Toplevel()
                top.grid()
                # new book title entry
                new_book_title_label = Label(top, text="NEW BOOK TITLE: ", bg="white", fg="blue", font=("ARIAL", 15))
                new_book_title_label.grid(column=0, row=0)
                new_book_title = Entry(top, width=30, bd=2)
                new_book_title.grid(column=1, row=0)

                # new book author entry
                new_book_author_label = Label(top, text="NEW BOOK AUTHOR: ", bg="white", fg="blue", font=("ARIAL", 15))
                new_book_author_label.grid(column=0, row=1)
                new_book_author = Entry(top, width=30, bd=2)
                new_book_author.grid(column=1, row=1)

                confirm_button = Button(top, text="Confirm", command = lambda: self.update_book_gui2(top, old_book_id, old_book_title,
                                                                                                    old_book_author, new_book_title,
                                                                                                     new_book_author)).grid(column=1, row=2)
        except Exception as e:
            messagebox.showerror("error", e)


    def update_book_button(self, book_id, book_title, book_author):
        """
        :param book_id: book id entry of a book
        :param book_title: book title entry of a book
        :param book_author: book author entry of a book
        """
        update_button = Button(self.frame2, text = "Update", command = lambda: self.update_book_gui1(book_id, book_title, book_author))
        update_button.grid(column = 9, row = 0)


    def list_books(self):
        list_button = Button(self.frame2, text = "List", command = lambda: self.books_view_tree(self.__book_services.list_books_service()))
        list_button.grid(column = 10, row = 0)


    def filter_books(self, book_id, book_title, book_author):
        try:
            filter_button = Button(self.frame2, text = "Filter",
                                   command = lambda: self.books_view_tree(self.__book_services.filter_books_service(book_id.get().strip().upper() if book_id.get().strip().upper() != "" else None,
                                                                                                                    book_title.get().strip().upper() if book_title.get().strip().upper() != "" else None,
                                                                                                                    book_author.get().strip().upper() if book_author.get().strip().upper() != "" else None)))
            filter_button.grid(column = 11, row = 0)
        except Excetion as e:
            messagebox.showerror("error", e)


    def navigate_to_tab(self, index):
        self.notebook.select(index)


    def book_input(self):   # for the book input we use the frame2
        """
        Entries and Input boxex for the parameters of a book entity
        """
        book_id_label = Label(self.frame2, text = "BOOK ID: ", bg = "white", fg = "blue", font = ("ARIAL", 15))
        book_id_label.grid(column = 0, row = 1, sticky = "W")
        book_id = Entry(self.frame2, width = 30, bd = 2)
        book_id.grid(column = 1, row = 1)

        book_title_label = Label(self.frame2, text = "BOOK TITLE: ", bg = "white", fg = "blue", font = ("ARIAL", 15))
        book_title_label.grid(column = 0, row = 2, sticky = "W")
        book_title = Entry(self.frame2, width = 30, bd = 2)
        book_title.grid(column = 1, row = 2)

        book_author_label = Label(self.frame2, text = "BOOK AUTHOR: ", bg = "white", fg = "blue", font = ("ARIAL", 15))
        book_author_label.grid(column = 0, row = 3, sticky = "W")
        book_author = Entry(self.frame2, width = 30, bd = 2)
        book_author.grid(column = 1, row = 3)

        self.add_book_button(book_id, book_title, book_author)
        self.remove_book_button(book_id, book_title, book_author)
        self.update_book_button(book_id, book_title, book_author)
        self.filter_books(book_id, book_title, book_author)
        self.list_books()
        main_menu_button = Button(self.frame2, text = "Main Menu", command = lambda: self.navigate_to_tab(0))
        main_menu_button.grid(column = 6, row = 0)


    """ Client GUI implementation """
    def clients_view_tree(self, data):
        """
        :param data: a list of list which contains the data for the view tree. each list from an index has a: book id, book name, book author
        :return: a view tree
        """
        level1 = Toplevel()
        level1.geometry("500x400")

        # create a tree
        my_tree = ttk.Treeview(level1)
        my_tree['columns'] = ("CLIENT ID", "CLIENT NAME")

        # create columns
        my_tree.column("#0", width = 0, stretch = NO)
        my_tree.column("CLIENT ID", anchor = W, width = 100)
        my_tree.column("CLIENT NAME", anchor = W, width = 200)

        # create headings
        my_tree.heading("#0", text = "", anchor = W)
        my_tree.heading("CLIENT ID", text = "ID", anchor = W)
        my_tree.heading("CLIENT NAME", text="CLIENT NAME", anchor=W)

        # grid to the the screen
        my_tree.grid()
        for index, el in enumerate(data):
            my_tree.insert(parent='', index='end', iid=index, values=(el.client_id, el.client_name))

        # adding a scroll bar to the tree
        scrollbar = Scrollbar(level1, orient=VERTICAL, command=lambda: my_tree.yview)
        my_tree.configure(yscroll=scrollbar.set)
        scrollbar.grid(row=0, column=1, sticky='ns')

        close_button = Button(level1, text = "Close", command = lambda: level1.destroy())
        close_button.grid(column=1, row = 12)



    def add_client_gui(self, client_id, client_name):
        try:
            if "" not in (client_id.get().strip(), client_name.get().strip()):
                self.__client_services.add_client_service(client_id.get().strip().upper(), client_name.get().strip().upper())
                messagebox.showinfo("info", "Client added succesfully!")
        except Exception as e:
            messagebox.showerror("error", e)


    def add_client_button(self, client_id, client_name):
        add_button = Button(self.frame3, text="Add", command=lambda: self.add_client_gui(client_id, client_name))
        add_button.grid(column = 7, row = 0)


    def remove_client_gui(self, client_id, client_name):
        try:
            if "" not in (client_id.get().strip(), client_name.get().strip()):
                self.__client_services.remove_client_service(client_id.get().strip().upper(), client_name.get().strip().upper())
                messagebox.showinfo("info", "Client removed succesfully!")
        except Exception as e:
            messagebox.showerror("error", e)


    def remove_client_button(self, client_id, client_name):
        remove_button = Button(self.frame3, text = "Remove", command = lambda: self.remove_client_gui(client_id, client_name))
        remove_button.grid(column = 8, row = 0)


    def update_client_gui2(self, top, old_client_id, old_client_name, new_client_name):
        try:
            if "" != new_client_name.get().strip():
                self.__client_services.update_client_service(old_client_id.get().strip().upper(),
                                                             old_client_name.get().strip().upper(),
                                                             new_client_name.get().strip().upper())
            top.destroy()
        except Exception as e:
            messagebox.showerror("error", e)
        else:
            messagebox.showinfo("info", "Client updated succesfully!")



    def update_client_gui1(self, old_client_id, old_client_name):
        """
        Entries and input boxex for the new parameters of a client
        :param old_client_id: the old client id entry of the client
        :param old_client_name: the old client name entry of the client

        """
        try:
            if "" not in(old_client_id.get().strip(), old_client_name.get().strip()):
                top = Toplevel()
                top.grid()
                # new book title entry
                new_client_name_label = Label(top, text="CLIENT NAME: ", bg="white", fg="blue", font=("ARIAL", 15))
                new_client_name_label.grid(column=0, row=0)
                new_client_name = Entry(top, width=30, bd=2)
                new_client_name.grid(column=1, row=0)

                confirm_button = Button(top, text="Confirm", command = lambda: self.update_client_gui2(top, old_client_id, old_client_name,
                                                                                                       new_client_name)).grid(column=1, row=1)
        except Exception as e:
            messagebox.showerror("error", e)


    def update_client_button(self, client_id, client_name):
        """
        :param client_id: client id of a entry
        :param client_name: client name of a entry
        :return: None
        """
        update_button = Button(self.frame3, text = "Update", command = lambda: self.update_client_gui1(client_id, client_name))
        update_button.grid(column = 9, row = 0)


    def list_clients(self):
        list_button = Button(self.frame3, text = "List", command = lambda: self.clients_view_tree(self.__client_services.list_clients_service()))
        list_button.grid(column = 10, row = 0)


    def filter_clients(self, client_id, client_name):
        try:
            filter_button = Button(self.frame3, text = "Filter",
                                   command = lambda: self.clients_view_tree(self.__client_services.filter_clients_service(client_id.get().strip().upper() if client_id.get().strip().upper() != "" else None,
                                                                                                                          client_name.get().strip().upper() if client_name.get().strip().upper() != "" else None)))

            filter_button.grid(column = 11, row = 0)
        except Excetion as e:
            messagebox.showerror("error", e)


    def client_input(self):
        """ Entries and Input boxex for the parameters of a book entity """
        client_id_label = Label(self.frame3, text="CLIENT ID: ", bg="white", fg="blue", font=("ARIAL", 15))
        client_id_label.grid(column=0, row=1, sticky = "W")
        client_id = Entry(self.frame3, width=30, bd=2)
        client_id.grid(column=1, row=1)

        client_name_label = Label(self.frame3, text="CLIENT NAME: ", bg="white", fg="blue", font=("ARIAL", 15))
        client_name_label.grid(column=0, row=2, sticky = "W")
        client_name = Entry(self.frame3, width=30, bd=2)
        client_name.grid(column=1, row=2)

        main_menu_button = Button(self.frame3, text="Main Menu", command=lambda: self.navigate_to_tab(0))
        main_menu_button.grid(column=6, row=0)

        self.add_client_button(client_id, client_name)
        self.remove_client_button(client_id, client_name)
        self.update_client_button(client_id, client_name)
        self.filter_clients(client_id, client_name)
        self.list_clients()


    """ Rental GUI implementation """
    def rentals_view_tree(self, data):
        """
        :param data: a list of list which contains the data for the view tree. each list from an index has a: book id, book name, book author
        :return: a view tree
        """
        level1 = Toplevel()
        level1.geometry("600x500")

        # create a tree
        my_tree = ttk.Treeview(level1)
        my_tree['columns'] = ("RENTAL ID", "BOOK ID", "CLIENT ID", "RENTED DATE", "RETURNED DATE" )

        # create columns
        my_tree.column("#0", width=0, stretch=NO)
        my_tree.column("RENTAL ID", anchor=W, width=100)
        my_tree.column("BOOK ID", anchor=CENTER, width=100)
        my_tree.column("CLIENT ID", anchor=W, width=100)
        my_tree.column("RENTED DATE", anchor=W, width = 100)
        my_tree.column("RETURNED DATE", anchor = W, width =100)

        # create headings
        my_tree.heading("#0", text="", anchor=W)
        my_tree.heading("RENTAL ID", text="RENTAL ID", anchor=W)
        my_tree.heading("BOOK ID", text="BOOK ID", anchor=W)
        my_tree.heading("CLIENT ID", text="CLIENT ID", anchor=W)
        my_tree.heading("RENTED DATE", text="RENTED DATE", anchor = W)
        my_tree.heading("RETURNED DATE", text="RETURNED DATE", anchor=W)
        # grid to the the screen
        my_tree.grid()
        for index, el in enumerate(data):
            my_tree.insert(parent='', index='end', iid=index, values=(el.rental_id, el.book_id, el.client_id, el.rented_date, el.returned_date))

        # adding a scroll bar to the tree
        scrollbar = Scrollbar(level1, orient=VERTICAL, command=lambda: my_tree.yview)
        my_tree.configure(yscroll=scrollbar.set)
        scrollbar.grid(row=0, column=1, sticky='ns')

        close_button = Button(level1, text="Close", command=lambda: level1.destroy())
        close_button.grid(column=1, row=12)


    def list_rentals(self):
        list_button = Button(self.frame4, text="List",
                             command=lambda: self.rentals_view_tree(self.__rental_services.list_rentals_service()))
        list_button.grid(column=10, row=0)



    def rent_book_gui(self, rental_id, book_id, client_id, rented_date):
        try:
            if "" in (rental_id.get().strip().upper(), book_id.get().strip().upper(), client_id.get().strip().upper(), rented_date.get().strip().upper()):
                raise Exception("Empty boxex!")
            else:
                self.__rental_services.rent_book_service(rental_id.get().strip().upper(), book_id.get().strip().upper(), client_id.get().strip().upper(), rented_date.get().strip().upper())
        except Exception as e:
            messagebox.showerror("error", e)
        else:
            messagebox.showinfo("info", "Rental added successfully!")


    def rent_book_button(self, rental_id, book_id, client_id, rented_date):
        rent_button = Button(self.frame4, text = "Rent", command = lambda: self.rent_book_gui(rental_id, book_id, client_id, rented_date))
        rent_button.grid(column=6, row=0)


    def return_book_gui(self, rental_id, book_id, client_id, rented_date, returned_date):
        try:
            if "" in (rental_id.get().strip().upper(), book_id.get().strip().upper(), client_id.get().strip().upper(), rented_date.get().strip().upper(), returned_date.get().strip().upper()):
                raise Exception("Empty boxex!")
            else:
                self.__rental_services.return_book_service(rental_id.get().strip().upper(), book_id.get().strip().upper(), client_id.get().strip().upper(), rented_date.get().strip().upper(), returned_date.get().strip().upper())
        except Exception as e:
            messagebox.showerror("error", e)
        else:
            messagebox.showinfo("info", "Book successfully returned!")


    def return_book_button(self, rental_id, book_id, client_id, rented_date, returned_date):
        return_button = Button(self.frame4, text="Return",
                             command=lambda: self.return_book_gui(rental_id, book_id, client_id, rented_date, returned_date))
        return_button.grid(column=7, row=0)


    def rental_input(self):
        rental_id_label = Label(self.frame4, text="RENTAL ID: ", bg="white", fg="blue", font=("ARIAL", 15))
        rental_id_label.grid(column=0, row=1, sticky = "W")
        rental_id = Entry(self.frame4, width=30, bd=2)
        rental_id.grid(column=1, row=1)

        book_id_label = Label(self.frame4, text="BOOK ID: ", bg="white", fg="blue", font=("ARIAL", 15))
        book_id_label.grid(column=0, row=2, sticky = "W")
        book_id = Entry(self.frame4, width=30, bd=2)
        book_id.grid(column=1, row=2)

        client_id_label = Label(self.frame4, text="CLIENT ID: ", bg="white", fg="blue", font=("ARIAL", 15))
        client_id_label.grid(column=0, row=3, sticky = "W")
        client_id = Entry(self.frame4, width=30, bd=2)
        client_id.grid(column=1, row=3)

        rented_date_label = Label(self.frame4, text = "RENTED DATE: ", bg="white", fg="blue", font=("ARIAL", 15))
        rented_date_label.grid(column = 0, row = 4, sticky = "W")
        rented_date = Entry(self.frame4, width=30, bd=2)
        rented_date.grid(column = 1, row = 4)

        returned_date_label = Label(self.frame4, text="RETURNED DATE: ", bg="white", fg="blue", font=("ARIAL", 15))
        returned_date_label.grid(column=0, row=5, sticky = "W")
        returned_date = Entry(self.frame4, width=30, bd=2)
        returned_date.grid(column=1, row=5)

        self.list_rentals()
        self.rent_book_button(rental_id, book_id, client_id, rented_date)
        self.return_book_button(rental_id, book_id, client_id, rented_date, returned_date)
        main_menu_button = Button(self.frame4, text="Main Menu", command=lambda: self.navigate_to_tab(0))
        main_menu_button.grid(column=5, row=0)



    def most_rented_books_view_tree(self, data):
        """
        :param data: a list of list which contains the data for the view tree. each list from an index has a: book id, book name, book author
        :return: a view tree
        """
        level1 = Toplevel()
        level1.geometry("500x400")

        # create a tree
        my_tree = ttk.Treeview(level1)
        my_tree['columns'] = ("BOOK", "TIMES")

        # create columns
        my_tree.column("#0", width = 0, stretch = NO)
        my_tree.column("BOOK", anchor = W, width = 300)
        my_tree.column("TIMES", anchor = W, width = 100)

        # create headings
        my_tree.heading("#0", text = "", anchor = W)
        my_tree.heading("BOOK", text = "BOOK", anchor = W)
        my_tree.heading("TIMES", text="TIMES", anchor=W)

        # grid to the the screen
        my_tree.grid()
        for index, el in enumerate(data):
            my_tree.insert(parent='', index='end', iid=index, values=(el.book, el.rentals))

        # adding a scroll bar to the tree
        scrollbar = Scrollbar(level1, orient=VERTICAL, command=lambda: my_tree.yview)
        my_tree.configure(yscroll=scrollbar.set)
        scrollbar.grid(row=0, column=1, sticky='ns')

        close_button = Button(level1, text = "Close", command = lambda: level1.destroy())
        close_button.grid(column=1, row = 12)


    def most_rented_books_gui(self):
        self.most_rented_books_view_tree(self.__rental_services.most_rented_books())


    def most_rented_books_button(self, my_frame):
        most_rented_books_button = Button(my_frame, text = "Most rented book", command = lambda: self.most_rented_books_gui())
        most_rented_books_button.grid(row = 0, column = 1, padx = 5)


    def most_active_clients_view_tree(self, data):
        """
        :param data: a list of list which contains the data for the view tree. each list from an index has a: book id, book name, book author
        :return: a view tree
        """
        level1 = Toplevel()
        level1.geometry("500x400")

        # create a tree
        my_tree = ttk.Treeview(level1)
        my_tree['columns'] = ("CLIENT", "ACTIVE DAYS")

        # create columns
        my_tree.column("#0", width = 0, stretch = NO)
        my_tree.column("CLIENT", anchor = W, width = 300)
        my_tree.column("ACTIVE DAYS", anchor = W, width = 100)

        # create headings
        my_tree.heading("#0", text = "", anchor = W)
        my_tree.heading("CLIENT", text = "CLIENT", anchor = W)
        my_tree.heading("ACTIVE DAYS", text="ACTIVE DAYS", anchor=W)

        # grid to the the screen
        my_tree.grid()
        for index, el in enumerate(data):
            my_tree.insert(parent='', index='end', iid=index, values=(el.client, el.activity))

        # adding a scroll bar to the tree
        scrollbar = Scrollbar(level1, orient=VERTICAL, command=lambda: my_tree.yview)
        my_tree.configure(yscroll=scrollbar.set)
        scrollbar.grid(row=0, column=1, sticky='ns')

        close_button = Button(level1, text = "Close", command = lambda: level1.destroy())
        close_button.grid(column=1, row = 12)


    def most_active_clients_gui(self):
        self.most_active_clients_view_tree(self.__rental_services.most_active_clients())


    def most_active_clients_button(self, my_frame):
        button = Button(my_frame, text = "Most active clients", command = lambda: self.most_active_clients_gui())
        button.grid(row = 0, column = 2, padx = 5)


    def most_rented_authors_view_tree(self, data):
        """
        :param data: a list of list which contains the data for the view tree. each list from an index has a: book id, book name, book author
        :return: a view tree
        """
        level1 = Toplevel()
        level1.geometry("500x400")

        # create a tree
        my_tree = ttk.Treeview(level1)
        my_tree['columns'] = ("AUTHOR", "TIMES")

        # create columns
        my_tree.column("#0", width = 0, stretch = NO)
        my_tree.column("AUTHOR", anchor = W, width = 300)
        my_tree.column("TIMES", anchor = W, width = 100)

        # create headings
        my_tree.heading("#0", text = "", anchor = W)
        my_tree.heading("AUTHOR", text = "AUTHOR", anchor = W)
        my_tree.heading("TIMES", text="TIMES", anchor=W)

        # grid to the the screen
        my_tree.grid()
        for index, el in enumerate(data):
            my_tree.insert(parent='', index='end', iid=index, values=(el.book, el.rentals))

        # adding a scroll bar to the tree
        scrollbar = Scrollbar(level1, orient=VERTICAL, command=lambda: my_tree.yview)
        my_tree.configure(yscroll=scrollbar.set)
        scrollbar.grid(row=0, column=1, sticky='ns')

        close_button = Button(level1, text = "Close", command = lambda: level1.destroy())
        close_button.grid(column=1, row = 12)


    def most_rented_authors_gui(self):
        self.most_rented_authors_view_tree(self.__rental_services.most_rented_authors())


    def most_rented_authors_button(self, my_frame):
        button = Button(my_frame, text="Most rented authors", command=lambda: self.most_rented_authors_gui())
        button.grid(row = 0, column = 3, padx = 5)


    def undo_gui(self):
        try:
            self.__undo_redo_service.undo()
        except IndexError as e:
            messagebox.showerror("error", e)
        else:
            messagebox.showinfo("info", "Undo succesfully completed!")

    def undo_button(self, my_frame):
        button = Button(my_frame, text = "Undo", command = lambda: self.undo_gui())
        button.grid(row = 0, column = 0)


    def redo_gui(self):
        try:
            self.__undo_redo_service.redo()
        except IndexError as e:
            messagebox.showerror("error", e)
        else:
            messagebox.showinfo("info", "Undo succesfully completed!")


    def redo_button(self, my_frame):
        button = Button(my_frame, text = "Redo", command = lambda: self.redo_gui())
        button.grid(row = 0, column = 1)



    def main_menu_navigation_buttons(self):
        navigation_label = Label(self.frame1, bg = "white")
        label = Label(navigation_label, text = "Navigate to: ", font = (1), bg = "white", fg = "blue")
        label.grid(row = 0, column = 0)
        button1 = Button(navigation_label, text = "Books Services", command = lambda: self.navigate_to_tab(1))
        button2 = Button(navigation_label, text="Clients Services", command=lambda: self.navigate_to_tab(2))
        button3 = Button(navigation_label, text="Rentals Services", command=lambda: self.navigate_to_tab(3))
        button1.grid(row = 0, column = 1, padx = 5)
        button2.grid(row = 0, column = 2, padx = 5)
        button3.grid(row = 0, column = 3, padx = 5)
        navigation_label.grid(row = 1, column = 0, sticky = "W", pady = 5)



    def start(self):
        self.main_menu_navigation_buttons()
        self.book_input()
        self.client_input()
        self.rental_input()

        stastics_commands = Label(self.frame1, bg = "white")
        statistics_label = Label(stastics_commands, text = "Statistics: ", font = (1), bg = "white", fg = "blue")
        statistics_label.grid(row = 0, column = 0)

        self.most_rented_books_button(stastics_commands)
        self.most_active_clients_button(stastics_commands)
        self.most_rented_authors_button(stastics_commands)
        stastics_commands.grid(row = 2, column = 0, sticky = "W")

        undo_redo_commands = Label(self.frame1, bg = "white")
        undo_redo_commands.grid(row = 0, column = 0, sticky = "W")
        self.undo_button(undo_redo_commands)
        self.redo_button(undo_redo_commands)
