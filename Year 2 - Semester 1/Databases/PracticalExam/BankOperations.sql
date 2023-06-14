/*
Create database for tracking operations within a bank.
You will manage customers, bank accounts, cards, ATMs and transactions.
Each customer has a name, the date of birth and may have multiple bank accounts.
For each bank account consider the following: the IBAN code, the current balance, the holder and the cards associated with that bank account.
Each card has a number, a CVV code (last 3 digits of the card number) and is associated with a bank account. An ATM has an address.
A transaction involves withdrawing, from an ATM, a sum of money using a card at a certain time (consider both date and time).
Of course, a card can be used in several transactions at the same ATM or at different ATMs and at an ATM multiple transactions can be done with multiple cards.

Requierements:
1. Write an SQL Server script that creates the corresponding relational data model.
2. Implement a stored procedure that receives a card and deletes all the transactions related to that card.
3. Create a view that shows the card numbers which were used in transactions at all the ATMs.
4. Implement a functions that lists the cards (number and CVV code) that have the total transactions sum greater than 2000 lei.
*/
/*
DROP TABLE Transactions, Cards, BankAccounts, ATMs, Customers

--1)
-- Creating Customers table
CREATE TABLE Customers (
    id INT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    date_of_birth DATE NOT NULL
);

-- Creating Bank Accounts table
CREATE TABLE BankAccounts (
    id INT PRIMARY KEY,
    iban VARCHAR(255) UNIQUE NOT NULL,
    balance DECIMAL(18, 2) NOT NULL,
    customer_id INT NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES Customers(id)
);

-- Creating Cards table
CREATE TABLE Cards (
    id INT PRIMARY KEY,
    number VARCHAR(255) UNIQUE NOT NULL,
    cvv VARCHAR(3) NOT NULL,
    account_id INT NOT NULL,
    FOREIGN KEY (account_id) REFERENCES BankAccounts(id)
);

-- Creating ATMs table
CREATE TABLE ATMs (
    id INT PRIMARY KEY,
    address VARCHAR(255) NOT NULL
);

-- Creating Transactions table
CREATE TABLE Transactions (
    id INT PRIMARY KEY,
    card_id INT NOT NULL,
    atm_id INT NOT NULL,
    amount DECIMAL(18, 2) NOT NULL,
    date_time DATETIME NOT NULL,
    FOREIGN KEY (card_id) REFERENCES Cards(id),
    FOREIGN KEY (atm_id) REFERENCES ATMs(id)
);

--2)
GO
CREATE PROCEDURE delete_transactions_by_card(@card_number VARCHAR(255))
AS
BEGIN
    DELETE FROM Transactions
    WHERE card_id = (SELECT id FROM Cards WHERE number = @card_number)
END;

--3)
GO
CREATE VIEW used_cards_at_all_atms AS
    SELECT DISTINCT number FROM Cards
    JOIN Transactions ON Cards.id = Transactions.card_id;

--4)
GO
CREATE FUNCTION get_cards_with_transactions_over_amount(@threshold FLOAT)
RETURNS TABLE 
AS
RETURN
    SELECT number, cvv
    FROM Cards
    WHERE (SELECT SUM(amount) FROM Transactions WHERE card_id = Cards.id) > @threshold;

GO
SELECT * FROM dbo.get_cards_with_transactions_over_amount(2000)\
*/

-- 1
-- Create Airplanes table
CREATE TABLE Airplanes (
    ID INT PRIMARY KEY IDENTITY(1, 1),
    ModelNumber NVARCHAR(255) NOT NULL,
    RegistrationNumber NVARCHAR(255) UNIQUE NOT NULL,
    Capacity INT NOT NULL
);

