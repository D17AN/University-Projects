USE [Supplement Sportive Company]
/*
a table with a single-column primary key and no foreign keys => EMPLOYEE
a table with a single-column primary key and at least one foreign key => FACTORY
multi-column primary key table => WORK_AT


3 views:
- a view with a select statement operating on one table
All the products of type whey and are < 200
SELECT P.NAME
FROM PRODUCT P
WHERE P.TYPE LIKE '%WHEY%' AND P.NAME IN (SELECT P1.NAME FROM PRODUCT P1 WHERE P1.PRICE < 200) 

- a view with a select statement operating on at least 2 tables
INNER JOIN | GET FOR ORDER > 200 THE NAME OF THE CUSTOMER

SELECT C.LAST_NAME, C.FIRST_NAME, O.CID, O.DESCRIPTION, O.PRICE 
FROM ORDER_ O INNER JOIN CUSTOMER C ON C.CID = O.CID
WHERE O.PRICE > 200

- a view with a select statement that has a Group By clause and operates on at least 2 tables.

--2) Print the departments with the most employees.
SELECT D.DID, D.NAME, COUNT(*) AS EMPLOYEES
FROM DEPARTMENT D INNER JOIN WORK_AT WT ON D.DID = WT.DID INNER JOIN EMPLOYEE E ON E.EID = WT.EID
GROUP BY D.DID, D.NAME
HAVING COUNT(*) = (
		/*get the max nr of employees for a department*/
		SELECT MAX(P.C)
		FROM(
				SELECT COUNT(*) C
				FROM DEPARTMENT D2 INNER JOIN WORK_AT WT2 ON D2.DID = WT2.DID INNER JOIN EMPLOYEE E2 ON E2.EID = WT2.EID
				GROUP BY D2.DID, D2.NAME
		)P
)
*/
DROP PROCEDURE addToTables
DROP PROCEDURE addToViews
DROP PROCEDURE addToTests
DROP PROCEDURE connectTableToTest
DROP PROCEDURE connectViewToTest
DROP PROCEDURE runTest

GO
create or alter procedure addToTables (@tableName varchar(50)) as
    if @tableName in (select Name from Tables) begin
        print 'Table already present in Tables'
        return
    end
    if @tableName not in (select TABLE_NAME from INFORMATION_SCHEMA.TABLES) begin
        print 'Table not present in the database'
        return
    end
    insert into Tables (Name) values (@tableName)


GO
create or alter procedure addToViews (@viewName varchar(50)) as
    if @viewName in (select Name from Views) begin
        print 'View already present in Views'
        return
    end
    if @viewName not in (select TABLE_NAME from INFORMATION_SCHEMA.VIEWS) begin
        print 'View not present in the database'
        return
    end
    insert into Views (Name) values (@viewName)

GO
create or alter procedure addToTests (@testName varchar(50)) as
    if @testName in (select Name from Tests) begin
        print 'Test already present in Tests'
        return
    end
    insert into Tests (Name) values (@testName)

GO
create or alter procedure connectTableToTest (@tableName varchar(50), @testName varchar(50), @rows int, @pos int) as
    if @tableName not in (select Name from Tables) begin
        print 'Table not present in Tables'
        return
    end
    if @testName not in (select Name from Tests) begin
        print 'Tests not present in Tests'
        return
    end
    if exists(
        select *
        from TestTables T1 join Tests T2 on T1.TestID = T2.TestID
        where T2.Name=@testName and Position=@pos
        ) begin
        print 'Position provided conflicts with previous positions'
        return
    end
    insert into TestTables (TestID, TableID, NoOfRows, Position) values (
        (select Tests.TestID from Tests where Name=@testName),
        (select Tables.TableID from Tables where Name=@tableName),
        @rows,
        @pos
    )

GO
create or alter procedure connectViewToTest (@viewName varchar(50), @testName varchar(50)) as
if @viewName not in (select Name from Views) begin
    print 'View not present in Views'
    return
end
if @testName not in (select Name from Tests) begin
    print 'Tests not present in Tests'
    return
end
insert into TestViews (TestID, ViewID) values (
    (select Tests.TestID from Tests where Name=@testName),
    (select Views.ViewID from Views where Name=@viewName)
)

--modifies(up)
-- Delete data from a table
GO
CREATE OR ALTER PROCEDURE deleteDataFromTable (@tableID INT) AS
BEGIN
	IF @tableID NOT IN (SELECT [TableID] FROM [Tables])
	BEGIN
		PRINT 'Table not present in Tables.'
		RETURN
	END
	DECLARE @tableName NVARCHAR(50) = (SELECT [Name] FROM [Tables] WHERE TableID = @tableID)
	PRINT 'Delete data from table ' + @tableName
	DECLARE @query NVARCHAR(100) = N'DELETE FROM ' + @tableName
	PRINT @query
	EXEC sp_executesql @query
