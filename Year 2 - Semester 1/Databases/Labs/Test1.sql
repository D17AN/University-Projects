exec addToTables 'PRODUCT'
select *
from Tables
select *
from Views
GO
-- drop view getProductsOfTypeWheyUnder200
create or alter view getProductsOfTypeWheyUnder200 as
	SELECT P.NAME
	FROM PRODUCT P
	WHERE P.TYPE LIKE '%WHEY%' AND P.NAME IN (SELECT P1.NAME FROM PRODUCT P1 WHERE P1.PRICE < 200) 

GO
exec addToViews 'getProductsOfTypeWheyUnder200'
exec addToTests 'test1'
exec connectTableToTest 'PRODUCT', 'test1', 1000, 1
exec connectViewToTest 'getProductsOfTypeWheyUnder200', 'test1'

-- drop procedure populateTablePRODUCT
GO
create or alter procedure populateTablePRODUCT(@rows int) as
	while @rows > 0 begin
		insert into PRODUCT(PID, TYPE, DESCRIPTION, PRICE, NAME) values (@rows, 'WHEY', 'TESTING', floor(rand()*1000), 'NAME')
		set @rows = @rows - 1
	end

GO
execute runTest 'test1'

select *
from TestRuns
select *
from TestRunTables