-- Create Flights table
CREATE TABLE Flights (
    ID INT PRIMARY KEY IDENTITY(1, 1),
    FlightNumber NVARCHAR(255) UNIQUE NOT NULL,
    DepartureAirport NVARCHAR(255) NOT NULL,
    DestinationAirport NVARCHAR(255) NOT NULL,
    DepartureDateTime DATETIME NOT NULL,
    ArrivalDateTime DATETIME NOT NULL,
    AirplaneID INT NOT NULL,
    FOREIGN KEY (AirplaneID) REFERENCES Airplanes(ID)
);

-- Create Passengers table
CREATE TABLE Passengers (
    ID INT PRIMARY KEY IDENTITY(1, 1),
    FirstName NVARCHAR(255) NOT NULL,
    LastName NVARCHAR(255) NOT NULL,
    Email NVARCHAR(255) UNIQUE NOT NULL
);

-- Create Payments table
CREATE TABLE Payments (
    ID INT PRIMARY KEY IDENTITY(1, 1),
    Amount DECIMAL(18, 2) NOT NULL,
    PaymentDateTime DATETIME NOT NULL,
    PaymentType NVARCHAR(255) NOT NULL
);

-- Create Reservations table
CREATE TABLE Reservations (
    ID INT PRIMARY KEY IDENTITY(1, 1),
    FlightID INT NOT NULL,
    PassengerID INT NOT NULL,
    PaymentID INT,
    FOREIGN KEY (FlightID) REFERENCES Flights(ID),
    FOREIGN KEY (PassengerID) REFERENCES Passengers(ID),
    FOREIGN KEY (PaymentID) REFERENCES Payments(ID)
);


INSERT INTO Airplanes (ModelNumber, RegistrationNumber, Capacity) VALUES ('A320', 'N123AA', 150);
INSERT INTO Airplanes (ModelNumber, RegistrationNumber, Capacity) VALUES ('B787', 'N456BB', 250);

INSERT INTO Flights (FlightNumber, DepartureAirport, DestinationAirport, DepartureDateTime, ArrivalDateTime, AirplaneID) 
VALUES ('AA100', 'New York', 'London', '2022-01-01 10:00:00', '2022-01-01 15:00:00', 1);
INSERT INTO Flights (FlightNumber, DepartureAirport, DestinationAirport, DepartureDateTime, ArrivalDateTime, AirplaneID) 
VALUES ('AA200', 'London', 'Paris', '2022-01-02 12:00:00', '2022-01-02 14:00:00', 1);

INSERT INTO Passengers (FirstName, LastName, Email) VALUES ('John', 'Doe', 'johndoe@example.com');
INSERT INTO Passengers (FirstName, LastName, Email) VALUES ('Jane', 'Doe', 'janedoe@example.com');

INSERT INTO Reservations (FlightID, PassengerID) VALUES (1, 1);
INSERT INTO Reservations (FlightID, PassengerID) VALUES (2, 1);
INSERT INTO Reservations (FlightID, PassengerID) VALUES (2, 2);

INSERT INTO Payments (Amount, PaymentDateTime, PaymentType) VALUES (300, '2022-01-01 12:00:00', 'Visa');
INSERT INTO Payments (Amount, PaymentDateTime, PaymentType) VALUES (200, '2022-01-02 10:00:00', 'Mastercard');

--2
GO
CREATE PROCEDURE AddPaymentToReservation (@ReservationID INT, @PaymentAmount DECIMAL(18, 2), @PaymentDateTime DATETIME, @PaymentType NVARCHAR(255))
AS
BEGIN
    IF NOT EXISTS (SELECT 1 FROM Reservations WHERE ID = @ReservationID AND PaymentID IS NOT NULL)
    BEGIN
        INSERT INTO Payments (Amount, PaymentDateTime, PaymentType) VALUES (@PaymentAmount, @PaymentDateTime, @PaymentType);

        DECLARE @PaymentID INT = SCOPE_IDENTITY();

        UPDATE Reservations SET PaymentID = @PaymentID WHERE ID = @ReservationID;
    END
    ELSE
    BEGIN
        PRINT 'A payment for this reservation already exists'
    END
