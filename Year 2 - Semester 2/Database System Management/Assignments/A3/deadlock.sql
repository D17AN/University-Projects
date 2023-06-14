-- query console 1
select @@TRANCOUNT
select @@SPID

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
	UPDATE Magazine set @oldData = price, price = 1000, @newData = price WHERE magazine_id = 1
	EXEC sp_log_changes @oldData, @newData, 'Deadlock 1: update 1', ''
	EXEC sp_log_locks 'Deadlock 1: between updates'
	waitfor delay '00:00:10'
	UPDATE Magazine set @oldData = price, price = 1000, @newData = price WHERE magazine_id = 2
	EXEC sp_log_changes @oldData, @newData, 'Deadlock 1: update 2', ''
COMMIT TRAN

-- query console 2
select @@TRANCOUNT
select @@SPID

BEGIN TRAN
	declare @oldData1 int
	declare @newData1 int
	UPDATE Magazine set @oldData1 = price, price = 1000, @newData1 = price WHERE magazine_id = 2
	EXEC sp_log_changes @oldData1, @newData1, 'Deadlock 2: update 1', ''
	EXEC sp_log_locks 'Deadlock 2: between updates'
	waitfor delay '00:00:05'
	UPDATE Magazine set @oldData1 = price, price = 1000, @newData1 = price WHERE magazine_id = 1
	EXEC sp_log_changes @oldData1, @newData1, 'Deadlock 2: update 2', ''
COMMIT TRAN


select * from LogLocks
select * from LogChanges

delete from LogLocks
delete from LogChanges