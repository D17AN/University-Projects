CREATE TABLE Book
(
    book_id int primary key,
    name varchar(max),
    author varchar(max),
    price int
);

CREATE TABLE Bookstore
(
    store_id int primary key,
    name varchar(max),
    country varchar(max),
    city varchar(max)
);

CREATE TABLE BookInBookstore
(
    book_id int references Book(book_id),
    store_id int references Bookstore(store_id),
    primary key (book_id, store_id)
);

CREATE TABLE PublishingCompany
(
    company_id int primary key,
    name varchar(max),
    number_of_employees int
);

CREATE TABLE Magazine
(
    magazine_id int primary key,
    company_id int references PublishingCompany(company_id),
    price int,
    name varchar(max)
);