END
GO
exec AddPaymentToReservation '1', '1000', '2022-12-28', 'Visa'
SELECT *
FROM Reservations
SELECT *
FROM Payments
--3
GO
CREATE VIEW PassengersWithReservationsFromMadrid AS
SELECT p.FirstName, p.LastName
FROM Passengers p
JOIN Reservations r ON p.ID = r.PassengerID
JOIN Flights f ON r.FlightID = f.ID
WHERE f.DepartureAirport = 'Madrid'
GROUP BY p.FirstName, p.LastName
GO
SELECT * FROM PassengersWithReservationsFromMadrid;

--4
GO
CREATE FUNCTION GetFlightsWithValidReservations (@StartDate DATETIME, @EndDate DATETIME, @MinValidReservations INT)
RETURNS TABLE 
AS
RETURN 
    SELECT f.ID, f.FlightNumber
    FROM Flights f
    JOIN Reservations r ON f.ID = r.FlightID
    JOIN Payments p ON r.PaymentID = p.ID
    WHERE f.DepartureDateTime >= @StartDate AND f.DepartureDateTime <= @EndDate
    GROUP BY f.ID, f.FlightNumber
    HAVING COUNT(r.ID) > @MinValidReservations

GO

--27
CREATE TABLE t(
	FK1 INT,
	FK2 INT,
	C1 VARCHAR(100),
	C2 VARCHAR(100),
	C3 FLOAT,
	C4 INT,
	PRIMARY KEY(FK1, FK2)
)

go
INSERT INTO t (FK1, FK2, C1, C2, C3, C4)
VALUES
('1', '3', 'Martha Delacruz', 'Ferrari', '23.5', '400'),
('3', '1', 'Roman Hayes', 'Mercedes', '13.25', '100'),
('1', '1', 'Maddison Rios', 'Haas', '61.25', '10'),
('3', '5', 'Haylee Hodges', 'Red bull', '50.5', '300'),
('5', '1', 'Thalia Kemp', 'Mercedes', '23.75', '150'),
('2', '7', 'Marlie Jordan', 'Alfa Romeo', '18.5', '230'),
('2', '3', 'Lea Hill', 'Alpha Tauri', '2.75', '520'),
('2', '1', 'Cason Barry', 'Ferrari', '90.25', '920'),
('3', '2', 'Skylar Velez', 'Red Bull', '72.25', '850'),
('3', '6', 'Dallas Lynch', 'Alfa Romeo', '90.5', '720'),
('1', '2', 'Jimena Mayer', 'Haas', '80.25', '64'),
('1', '7', 'Zayden Daugherty', 'Mercedes', '95.75', '450'),
('2', '5', 'Tate Huang', 'Ferrari', '10.5', '510'),
('4', '2', 'Rex Serrano', 'Alfa Romeo', '15.25', '320'),
('2', '4', 'Wilson Duke', 'Alpha Tauri', '30.25', '290'),
('5', '2', 'Enrique Park', 'Haas', '85.25', '180')

SELECT C2, SUM(C3) AS S, COUNT(*) AS C
FROM t
WHERE C1 LIKE '%as%' or C3>20
GROUP BY C2
HAVING SUM(C3) <= 150 OR COUNT(*) > 3


SELECT * FROM
(SELECT * FROM t
WHERE FK1 <= FK2)R1
RIGHT JOIN
(SELECT * FROM t
WHERE C4/10 < C3)R2
ON R1.FK1 = R2.FK1 AND R1.FK2 = R2.FK2

GO
CREATE OR ALTER TRIGGER TriggerOnUpdate
ON t
FOR UPDATE
AS
DECLARE @n INT = 0
SELECT @n = SUM(2*d.FK1 + i.FK2)
from deleted d
INNER JOIN inserted i
ON d.FK1 = i.FK1 and d.FK2 = i.FK2
where d.C3 > i.C3
PRINT @n
GO

UPDATE t
SET C3 = 35.5
WHERE FK2>FK1

