create table SportTypes(
	id int primary key,
	description varchar(256)
);

create table Sports(
	id int primary key,
	name varchar(256),
	description varchar(256),
	location varchar(256),
	type_id int,
	foreign key (type_id) references SportTypes(id)
);

create table Players(
	id int primary key,
	name VARCHAR(256),
	surname VARCHAR(256),
	dob date,
	gender varchar(256),
	sport_id int,
	foreign key (sport_id) references Sports(id)
);

create table Clubs(
	id int primary key,
	dob int,
	stars int,
);

create table ClubsPlayers(
	id int primary key,
	player_id int,
	foreign key (player_id) references Players(id),
	club_id int,
	foreign key (club_id) references Clubs(id),
	enrollment_date date,
	fee decimal (10, 2)
);


--drop table ClubsPlayers;
--drop table Clubs;
--drop table Players;
--drop table Sports;
--drop table SportTypes;


--insert into SportTypes (id, description) values (1, 'sport de echipa'), (2, 'sport de contact');

--insert into Sports (id, name, description, location, type_id) values 
--(1, 'box', 'incepatori', 'Cluj-Napoca', 2),
--(2, 'karate', 'intermediari', 'Bucuresti', 2),
--(3, 'fotbal', 'incepatori', 'Iasi', 1);

--insert into Players (id, name, surname, dob, gender, sport_id) values
--(1, 'Pascu', 'George', '2000-04-28', 'male', 1),
--(2, 'Petraru', 'Constantin', '2001-02-25', 'male', 3);

