-- query console 1
select @@SPID
select @@TRANCOUNT
DBCC USEROPTIONS

DELETE FROM Magazine
DELETE FROM PublishingCompany

INSERT INTO PublishingCompany(company_id, name, number_of_employees) VALUES
	(1, 'name1', 1)

INSERT INTO Magazine(magazine_id, company_id, price, name) VALUES
	(1, 1, 200, 'name1'),
	(2, 1, 300, 'name2')

BEGIN TRAN
	declare @oldData int
	declare @newData int
	waitfor delay '00:00:10'
	UPDATE Magazine set @oldData = price, price = 1000, @newData = price WHERE magazine_id = 1
	EXEC sp_log_changes @oldData, @newData, 'Non-repeatable reads 1: update', ''
	EXEC sp_log_locks 'Non-repeatable reads 1: after update'
COMMIT TRAN

-- query console 2
select @@SPID
select @@TRANCOUNT
DBCC USEROPTIONS

-- set transaction isolation level read committed
set transaction isolation level repeatable read -- solution
BEGIN TRAN
	SELECT * FROM Magazine
	EXEC sp_log_locks 'Non-repeatable reads 2: between selects'
	waitfor delay '00:00:10'
	SELECT * FROM Magazine
	EXEC sp_log_locks 'Non-repeatable reads 2: after both selects'
COMMIT TRAN

