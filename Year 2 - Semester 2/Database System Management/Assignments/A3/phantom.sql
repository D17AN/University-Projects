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
	waitfor delay '00:00:10'
	INSERT INTO Magazine(magazine_id, company_id, price, name) VALUES (3, 1, 400, 'name3')
	EXEC sp_log_changes null, 3, 'Phantom 1: insert', ''
	EXEC sp_log_locks 'Phantom 1: after insert'
COMMIT TRAN

-- query console 2
select @@SPID
select @@TRANCOUNT
DBCC USEROPTIONS

-- set transaction isolation level repeatable read
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE --solution
BEGIN TRAN
	SELECT * FROM Magazine where magazine_id = 3
	EXEC sp_log_locks 'Phantom 2: between selects'
	waitfor delay '00:00:10'
	SELECT * FROM Magazine
	EXEC sp_log_locks 'Phantom 2: after both selects'
COMMIT TRAN
