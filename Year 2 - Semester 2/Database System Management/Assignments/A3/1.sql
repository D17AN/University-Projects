--create a stored procedure that inserts data in tables that are in a m:n relationship; 
--if one insert fails, all the operations performed by the procedure must be rolled back;

CREATE OR ALTER PROCEDURE addRowBook (@name varchar(100), @author varchar(100), 
	@price float) as
	declare @maxID INT
		set @maxID = 0 --get a valid id
		SELECT TOP 1 @maxID = book_id + 1 FROM Book ORDER BY book_id DESC
		
		declare @errors varchar(max)
		set @errors = ''

		if (@name is null)
		begin
			set @errors = 'Book name not defined!'
			raiserror('Book name not defined!', 24, 1);
		end

		if(@author is null)
		begin
			set @errors = 'Author name not defined!'
			raiserror('Author name not defined!', 24, 1);
		end 

		if(@price < 0)
		begin
			set @errors = 'Author name not defined!'
			raiserror('Author name not defined!', 24, 1);
		end

		INSERT INTO Book (book_id, name, author, price) VALUES 
			(@maxID, @name, @author, @price);
	EXEC sp_log_changes null, @name, 'Added row to book', @errors

GO

CREATE OR ALTER PROCEDURE addRowBookstore(@name varchar(100), @country varchar(100), 
	@city varchar(100)) as 
	declare @maxID INT
		set @maxID = 0
		SELECT TOP 1 @maxID = store_id + 1 FROM Bookstore ORDER BY store_id DESC

		declare @errors varchar(max)
		set @errors = ''

		if (@name is null)
		begin
			set @errors = 'Bookstore name not defined!'
			raiserror('Bookstore name not defined!', 24, 1);
		end 

		if (@country is null)
		begin
			set @errors = 'Bookstore country not defined!'
			raiserror('Bookstore country not defined!', 24, 1);
		end

		if (@city is null)
		begin
			set @errors = 'Bookstore city not defined!'
			raiserror('Bookstore city not defined!', 24, 1);
		end

		INSERT INTO Bookstore (store_id, name, country, city) VALUES
			(@maxID, @name, @country, @city);
	
	EXEC sp_log_changes null, @name, 'Added row to bookstore', @errors

GO

CREATE OR ALTER PROCEDURE addRowBookInBookstore(@BookName varchar(100), 
	@BookstoreName varchar(100)) as
		
		declare @errors varchar(max)
		set @errors = ''

		if (@BookName is null)
		begin
			set @errors = 'Book name is not defined!'
			raiserror('Book name is not defined!', 24, 1);
		end 

		if (@BookstoreName is null)
		begin
			set @errors = 'Bookstore name is not defined!'
			raiserror('Bookstore name is not defined!', 24, 1);
		end

		declare @BookNameID int
		SET @BookNameID = (SELECT book_id FROM Book WHERE name = @BookName)
		declare @BookstoreNameID int
		SET @BookstoreNameID = (SELECT store_id FROM Bookstore WHERE name = @BookstoreName)

		if (@BookNameID is null)
		begin
			set @errors = 'Book name does not exists!'
			raiserror('Book name does not exists!', 24, 1);
		end

		if (@BookstoreNameID is null)
		begin
			set @errors = 'Bookstore name does not exists!'
			raiserror('Bookstore name does not exists!', 24, 1);
		end

		INSERT INTO BookInBookstore VALUES (@BookNameID, @BookstoreNameID)
		declare @newData varchar(100)
		set @newData = @BookName + ' ' + @BookstoreName

	EXEC sp_log_changes null, @newData, 'Connected book to bookstore', @errors

GO

CREATE OR ALTER PROCEDURE rollbackScenarioNoFail
AS
	BEGIN TRAN
	BEGIN TRY
		EXEC addRowBook 'Lord of the rings', 'J.R.R. Tolkien', 100
		EXEC addRowBookstore 'Carturesti', 'Romania', 'Cluj-Napoca'
		EXEC addRowBookInBookstore 'Lord of the rings', 'Carturesti'
	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		RETURN
	END CATCH
	COMMIT TRAN
GO

CREATE OR ALTER PROCEDURE rollbackScenarioFail
AS
	BEGIN TRAN
	BEGIN TRY
		EXEC addRowBook 'Lord of the rings', 'J.R.R. Tolkien', 100
		EXEC addRowBookstore 'Carturesti', 'Romania', 'Cluj-Napoca'
		EXEC addRowBookInBookstore 'Lord of the rings', 'Bookstory'
	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		RETURN
	END CATCH
	COMMIT TRAN
GO

CREATE OR ALTER PROCEDURE noRollbackScenarioManyToManyNoFail
AS
	declare @ERRORS INT
	set @ERRORS = 0
	BEGIN TRY
		EXEC addRowBook 'Lord of the rings', 'J.R.R. Tolkien', 100
	END TRY
	BEGIN CATCH
		set @ERRORS = @ERRORS + 1
	END CATCH

	BEGIN TRY
		EXEC addRowBookstore 'Carturesti', 'Romania', 'Cluj-Napoca'
	END TRY
	BEGIN CATCH
		set @ERRORS = @ERRORS + 1
	END CATCH

	if (@errors = 0) BEGIN
		BEGIN TRY
			EXEC addRowBookInBookstore 'Lord of the rings', 'Carturesti'
		END TRY
		BEGIN CATCH
		END CATCH
	END
GO

CREATE OR ALTER PROCEDURE noRollbackScenarioManyToManyFail
AS
	declare @ERRORS INT
	set @ERRORS = 0
	BEGIN TRY
		EXEC addRowBook 'Lord of the rings', 'J.R.R. Tolkien', 100
	END TRY
	BEGIN CATCH
		set @ERRORS = @ERRORS + 1
	END CATCH

	BEGIN TRY
		EXEC addRowBookstore 'Carturesti', 'Romania', 'Cluj-Napoca'
	END TRY
	BEGIN CATCH
		set @ERRORS = @ERRORS + 1
	END CATCH

	if (@errors = 0) BEGIN
		BEGIN TRY
			EXEC addRowBookInBookstore 'Lord the rings', 'Bookstory'
		END TRY
		BEGIN CATCH
		END CATCH
	END
GO



SELECT * FROM Book
SELECT * FROM Bookstore
SELECT * FROM BookInBookstore
SELECT * FROM LogChanges

DELETE FROM BookInBookstore
DELETE FROM Bookstore
DELETE FROM Book
DELETE FROM LogChanges

exec rollbackScenarioFail
exec rollbackScenarioNoFail
exec noRollbackScenarioManyToManyFail
exec noRollbackScenarioManyToManyNoFail
