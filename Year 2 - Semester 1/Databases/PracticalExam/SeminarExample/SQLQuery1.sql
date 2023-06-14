/*
1) c
2) c
3) b
*/
--I
CREATE TABLE R(
	FK1 INT,
	FK2 INT,
	C1 VARCHAR(200),
	C2 VARCHAR(200),
	C3 INT,
	C4 INT,
	C5 VARCHAR(10),
	PRIMARY KEY(FK1, FK2)
)

insert into R (FK1, FK2, C1, C2, C3, C4, C5)
VALUES
('1', '1', 'Pisica pe acoperisul fierbinte', 'Tennessee Williams', '100', '20', 'AB'),
('1', '2', 'Conul Leonida fata cu reactiunea', 'Ion Luca Caragiale', '50', '50', 'CQ'),
('1', '3', 'Concert din muzica de Bach', 'Hortensia Papadat-Bengescu', '50', '10', 'QC'),
('2', '1', 'Fata babei si fata mosneagului', 'Ion Creanga', '100', '100', 'QM'),
('2', '2', 'Frumosii nebuni ai marilor orase', 'Fanus Neagu', '10', '10', 'BA'),
('2', '3', 'Frumoasa calatorie a ursilor panda povestita de un saxofonist care avea o iubita la Frankfurt', 'Matei Visniec', '100', '20', 'MQ'),
('3', '1', 'Mansarda la Paris cu vedere spre moarte', 'Matei Visniec', '200', '10', 'PQ'),
('3', '2', 'Richard al III-lea se interzice sau Scene din Viata lui Meyerhold', 'Matei Visniec', '100', '50', 'PQ'),
('3', '3', 'Masinaria Cehov. Nina sau despre fragilitatea pescarusilor impaiati', 'Matei Visniec', '100', '100', 'AZ'),
('4', '1', 'Omul de zapada care voia sa intalneasca soarele', 'Matei Visniec', '100', '100', 'CP'),
('4', '2', 'Extraterestrul care isi dorea ca amintere o pijama', 'Matei Visniec', '50', '10', 'CQ'),
('4', '3', 'O femeie draguta cu o floare si ferestre spre nord', 'Edward Radzinski', '10', '100', 'CP'),
('4', '4', 'Trenul din zori nu mai opreste aici', 'Tennessee Williams', '200', '200', 'MA')

SELECT C2, SUM(C3) TotalC3, AVG(C3) AvgC3
FROM R
WHERE C3 >= 100 OR C1 LIKE '%Pisica%'
GROUP BY C2
HAVING SUM(C3) > 100

SELECT *
FROM
(SELECT FK1, FK2, C3+C4 TotalC3C4
FROM R
WHERE FK1 = FK2) r1
INNER JOIN
(SELECT FK1, FK2, C5
FROM R
WHERE C5 LIKE '%Q%')r2 ON r1.FK1 = r2.FK1 and r1.FK2 = r2.FK2

GO
CREATE OR ALTER TRIGGER TrOnUpdate
ON R
FOR UPDATE
AS
DECLARE @total INT = 0
SELECT @total = SUM(i.C3 - d.C3)
FROM deleted d INNER JOIN inserted i ON d.FK1 = i.FK1 and d.FK2 = i.FK2
WHERE d.C3 < i.C3
PRINT @total

UPDATE R
SET C3 = 300
WHERE FK1 < FK2

--II
USE PracticalExamExample
GO
DROP TABLE RoutesStations
DROP TABLE Stations
DROP TABLE Routes 
DROP TABLE Trains
DROP TABLE TrainTypes

GO
create table TrainTypes
(
	TrainTypeID int primary key,
	TName varchar(50),
	TDescription varchar(50)
)

create table Trains
(
	TrainID int primary key,
	TName varchar(50),
	TrainTypeID int references TrainTypes(TrainTypeID)
)

create table Routes
(
	RouteID int primary key,
	RName varchar(50),
	TrainID int references Trains(TrainID)

)

create table Stations
(
StationID int primary key,
SName varchar(50) unique
)

create table RoutesStations
(
RouteID int references Routes(RouteID),
StationID int references Stations(StationID),
Arrival time,
Departure time,
primary key(RouteID, StationID)
)

GO
create or alter procedure uspUpdateStationOnRoute(@RName varchar(50), @SName varchar(50), @Arrival time, @Departure time) as
	declare @RouteID int, @StationID int
	if not exists (select * from Routes where RName = @RName)
	begin
		Raiserror('Invalid route name.', 16, 1)
	end
	if not exists(select * from Stations where SName = @SName)
	begin
		Raiserror('Invalid station name.', 16, 1)
	end
	
	select @RouteID = (select RouteID from Routes where RName = @RName),
		@StationID = (select StationID from Stations where SName = @SName)

	if exists (select * from RoutesStations where RouteID = @RouteID and StationID = @StationID)
		update RoutesStations
		set Arrival = @Arrival, Departure = @Departure
		where RouteID = @RouteID and StationID = @StationID
	else
		insert RoutesStations(RouteID, StationID, Arrival, Departure)
		values(@RouteID, @StationID, @Arrival, @Departure)

GO

insert TrainTypes values(1, 'tt1', 'd1'), (2, 'tt2', 'd2')
insert Trains values(1, 't1', 1), (2, 't2', 1), (3, 't3', 1)
insert Routes values(1, 'r1', 1), (2, 'r2', 1), (3, 'r3', 1)
insert Stations values(1, 's1'), (2, 's2'), (3, 's3')

select * from TrainTypes
select * from Trains
select * from Routes
select * from Stations


--uspUpdateStationOnRoute 'r4', 's1', '7:00AM', '7:10AM' --err
--uspUpdateStationOnRoute 'r1', 's4', '7:00AM', '7:10AM' --err
exec uspUpdateStationOnRoute 'r1', 's1', '7:00AM', '7:10AM'
exec uspUpdateStationOnRoute 'r1', 's2', '7:20AM', '7:30AM'
exec uspUpdateStationOnRoute 'r1', 's3', '7:40AM', '7:50AM'

exec uspUpdateStationOnRoute 'r2', 's1', '8:00AM', '8:10AM'
exec uspUpdateStationOnRoute 'r2', 's2', '8:20AM', '8:30AM'
exec uspUpdateStationOnRoute 'r2', 's3', '8:40AM', '8:50AM'

exec uspUpdateStationOnRoute 'r3', 's1', '9:00AM', '9:10AM'
exec uspUpdateStationOnRoute 'r3', 's2', '9:20AM', '9:30AM'

select	R.RName
from Routes R
where not exists
	(
	select StationID
	from Stations
	except 
	select StationID
	from RoutesStations
	where RouteID = R.RouteID
	)

GO
create function ufFilterStationsByNoRoutes(@R int)
returns table 
return
select SName
from Stations
where StationID in(
	select StationID
	from RoutesStations 
	group by StationID
	having count(*) > 2
	)
GO

select *
from ufFilterStationsByNoRoutes(1)

select StationID, RouteID from RoutesStations







