-- query console 1

select @@SPID
select @@TRANCOUNT
DBCC USEROPTIONS

DELETE FROM Magazine
DELETE FROM PublishingCompany

INSERT INTO PublishingCompany(company_id, name, number_of_employees) VALUES
	(1, 'name1', 1)

ALTER DATABASE ProjectDashboardDB  set allow_snapshot_isolation on

BEGIN TRAN
	declare @oldData varchar(100)
	declare @newData varchar(100)
	UPDATE PublishingCompany set @oldData = name, name = 'name2', @newData = name WHERE company_id = 1
	waitfor delay '00:00:10'
	exec sp_log_changes @oldData, @newData, 'Update conflict 1: update', null
	exec sp_log_locks 'Update conflic 1: after update'
	SELECT * FROM PublishingCompany
COMMIT TRAN

-- query console 2
select @@SPID
select @@TRANCOUNT
DBCC USEROPTIONS

SET TRANSACTION ISOLATION LEVEL SNAPSHOT

BEGIN TRAN
	declare @oldData1 varchar(100)
	declare @newData1 varchar(100)
	UPDATE PublishingCompany set @oldData1 = name, name = 'name3', @newData1 = name WHERE company_id = 1
	exec sp_log_changes @oldData1, @newData1, 'Update conflict 2: update', null
	exec sp_log_locks 'Update conflic 2: after update'
	SELECT * FROM PublishingCompany
COMMIT TRAN