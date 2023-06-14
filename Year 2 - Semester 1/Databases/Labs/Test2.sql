exec addToTables 'ORDER_'
exec addToTables 'CUSTOMER'
exec addToTables 'DEPARTMENT'

GO
--drop view getCustomersForOrdersMoreThan200
create or alter view getCustomersForOrdersMoreThan200 as
	SELECT C.LAST_NAME, C.FIRST_NAME, O.CID, O.DESCRIPTION, O.PRICE 
	FROM ORDER_ O INNER JOIN CUSTOMER C ON C.CID = O.CID
	WHERE O.PRICE > 200

GO

exec addToViews 'getCustomersForOrdersMoreThan200'
exec addToTests 'test2'
exec connectTableToTest 'ORDER_', 'test2', 1200, 2
exec connectTableToTest 'CUSTOMER', 'test2', 600, 1
exec connectTableToTest 'DEPARTMENT', 'test2', 10, 3
exec connectViewToTest 'getCustomersForOrdersMoreThan200', 'test2'

GO 
--drop procedure populateTableORDER_
create or alter procedure populateTableORDER_(@rows int) as
	while @rows > 0 begin
		insert into ORDER_(OID, DESCRIPTION, PRICE, CID) values
			(@rows,
			'TEST',
			floor(1000*rand()),
			(select top 1 CID from CUSTOMER order by newid()))
		set @rows = @rows - 1
	end

GO
--drop procedure populateTableCustomer
create or alter procedure populateTableCustomer(@rows int) as
	while @rows > 0 begin
		insert into CUSTOMER(CID, LAST_NAME, FIRST_NAME, DID) values
			(@rows,
			'NAMETEST',
			'NAMETEST',
			(select top 1 DID from DEPARTMENT order by newid()))
		set @rows = @rows - 1
	end

GO
--drop procedure populateTableDepartment
create or alter procedure populateTableDepartment(@rows int) as
	while @rows > 0 begin
		insert into DEPARTMENT(DID, NAME, DESCRIPTION, BUDGET) values
			(@rows,
			'NAME',
			'DESCRIPTION',
			floor(1000000*rand()))
		set @rows = @rows - 1
	end


execute runTest 'test2'
select *
from TestRuns

		



