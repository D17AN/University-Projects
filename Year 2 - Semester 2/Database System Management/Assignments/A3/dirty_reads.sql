-- query console 1
SELECT @@SPID
SELECT @@TRANCOUNT
DBCC USEROPTIONS

DELETE FROM Magazine
DELETE FROM PublishingCompany

INSERT INTO PublishingCompany(company_id, name, number_of_employees) VALUES
	(1, 'name1', 1)

INSERT INTO Magazine(magazine_id, company_id, price, name) VALUES
	(1, 1, 200, 'name1'),
	(2, 1, 300, 'name2')

SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
-- set transaction isolation level read committed --solution

BEGIN TRAN
	SELECT * FROM Magazine
	EXEC sp_log_locks 'Dirty reads 2: after select'
	waitfor delay '00:00:10'
	SELECT * FROM Magazine
	waitfor delay '00:00:10'
	SELECT * FROM Magazine
COMMIT TRAN 

-- query console 2
SELECT @@SPID
SELECT @@TRANCOUNT
DBCC USEROPTIONS


BEGIN TRAN
	declare @oldData int
	declare @newData int
	UPDATE Magazine set @oldData = price, price = 1000, @newData = price WHERE magazine_id = 1
	EXEC sp_log_changes @oldData, @newData, 'Dirty reads 1: update', ''
	EXEC sp_log_locks 'Dirty reads 1: after update'
	waitfor delay '00:00:10'
	UPDATE Magazine set @oldData = price, price = 1500, @newData = price WHERE magazine_id = 1
	EXEC sp_log_changes @oldData, @newData, 'Dirty reads 1: update', ''
	EXEC sp_log_locks 'Dirty reads 1: after update'
	waitfor delay '00:00:10'
COMMIT TRAN