END

-- Delete data from all the tables involved in a test
GO
CREATE OR ALTER PROCEDURE deleteDataFromAllTables (@testID INT) AS
BEGIN
	IF @testID NOT IN (SELECT [TestID] FROM [Tests])
	BEGIN
		PRINT 'Test not present in Tests.'
		RETURN
	END
	PRINT 'Delete data from all tables for the test ' + CONVERT(VARCHAR, @testID)
	DECLARE @tableID INT
	DECLARE @pos INT
	-- cursor to iterate through the tables in the descending order of their position
	DECLARE allTableCursorDesc CURSOR LOCAL FOR
		SELECT T1.TableID, T1.Position 
		FROM TestTables T1 
		INNER JOIN Tests T2 ON T2.TestID = T1.TestID
		WHERE T2.TestID = @testID
		ORDER BY T1.Position DESC

	OPEN allTableCursorDesc
	FETCH allTableCursorDesc INTO @tableID, @pos
	WHILE @@FETCH_STATUS = 0 
	BEGIN
		EXEC deleteDataFromTable @tableID
		FETCH NEXT FROM allTableCursorDesc INTO @tableID, @pos
	END
	CLOSE allTableCursorDesc
	DEALLOCATE allTableCursorDesc
END
--modifies(bottom)

GO
create or alter procedure runTest (@testName varchar(50)) as
    if @testName not in (select Name from Tests) begin
        print 'test not in Tests'
        return
    end
    declare @command varchar(100)
    declare @testStartTime datetime2
    declare @startTime datetime2
    declare @endTime datetime2
    declare @table varchar(50)
    declare @rows int
    declare @pos int
    declare @view varchar(50)
    declare @testId int
    select @testId=TestID from Tests where Name=@testName
    declare @testRunId int
    set @testRunId = (select max(TestRunID)+1 from TestRuns)
    if @testRunId is null
        set @testRunId = 0
    declare tableCursor cursor local scroll for
        select T1.Name, T2.NoOfRows, T2.Position
        from Tables T1 join TestTables T2 on T1.TableID = T2.TableID
        where T2.TestID = @testId
        order by T2.Position
    declare viewCursor cursor local for
        select V.Name
        from Views V join TestViews TV on V.ViewID = TV.ViewID
        where TV.TestID = @testId

    set @testStartTime = sysdatetime()
    open tableCursor
    fetch last from tableCursor into @table, @rows, @pos
    while @@FETCH_STATUS = 0 begin
        exec ('delete from '+ @table)
        fetch prior from tableCursor into @table, @rows, @pos
    end
    close tableCursor

    open tableCursor
    SET IDENTITY_INSERT TestRuns ON
    insert into TestRuns (TestRunID, Description, StartAt)values (@testRunId, 'Tests results for: ' + @testName, @testStartTime)
    SET IDENTITY_INSERT TestRuns OFF
    fetch tableCursor into @table, @rows, @pos
    while @@FETCH_STATUS = 0 begin
        set @command = 'populateTable' + @table
        if @command not in (select ROUTINE_NAME from INFORMATION_SCHEMA.ROUTINES) begin
            print @command + 'does not exist'
            return
        end
        set @startTime = sysdatetime()
        exec @command @rows
        set @endTime = sysdatetime()
        insert into TestRunTables (TestRunID, TableId, StartAt, EndAt) values (@testRunId, (select TableID from Tables where Name=@table), @startTime, @endTime)
        fetch tableCursor into @table, @rows, @pos
    end
    close tableCursor
    deallocate tableCursor

    open viewCursor
    fetch viewCursor into @view
    while @@FETCH_STATUS = 0 begin
        set @command = 'select * from ' + @view
        set @startTime = sysdatetime()
        exec (@command)
        set @endTime = sysdatetime()
        insert into TestRunViews (TestRunID, ViewID, StartAt, EndAt) values (@testRunId, (select ViewID from Views where Name=@view), @startTime, @endTime)
        fetch viewCursor into @view
    end
    close viewCursor
    deallocate viewCursor

	--here
	--deletion
	DECLARE allTestsCursor CURSOR LOCAL FOR
		SELECT *
		FROM Tests
		WHERE Tests.Name = @testName

	declare @testID_allTestsCursor int
	declare @testName_allTestsCursor varchar(50)
	OPEN allTestsCursor
	FETCH allTestsCursor INTO @testID_allTestsCursor, @testName_allTestsCursor
	while @@FETCH_STATUS = 0
	BEGIN
		exec deleteDataFromAllTables @testID_allTestsCursor
		FETCH NEXT FROM allTestsCursor INTO @testID_allTestsCursor, @testName_allTestsCursor
	END
	close allTestsCursor
	deallocate allTestsCursor
	--here
    update TestRuns
    set EndAt=sysdatetime()
    where TestRunID = @testRunId


