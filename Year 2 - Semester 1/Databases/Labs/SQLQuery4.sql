USE [Supplement Sportive Company]

DROP PROCEDURE [dbo].[setBudgetOfDepartmentDecimal]
DROP PROCEDURE [dbo].[setBudgetOfDepartmentInt]
DROP PROCEDURE [dbo].addFavoriteTypeOfProductToCustomer
DROP PROCEDURE [dbo].[removeFavoriteTypeOfProductToCustomer]
DROP PROCEDURE [dbo].[addDefaultOrderPrice]
DROP PROCEDURE [dbo].[removeDefaultOrderPrice]
DROP PROCEDURE [dbo].[addManager]
DROP PROCEDURE [dbo].[dropManager]
DROP PROCEDURE [dbo].[addIDAndManagedDepartmentPrimaryKeyManager]
DROP PROCEDURE [dbo].[removeIDAndManagedDepartmentPrimaryKeyManager]
DROP PROCEDURE [dbo].[newCandidateKey]
DROP PROCEDURE [dbo].[removeCandidateKey]
DROP PROCEDURE [dbo].[newForeignKeyManager]
DROP PROCEDURE [dbo].[removeForeignKeyManager]
DROP TABLE versionTable
DROP TABLE procedureTable
DROP PROCEDURE [dbo].[goToVersion]
ALTER TABLE CUSTOMER DROP COLUMN FAVORITE_TYPE_OF_PRODUCT
ALTER TABLE ORDER_ DROP CONSTRAINT DEFAULT_PRICE
DROP TABLE MANAGER
ALTER TABLE EMPLOYEE DROP CONSTRAINT EMPLOYEE_CANDIDATE_KEY




-- modify the type of a column
GO
CREATE PROCEDURE setBudgetOfDepartmentDecimal
AS
	ALTER TABLE DEPARTMENT ALTER COLUMN BUDGET DECIMAL(20, 1)

GO
CREATE PROCEDURE setBudgetOfDepartmentInt
AS
	ALTER TABLE DEPARTMENT ALTER COLUMN BUDGET INT


-- add/remove a column
GO
CREATE PROCEDURE addFavoriteTypeOfProductToCustomer
AS
	ALTER TABLE CUSTOMER ADD FAVORITE_TYPE_OF_PRODUCT VARCHAR(100)
GO
CREATE PROCEDURE removeFavoriteTypeOfProductToCustomer
AS
	ALTER TABLE CUSTOMER DROP COLUMN FAVORITE_TYPE_OF_PRODUCT

-- add/remove a default constraint
GO
CREATE PROCEDURE addDefaultOrderPrice
AS
	ALTER TABLE ORDER_ ADD CONSTRAINT DEFAULT_PRICE DEFAULT(50) FOR PRICE
GO
CREATE PROCEDURE removeDefaultOrderPrice
AS
	ALTER TABLE ORDER_ DROP CONSTRAINT DEFAULT_PRICE

-- create/drop a table
GO

CREATE PROCEDURE addManager
AS
	CREATE TABLE MANAGER(
			EID INT not null,
			MANAGED_DEPARTMENT INT not null,
			CONSTRAINT MANAGER_PRIMARY_KEY PRIMARY KEY(EID)
			)
GO
CREATE PROCEDURE dropManager
AS
	DROP TABLE MANAGER

-- add/remove a primary key
GO
CREATE PROCEDURE addIDAndManagedDepartmentPrimaryKeyManager
AS
	ALTER TABLE MANAGER
		DROP CONSTRAINT MANAGER_PRIMARY_KEY
	ALTER TABLE MANAGER
		ADD CONSTRAINT MANAGER_PRIMARY_KEY PRIMARY KEY(EID, MANAGED_DEPARTMENT)
GO
CREATE PROCEDURE removeIDAndManagedDepartmentPrimaryKeyManager
AS
	ALTER TABLE MANAGER
		DROP CONSTRAINT MANAGER_PRIMARY_KEY
	ALTER TABLE MANAGER
		ADD CONSTRAINT MANAGER_PRIMARY_KEY PRIMARY KEY(EID)

-- add/remove a candidate key
GO
CREATE PROCEDURE newCandidateKey
AS
	ALTER TABLE EMPLOYEE
		ADD CONSTRAINT EMPLOYEE_CANDIDATE_KEY UNIQUE(LAST_NAME, FIRST_NAME, DOB)
GO
CREATE OR ALTER PROCEDURE removeCandidateKey
AS
	ALTER TABLE EMPLOYEE
		DROP CONSTRAINT EMPLOYEE_CANDIDATE_KEY

-- add/remove a foreign key
GO
CREATE PROCEDURE newForeignKeyManager
AS
	ALTER TABLE MANAGER 
		ADD CONSTRAINT EID_FOREIGN_KEY FOREIGN KEY(EID) REFERENCES EMPLOYEE(EID)
GO
CREATE OR ALTER PROCEDURE removeForeignKeyManager
AS
	ALTER TABLE MANAGER
		DROP CONSTRAINT EID_FOREIGN_KEY

-- create a table that contains the current version of the database schema
GO

CREATE TABLE versionTable(
	VERSION INT
)

INSERT INTO versionTable(VERSION)
VALUES
		(1) -- initial version

-- a table which contains the initial version, version after the execution of the procedure and the procedure that modifies the table

CREATE TABLE procedureTable(
	INITIAL_VERSION INT,
	FINAL_VERSION INT,
	PROCEDURE_NAME VARCHAR(MAX),
	PRIMARY KEY(INITIAL_VERSION, FINAL_VERSION)
)

INSERT INTO procedureTable
VALUES
		(1, 2, 'setBudgetOfDepartmentDecimal'),
		(2, 1, 'setBudgetOfDepartmentInt'),
		(2, 3, 'addFavoriteTypeOfProductToCustomer'),
		(3, 2, 'removeFavoriteTypeOfProductToCustomer'),
		(3, 4, 'addDefaultOrderPrice'),
		(4, 3, 'removeDefaultOrderPrice'),
		(4, 5, 'addManager'),
		(5, 4, 'dropManager'),
		(5, 6, 'addIDAndManagedDepartmentPrimaryKeyManager'),
		(6, 5, 'removeIDAndManagedDepartmentPrimaryKeyManager'),
		(6, 7, 'newCandidateKey'),
		(7, 6, 'removeCandidateKey'),
		(7, 8, 'newForeignKeyManager'),
		(8, 7, 'removeForeignKeyManager')

		
-- procedure to convert the database to a specified version
GO
CREATE OR ALTER PROCEDURE goToVersion(@newVersion INT)
AS
declare @curr int
    declare @var varchar(max)
    select @curr=version from versionTable

    if @newVersion > (select max(FINAL_VERSION) from procedureTable)
        raiserror ('Bad version', 10, 1)

    while @curr > @newVersion begin
        select @var=PROCEDURE_NAME from procedureTable where INITIAL_VERSION=@curr and FINAL_VERSION=@curr-1
        exec (@var)
        set @curr=@curr-1
    end

    while @curr < @newVersion begin
        select @var=PROCEDURE_NAME from procedureTable where INITIAL_VERSION=@curr and FINAL_VERSION=@curr+1
        exec (@var)
        set @curr=@curr+1
    end

    update versionTable set version=@newVersion

GO
EXEC goToVersion 2

SELECT *
FROM versionTable

SELECT *
FROM procedureTable

SELECT *
FROM MANAGER

SELECT *
FROM SYS.objects 
WHERE TYPE = 'D'

SELECT *
FROM SYS.objects
ORDER BY TYPE
