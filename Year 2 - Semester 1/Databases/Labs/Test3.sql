exec addToTables 'DEPARTMENT'
exec addToTables 'WORK_AT'
exec addToTables 'EMPLOYEE'

GO
--drop view getDepartmentsWithMostEmployees
create or alter view getDepartmentsWithMostEmployees as
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
GO

exec addToViews 'getDepartmentsWithMostEmployees'
exec addToTests 'test3'
exec connectTableToTest 'DEPARTMENT', 'test3', 100, 1
exec connectTableToTest 'EMPLOYEE', 'test3', 100, 2
exec connectTableToTest 'WORK_AT', 'test3', 100, 3
exec connectViewToTest 'getDepartmentsWithMostEmployees', 'test3'

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

GO
--drop procedure populateTableEmployee
create or alter procedure populateTableEmployee(@rows int) as
	while @rows > 0 begin
		insert into EMPLOYEE(EID, LAST_NAME, FIRST_NAME, DOB, ADDRESS, SALARY) values
			(@rows,
			'LNAME',
			'FNAME',
			'1987-03-24',
			'NONE',
			floor(100000*rand())
			)
		set @rows = @rows - 1
	end

GO
--drop procedure populateTableWORK_AT
create or alter procedure populateTableWORK_AT(@rows int) as
	declare @did int
	declare @eid int
	while @rows > 0 begin
		set @did = (select top 1 DID from DEPARTMENT order by newid())
		set @eid = (select top 1 EID from EMPLOYEE order by newid())
		while exists(select * from WORK_AT where DID = @did and EID = @eid) begin
			set @did = (select top 1 DID from DEPARTMENT order by newid())
			set @eid = (select top 1 EID from EMPLOYEE order by newid())
		end 
		insert into WORK_AT(DID, EID, EMPLOYNMENT_DATE) values
			(
			@did,
			@eid,
			'1990-10-14'
			)
		set @rows = @rows - 1
	end


exec runTest 'test3'

select *
from TestRuns
