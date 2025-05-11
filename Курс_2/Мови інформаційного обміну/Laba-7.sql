-- 513-і, Золотухин Андрій, Лабораторна № 7, Варіант 2. Movie Database

DROP DATABASE IF EXISTS Movie;
CREATE DATABASE IF NOT EXISTS Movie;


DROP TABLE IF EXISTS Actors;
CREATE TABLE IF NOT EXISTS Actors (
	actor_id SERIAL,
	First_name VARCHAR(25) NOT NULL,
	Last_name VARCHAR(25) NOT NULL,
	Gender BOOLEAN NOT NULL,
	Birth_date DATE NOT NULL
);


DROP TABLE IF EXISTS Directors;
CREATE TABLE IF NOT EXISTS Directors (
	director_id SERIAL,
	First_name VARCHAR(25) NOT NULL,
	Last_name VARCHAR(25) NOT NULL,
	Gender BOOLEAN NOT NULL,
	Birth_date DATE NOT NULL
);


DROP TABLE IF EXISTS Studios;
CREATE TABLE IF NOT EXISTS Studios (
	studio_id SERIAL,
	studio_name VARCHAR(25) NOT NULL,
	address VARCHAR(25) NOT NULL,
	phone_number VARCHAR(25) NOT NULL
);


DROP TABLE IF EXISTS Ratings;
CREATE TABLE IF NOT EXISTS Ratings (
	rating_id SERIAL,
	rating_name VARCHAR(25) NOT NULL
);


DROP TABLE IF EXISTS Movies;
CREATE TABLE IF NOT EXISTS Movies (
	movie_id SERIAL,
	title VARCHAR(25) NOT NULL,
	release_year YEAR NOT NULL,
	runtime INTERVAL NOT NULL,
	rating_id INTEGER CHECK (rating_id >= 0),
	studio_id INTEGER CHECK (studio_id >= 0),
	director_id INTEGER CHECK (director_id >= 0),
  
	CONSTRAINT rating FOREIGN KEY (rating_id) REFERENCES Ratings (rating_id) ON DELETE SET NULL ON UPDATE CASCADE,
	CONSTRAINT studio FOREIGN KEY (studio_id) REFERENCES Studios (studio_id) ON DELETE SET NULL ON UPDATE CASCADE,
	CONSTRAINT director FOREIGN KEY (director_id) REFERENCES Directors (director_id) ON DELETE SET NULL ON UPDATE CASCADE
  
);









