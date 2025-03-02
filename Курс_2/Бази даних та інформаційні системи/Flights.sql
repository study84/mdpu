show databases;
show tables;

#Країни
#drop table if exists countries;
create table if not exists countries (
	country int primary key AUTO_INCREMENT,
  create_at datetime not null default now(),
  name varchar(100) not null comment = 'назва',
  name_alpha3 varchar(3) not null comment = 'скорочена назва'
) comment = 'Країни';
insert into countries (name, name_alpha3) values
	('Австрія', 'AUT'), ('Бельгія', 'BEL'), ('Болгарія', 'BGR'), ('Хорватія', 'HRV'), ('Кіпр', 'CYP'), ('Чехія', 'CZE'), ('Данія', 'DNK'), ('Естонія', 'EST'), ('Фінляндія', 'FIN'), ('Франція', 'FRA'),
  ('Німеччина', 'DEU'), ('Греція', 'GRC'), ('Угорщина', 'HUN'), ('Ірландія', 'IRL'), ('Італія', 'ITA'), ('Латвія', 'LVA'), ('Литва', 'LTU'), ('Люксембург', 'LUX'), ('Мальта', 'MLT'), ('Нідерланди', 'NLD'),
  ('Польща', 'POL'), ('Португалія', 'PRT'), ('Румунія', 'ROU'), ('Словаччина', 'SVK'), ('Словенія', 'SVN'), ('Іспанія', 'ESP'), ('Швеція', 'SWE');
select * from countries;
#SELECT REGEXP_LIKE('CamelCase', 'CAMELCASE');
#select * from countries where REGEXP_LIKE(name, '^[А|С]');

#------------------------------------------------------------------------------------------------------------------------------------------------

#drop table if exists cities;
create table if not exists cities ( # сгенерируй на укр 3 города страны Бельгія в формате (2, 'название', столица(0/1), utc(только число))
	city int primary key AUTO_INCREMENT,
  create_at datetime not null default now(),
  country int not null,
  name varchar(80) not null,
  capital boolean,
  UTC tinyint not null CHECK (UTC BETWEEN -23 AND 23),
  ##CONSTRAINT fk_country
  FOREIGN KEY (country) REFERENCES countries(country)
) comment = 'міста';
insert into cities(country, name, capital, UTC) values
	(1, 'Відень', 1, 1), (1, 'Грац', 0, 1), (1, 'Лінц', 0, 1),
  (2, 'Брюссель', 1, 1), (2, 'Антверпен', 0, 1), (2, 'Гент', 0, 1),
  (3, 'Софія', 1, 2), (3, 'Пловдив', 0, 2), (3, 'Варна', 0, 2),
  (4, 'Загреб', 1, 2), (4, 'Спліт', 0, 2), (4, 'Рієка', 0, 2),
  (5, 'Никосия', 1, 2), (5, 'Лимасол', 0, 2), (5, 'Ларнака', 0, 2),
  (6, 'Прага', 1, 1), (6, 'Брно', 0, 1), (6, 'Острава', 0, 1),
  (7, 'Копенгаген', 1, 1), (7, 'Орхус', 0, 1), (7, 'Оденсе', 0, 1),
  (8, 'Таллин', 1, 2), (8, 'Тарту', 0, 2), (8, 'Нарва', 0, 2),
  (9, 'Хельсинки', 1, 2), (9, 'Эспоо', 0, 2), (9, 'Тампере', 0, 2),
  (10, 'Париж', 1, 1), (10, 'Марсель', 0, 1), (10, 'Лион', 0, 1), 
  (11, 'Берлин', 1, 1), (11, 'Мюнхен', 0, 1), (11, 'Гамбург', 0, 1),
  (12, 'Афины', 1, 2), (12, 'Салоники', 0, 2), (12, 'Патры', 0, 2),
  (13, 'Будапешт', 1, 1), (13, 'Дебрецен', 0, 1), (13, 'Сегед', 0, 1),
  (14, 'Дублин', 1, 0), (14, 'Корк', 0, 0), (14, 'Лимерик', 0, 0),
  (15, 'Рим', 1, 1), (15, 'Милан', 0, 1), (15, 'Неаполь', 0, 1),
  (16, 'Рига', 1, 2), (16, 'Даугапилс', 0, 2), (16, 'Лиепая', 0, 2),
  (17, 'Вильнюс', 1, 2), (17, 'Каунас', 0, 2), (17, 'Клайпеда', 0, 2),
  (18, 'Люксембург', 1, 1), (18, 'Эттельбрук', 0, 1), (18, 'Дифферданж', 0, 1),
  (19, 'Ла Валлетта', 1, 1), (19, 'Моста', 0, 1), (19, 'Слима', 0, 1),
  (20, 'Амстердам', 1, 1), (20, 'Роттердам', 0, 1), (20, 'Утрехт', 0, 1),
  (21, 'Варшава', 1, 1), (21, 'Краков', 0, 1), (21, 'Вроцлав', 0, 1),
  (22, 'Лиссабон', 1, 0), (22, 'Порту', 0, 0), (22, 'Авиору', 0, 0),
  (23, 'Бухарест', 1, 2), (23, 'Клуж-Напока', 0, 2), (23, 'Тимишоара', 0, 2),
  (24, 'Братислава', 1, 1), (24, 'Кошице', 0, 1), (24, 'Нитра', 0, 1),
  (25, 'Любляна', 1, 1), (25, 'Марибор', 0, 1), (25, 'Целе', 0, 1),
  (26, 'Мадрид', 1, 1), (26, 'Барселона', 0, 1), (26, 'Валенсия', 0, 1),
  (27, 'Стокгольм', 1, 1), (27, 'Гётеборг', 0, 1), (27, 'Мальмё', 0, 1);
select * from cities;
#------------------------------------------------------------------------------------------------------------------------------------------------


#drop table if exists airports;
create table if not exists airports (
	airport int primary key AUTO_INCREMENT,
  create_at datetime not null default now(),
  country int not null,
  city int not null,
  name varchar(100) not null,
  IATA varchar(3) not null comment = 'використовується для продажу квитків, планування рейсів і взаємодії з пасажирами',
  ICAO varchar(4) not null comment = 'використовується для авіаційної навігації, контролю повітряного руху та операційних потреб, таких як авіаційні карти і маршрути',
  build year,
  runway tinyint unsigned not null comment = 'кількість впс',
  international boolean not null comment = 'статус міжнародного',
  Latitude DECIMAL(9, 6) not null,
  Longitude DECIMAL(9, 6) not null,
  FOREIGN KEY (country) REFERENCES countries(country),
  FOREIGN KEY (city) REFERENCES cities(city)  
) comment = 'аеропорти';

select cn.country, cn.name, ct.city, ct.name, 'назва аеропорту?', 'IATA?', 'ICAO?', 'дата побудови?', 'кількість ЗПС?', 'міжнародний?', 'Latitude?', 'Longitude?'
from countries cn
inner join cities ct on ct.country = cn.country;

insert into airports(country, city, name, IATA, ICAO, build, runway, international, Latitude, Longitude) values
	(1, 1, 'Vienna International Airport', 'VIE', 'LOWW', 1938, 1, 1, 48.1100, 16.5690),
  (1, 2, 'Graz Airport', 'GRZ', 'LOWG', 1913, 1, 1, 46.9925, 15.4400),
  (1, 3, 'Linz Airport', 'LNZ', 'LOWL', 1955, 1, 1, 48.2133, 14.1875),
  (2, 4, 'Brussels Airport', 'BRU', 'EBBR', 1958, 1, 1, 50.9019, 4.4844),
  (2, 5, 'Antwerp International Airport', 'ANR', 'EBAW', 1923, 1, 1, 51.1894, 4.4600),
  (2, 6, 'Ghent Airport', 'GNE', 'EBGM', 1989, 1, 1, 51.0378, 3.5661),
  (3, 7, 'Sofia Airport', 'SOF', 'LBSF', 1937, 1, 1, 42.6957, 23.4060),
  (3, 8, 'Plovdiv Airport', 'PDV', 'LBPD', 1960, 1, 1, 42.1264, 24.8011),
  (3, 9, 'Varna Airport', 'VAR', 'LBWN', 1962, 1, 1, 43.2300, 27.9147),
  (4, 10, 'Zagreb Airport', 'ZAG', 'LDZA', 1962, 1, 1, 45.7420, 16.0686),
  (4, 11, 'Split Airport', 'SPU', 'LDSP', 1966, 1, 1, 43.5381, 16.2986),
  (4, 12, 'Rijeka Airport', 'RJK', 'LDRI', 1970, 1, 1, 45.2171, 14.5694),
  (5, 13, 'Nicosia International Airport', 'NIC', 'LCNC', 1968, 1, 1, 35.1397, 33.4306),
  (5, 14, 'Limassol Airport', 'QFZ', 'LCOM', 1974, 1, 1, 34.7000, 33.0500),
  (5, 15, 'Larnaca International Airport', 'LCA', 'LCLK', 1975, 1, 1, 34.8753, 33.6248),
  (6, 16, 'Václav Havel Airport Prague', 'PRG', 'LKPR', 1937, 1, 1, 50.1008, 14.26),
  (6, 17, 'Brno Tuřany Airport', 'BRQ', 'LKTB', 1956, 1, 1, 49.2011, 16.6903),
  (6, 18, 'Ostrava Leos Janacek Airport', 'OSR', 'LKMT', 1959, 1, 1, 49.7217, 18.2922),
  (7, 19, 'Copenhagen Airport', 'CPH', 'EKCH', 1925, 1, 1, 55.6170, 12.6560),
  (7, 20, 'Aarhus Airport', 'AAR', 'EKAH', 1961, 1, 1, 56.3000, 10.6000),
  (7, 21, 'Odense Airport', 'ODE', 'EKOD', 1975, 1, 1, 55.4500, 10.4500),
  (8, 22, 'Tallinn Airport', 'TLL', 'EETN', 1936, 1, 1, 59.4139, 24.8328),
  (8, 23, 'Tartu Airport', 'TAY', 'EETR', 1946, 1, 1, 58.2947, 26.7411),
  (8, 24, 'Narva Airport', 'NRV', 'EENR', 1975, 1, 1, 59.3833, 28.2000),
  (9, 25, 'Helsinki-Vantaa Airport', 'HEL', 'EFHK', 1952, 1, 1, 60.3172, 24.9633),
  (9, 26, 'Espoo Airport', 'ESQ', 'EFES', 1989, 1, 1, 60.2167, 24.6667),
  (9, 27, 'Tampere-Pirkkala Airport', 'TMP', 'EFTP', 1936, 1, 1, 61.4147, 23.5889),
  (10, 28, 'Charles de Gaulle Airport', 'CDG', 'LFPG', 1966, 1, 1, 49.0097, 2.5478),
  (10, 29, 'Marseille Provence Airport', 'MRS', 'LFML', 1922, 1, 1, 43.4400, 5.2217),
  (10, 30, 'Lyon–Saint-Exupéry Airport', 'LYS', 'LFLL', 1975, 1, 1, 45.7269, 5.0814),
  (11, 31, 'Berlin Brandenburg Airport', 'BER', 'EDDB', 2020, 1, 1, 52.3667, 13.5033),
  (11, 32, 'Munich Airport', 'MUC', 'EDDM', 1992, 1, 1, 48.3538, 11.7861),
  (11, 33, 'Hamburg Airport', 'HAM', 'EDDH', 1911, 1, 1, 53.6300, 9.9886),
  (12, 34, 'Athens Eleftherios Venizelos Airport', 'ATH', 'LGAV', 2001, 1, 1, 37.9364, 23.9444),
  (12, 35, 'Thessaloniki Airport', 'SKG', 'LGTS', 1930, 1, 1, 40.5194, 22.9700),
  (12, 36, 'Patras Araxos Airport', 'GPA', 'LGAX', 1981, 1, 1, 38.2500, 21.4333),
  (13, 37, 'Budapest Ferenc Liszt International Airport', 'BUD', 'LHBP', 1950, 1, 1, 47.4419, 19.2614),
  (13, 38, 'Debrecen International Airport', 'DEB', 'LHDC', 2002, 1, 1, 47.5300, 21.6250),
  (13, 39, 'Szeged Airport', 'QZD', 'LHSZ', 1938, 1, 1, 46.2522, 20.1450),
  (14, 40, 'Dublin Airport', 'DUB', 'EIDW', 1940, 1, 1, 53.4214, -6.2700),
  (14, 41, 'Cork Airport', 'ORK', 'EICK', 1961, 1, 1, 51.8419, -8.4917),
  (14, 42, 'Shannon Airport', 'SNN', 'EINN', 1942, 1, 1, 52.7017, -8.9242),
  (15, 43, 'Leonardo da Vinci International Airport', 'FCO', 'LIRF', 1960, 1, 1, 41.8003, 12.2389),
  (15, 44, 'Milan Malpensa Airport', 'MXP', 'LIMC', 1948, 1, 1, 45.6300, 8.7239),
  (15, 45, 'Naples International Airport', 'NAP', 'LIRN', 1950, 1, 1, 40.8867, 14.2900),
  (16, 46, 'Riga International Airport', 'RIX', 'EVRA', 1973, 1, 1, 56.9236, 23.9719),
  (16, 47, 'Daugavpils International Airport', 'DGP', 'EYDA', 1960, 1, 1, 55.8667, 26.5000),
  (16, 48, 'Liepaja International Airport', 'LPX', 'EVLA', 1976, 1, 1, 56.5100, 21.0500),
  (17, 49, 'Vilnius Airport', 'VNO', 'EYVI', 1932, 1, 1, 54.6342, 25.2850),
  (17, 50, 'Kaunas Airport', 'KUN', 'EYKA', 1988, 1, 1, 54.9617, 23.9733),
  (17, 51, 'Palanga International Airport', 'PLQ', 'EYPA', 1937, 1, 1, 55.9794, 21.1000),
  (18, 52, 'Luxembourg Airport', 'LUX', 'ELLX', 1946, 1, 1, 49.6236, 6.2114),
  (18, 53, 'Findel Airport', 'FNZ', 'ELLX', 1960, 1, 1, 49.6125, 6.2019),
  (18, 54, 'Ettelbruck Airport', 'ETR', 'ELET', 1971, 1, 1, 49.8475, 6.0697),
  (19, 55, 'Madrid Barajas Adolfo Suárez Airport', 'MAD', 'LEMD', 1928, 1, 1, 40.4713, -3.5667),
  (19, 56, 'Barcelona El Prat Airport', 'BCN', 'LEBL', 1918, 1, 1, 41.2975, 2.0783),
  (19, 57, 'Malaga Airport', 'AGP', 'LEMG', 1919, 1, 1, 36.6749, -4.4992),
  (20, 58, 'Stockholm Arlanda Airport', 'ARN', 'ESSA', 1962, 1, 1, 59.6497, 17.9186),
  (20, 59, 'Gothenburg Landvetter Airport', 'GOT', 'ESGG', 1977, 1, 1, 57.6625, 12.2972),
  (20, 60, 'Malmö Airport', 'MMX', 'ESMS', 1972, 1, 1, 55.5300, 13.3744),
  (21, 61, 'Warsaw Chopin Airport', 'WAW', 'EPWA', 1934, 2, 1, 52.1650, 20.9670),
  (21, 62, 'John Paul II Kraków–Balice International Airport', 'KRK', 'EPKK', 1967, 2, 1, 50.0772, 19.7844),
  (21, 63, 'Wrocław Copernicus Airport', 'WRO', 'EPWR', 1938, 1, 1, 51.1020, 16.8850),
  (22, 64, 'Lisbon Humberto Delgado Airport', 'LIS', 'LPPT', 1942, 2, 1, 38.7812, -9.1355),
  (22, 65, 'Francisco Sá Carneiro Airport', 'OPO', 'LPPR', 1945, 1, 1, 41.2486, -8.6811),
  (22, 66, 'Beja Airport', 'BYJ', 'LPBJ', 1989, 1, 1, 38.4978, -7.8703),
  (23, 67, 'Henri Coandă International Airport', 'OTP', 'LRBB', 1969, 2, 1, 44.5717, 26.0850),
  (23, 68, 'Cluj-Napoca International Airport', 'CLJ', 'LRCL', 1932, 1, 1, 46.7719, 23.6889),
  (23, 69, 'Timișoara Traian Vuia International Airport', 'TSR', 'LRTR', 1936, 1, 1, 45.8772, 21.3389),
  (24, 70, 'Bratislava Airport', 'BTS', 'LZIB', 1951, 1, 1, 48.1700, 17.2122),
  (24, 71, 'Košice International Airport', 'KSC', 'LZKZ', 1953, 1, 1, 48.6631, 21.2389),
  (24, 72, 'Nitra Airport', 'NIT', 'LZNI', 1947, 1, 1, 48.3078, 18.0736),
  (25, 73, 'Ljubljana Jože Pučnik Airport', 'LJU', 'LJLJ', 1963, 1, 1, 46.2231, 14.4572),
  (25, 74, 'Maribor Edvard Rusjan Airport', 'MBX', 'LJMB', 1963, 1, 1, 46.5572, 15.6453),
  (25, 75, 'Celje Airport', 'CLJ', 'LJCE', 1947, 1, 1, 46.2681, 15.2697),
  (26, 76, 'Adolfo Suárez Madrid–Barajas Airport', 'MAD', 'LEMD', 1931, 4, 1, 40.4740, -3.5600),
  (26, 77, 'Barcelona El Prat Airport', 'BCN', 'LEBL', 1918, 2, 1, 41.2975, 2.0780),
  (26, 78, 'Valencia Airport', 'VLC', 'LEVC', 1933, 2, 1, 39.4897, -0.4815),
  (27, 79, 'Stockholm Arlanda Airport', 'ARN', 'ESSA', 1962, 4, 1, 59.6519, 17.9186),
  (27, 80, 'Gothenburg Landvetter Airport', 'GOT', 'ESGG', 1977, 2, 1, 57.6625, 12.2792),
  (27, 81, 'Malmö Airport', 'MMX', 'ESMS', 1972, 2, 1, 55.5400, 13.3750);
select * from airports;
#------------------------------------------------------------------------------------------------------------------------------------------------


#drop table if exists airplane_models;
create table if not exists airplane_models(
	airplane SMALLINT primary key AUTO_INCREMENT,
  create_at datetime not null default now(),
  brend varchar(16) not null comment = 'бренд',
  model varchar(16) not null comment = 'модель',
  creation year not null comment = 'рік створення',
  weight MEDIUMINT UNSIGNED not null comment = 'вага',
  wing_span float(3,1) not null comment = 'розмах крил',
  num_of_engines TINYINT UNSIGNED not null comment = 'кількість двигунів',
  fuel_tank MEDIUMINT UNSIGNED not null comment = 'об`єм паливного бака',
  lifetime TINYINT UNSIGNED not null comment = 'Календарний строк служби (років)',
  flights SMALLINT UNSIGNED not null comment = '#Кількість польотів',
  flying_hours MEDIUMINT UNSIGNED not null comment = 'Кількість льотних годин',
  pilots TINYINT UNSIGNED not null comment = 'кількість пілотів',
  runway_length SMALLINT UNSIGNED not null comment = 'довжина розбігу на зліт',
  flight_range SMALLINT UNSIGNED not null comment = 'дальність польоту',
  fuel_consumption SMALLINT UNSIGNED not null comment = 'витрата палива',
  speed_cruising SMALLINT UNSIGNED not null comment = 'крейсерська швидкість',
  speed_max SMALLINT UNSIGNED not null comment = 'максимальна швидкість',
  altitude_max SMALLINT UNSIGNED not null comment = 'максимальна висота польоту',
  seats SMALLINT UNSIGNED not null comment = 'Макс кількість місць',
  seat_configuration set('2-2','3-3','2-3-2','2-4-2','3-3-3','3-4-3')  
) comment = 'моделі літаків';
# зроби у вигляді таблиці: бренд, модель, рік створення, кількість місць, дальність польоту, витрата палива, крейсерська швидкість, максимальна швидкість, максимальна висота польоту, розмах крил, кількість пілотів, варіант компонування крісел, довжина розбігу на зліт
insert into airplane_models
	(brend, model, creation, weight, wing_span, num_of_engines, fuel_tank, lifetime, flights, flying_hours, pilots, runway_length, flight_range, fuel_consumption,
   speed_cruising, speed_max, altitude_max, seats, seat_configuration)
values
  ('Boeing', '737-800', 1997, 41400, 35.8, 2, 26000, 30, 28000, 50000, 2, 2800, 5000, 2400, 840, 1015, 41000, 189, '3-3'),
  ('Airbus', 'A320', 1988, 41500, 34.1, 2, 23800, 30, 35000, 55000, 2, 2300, 6000, 2500, 830, 900, 39000, 180, '3-3'),
  ('Boeing', '747-400', 1989, 87500, 64.4, 4, 23800, 40, 55000, 90000, 3, 3200, 13900, 5000, 920, 1050, 45000, 524, '3-4-3'),
  ('Airbus', 'A380', 2005, 56000, 79.8, 4, 32000, 40, 60000, 100000, 2, 4000, 15000, 5600, 1020, 1100, 43000, 555, '3-4-3'),
  ('Boeing', '777-200', 1995, 76600, 60.9, 2, 17400, 40, 30000, 50000, 2, 3700, 10200, 3500, 900, 950, 42000, 314, '3-3-3'),
  ('Boeing', '787-9', 2014, 25400, 60.1, 2, 13000, 40, 12000, 22000, 2, 2900, 14500, 4500, 900, 940, 43000, 296, '3-3-3'),
  ('Airbus', 'A330-300', 1992, 24200, 64.0, 2, 13900, 40, 40000, 70000, 2, 3100, 12500, 4800, 890, 930, 42000, 277, '2-4-2'),
  ('Boeing', '767-300', 1982, 24200, 47.6, 2, 13100, 30, 35000, 55000, 2, 2600, 11000, 4200, 870, 910, 42000, 269, '2-3-2'),
  ('Bombardier', 'CRJ-900', 2001, 19500, 23.5, 2, 5000, 30, 12000, 20000, 2, 1700, 2600, 1600, 870, 890, 41000, 90, '2-2'),
  ('Embraer', 'E190', 2005, 23100, 28.7, 2, 5700, 30, 25000, 35000, 2, 1700, 4500, 2100, 850, 890, 41000, 114, '2-2');
select * from airplane_models;
# ---------------------------------------------------------------------------------------------------------------------------------------------------------


#drop table if exists airplanes_seats;
create table if not exists airplanes_seats (
	id SMALLINT primary key AUTO_INCREMENT,
  airplane SMALLINT not null,
  seat SMALLINT UNSIGNED not null,
  class tinyint unsigned,
  glass boolean,
  media boolean,
  FOREIGN KEY (airplane) REFERENCES airplane_models(airplane)
) comment = 'місця в літаках';

select sum(seats) from airplane_models;

/*
WITH RECURSIVE airplanes_seats_gen AS (
    SELECT 1 AS a, 1 AS s
    UNION ALL
    SELECT a + 1, s + 1 FROM airplanes_seats_gen WHERE a < (select count(*) from airplane_models) and s < (select seats from airplane_models where airplane = a)
)
SELECT a, s FROM airplanes_seats_gen;
*/

#SHOW VARIABLES LIKE '%recursion%';
#SET SESSION cte_max_recursion_depth=5000;
#SET SESSION max_execution_time = 60000;

insert into airplanes_seats (airplane, seat)
WITH RECURSIVE airplanes_seats_gen AS (
    # Ініціалізація: перший літак (a = 1), перше сидіння (s = 1)
    SELECT 1 AS a, 1 AS s
    UNION ALL
    # Рекурсивна частина: збільшуємо номер літака (a) і сидіння (s) у міру просування
    SELECT
        CASE WHEN s + 1 > am.seats THEN a + 1 ELSE a END AS a, # Якщо сидіння завершені для поточного літака, переходимо до наступного
        CASE WHEN s + 1 > am.seats THEN 1 ELSE s + 1 END AS s # Якщо сидіння завершені, починаємо з першого сидіння наступного літака
    FROM airplanes_seats_gen
    JOIN airplane_models am ON am.airplane = a
    WHERE a <= (SELECT count(*) FROM airplane_models)
)
#SELECT a as airplane, s as seat FROM airplanes_seats_gen
SELECT a, s FROM airplanes_seats_gen where a <= 10;
#----
select * from airplanes_seats;

# ------------------------------------------------------------------------------------------------------------------------------------------------------------


#drop table if exists airlines;
create table if not exists airlines(
	airline smallint primary key AUTO_INCREMENT,
  create_at datetime not null default now(),
  name varchar(100) not null,
  foundations year comment = 'рік заснування',
  country int not null comment = 'країна реєстрації',
  city int not null comment = 'місто, в якому розташований головний офіс',
  Contact varchar(255),
  FOREIGN KEY (country) REFERENCES countries(country),
  FOREIGN KEY (city) REFERENCES cities(city)
); comment = 'авіокомпанії';
# --------
select 'назва авіокомпанії?', 'рік заснування?', cn.country, cn.name, ct.city, ct.name, 'контакти?'
from countries cn
inner join cities ct on ct.country = cn.country;
# --------
insert into airlines (name, foundations, country, city, Contact) values
  ('Austrian Airlines', 1957, 1, 1, 'Office Park 2, 1300 Vienna Airport, Austria'),
  ('Styrian Airways', 2000, 1, 2, 'Graz Airport, 8073 Graz, Austria'),
  ('Linz Airlines', 2005, 1, 3, 'Linz Airport, 4063 Linz, Austria'),
  ('Brussels Airlines', 2006, 2, 4, 'Brussels Airport, 1930 Zaventem, Belgium'),
  ('Antwerp Airlines', 2008, 2, 5, 'Antwerp International Airport, 2100 Antwerp, Belgium'),
  ('Ghent Air', 2010, 2, 6, 'Ghent Airport, 9000 Ghent, Belgium'),
  ('Bulgaria Air', 2002, 3, 7, 'Sofia Airport, 1540 Sofia, Bulgaria'),
  ('Plovdiv Airlines', 2004, 3, 8, 'Plovdiv Airport, 4000 Plovdiv, Bulgaria'),
  ('Varna Airways', 2006, 3, 9, 'Varna Airport, 9000 Varna, Bulgaria'),
  ('Croatia Airlines', 1991, 4, 10, 'Zagreb Airport, 10150 Zagreb, Croatia'),
  ('Split Airlines', 1995, 4, 11, 'Split Airport, 21000 Split, Croatia'),
  ('Rijeka Airlines', 1998, 4, 12, 'Rijeka Airport, 51000 Rijeka, Croatia'),
  ('Cyprus Airways', 1947, 5, 13, 'Larnaca Airport, 6028 Larnaca, Cyprus'),
  ('Limassol Airlines', 2000, 5, 14, 'Limassol International Airport, 4532 Limassol, Cyprus'),
  ('Larnaca Airways', 1990, 5, 15, 'Larnaca Airport, 6028 Larnaca, Cyprus'),
  ('Czech Airlines', 1923, 6, 16, 'Prague Airport, 16008 Prague, Czech Republic'),
  ('Brno Airlines', 2005, 6, 17, 'Brno Airport, 62700 Brno, Czech Republic'),
  ('Ostrava Airlines', 2008, 6, 18, 'Ostrava Airport, 72300 Ostrava, Czech Republic'),
  ('SAS', 1946, 7, 19, 'Copenhagen Airport, 2770 Kastrup, Denmark'),
  ('Aarhus Airlines', 2000, 7, 20, 'Aarhus Airport, 8230 Aarhus, Denmark'),
  ('Odense Airlines', 1990, 7, 21, 'Odense Airport, 5220 Odense, Denmark'),
  ('Estonian Air', 1991, 8, 22, 'Tallinn Airport, 11101 Tallinn, Estonia'),
  ('Tartu Airlines', 1998, 8, 23, 'Tartu Airport, 50411 Tartu, Estonia'),
  ('Narva Airlines', 2005, 8, 24, 'Narva Airport, 20308 Narva, Estonia'),
  ('Finnair', 1923, 9, 25, 'Helsinki Airport, 01530 Vantaa, Finland'),
  ('Espoo Airlines', 2005, 9, 26, 'Espoo Airport, 02100 Espoo, Finland'),
  ('Tampere Airlines', 1998, 9, 27, 'Tampere Airport, 33960 Tampere, Finland'),
  ('Air France', 1933, 10, 28, 'Charles de Gaulle Airport, 95711 Roissy-en-France, France'),
  ('Marseille Airlines', 1991, 10, 29, 'Marseille Airport, 13727 Marignane, France'),
  ('Lyon Airlines', 1987, 10, 30, 'Lyon-Saint-Exupéry Airport, 69125 Lyon, France'),
  ('Lufthansa', 1953, 11, 31, 'Berlin Tegel Airport, 13405 Berlin, Germany'),
  ('Munich Airlines', 1962, 11, 32, 'Munich Airport, 85356 Munich, Germany'),
  ('Hamburg Airlines', 1970, 11, 33, 'Hamburg Airport, 22335 Hamburg, Germany'),
  ('Aegean Airlines', 1987, 12, 34, 'Eleftherios Venizelos Airport, 19019 Markopoulo, Greece'),
  ('Thessaloniki Airlines', 1990, 12, 35, 'Thessaloniki Airport, 55103 Thessaloniki, Greece'),
  ('Patras Airlines', 2000, 12, 36, 'Patras Airport, 26335 Patras, Greece'),
  ('Hungarian Airlines', 1946, 13, 37, 'Budapest Airport, 1185 Budapest, Hungary'),
  ('Hungarian Airlines', 1946, 13, 38, 'Debrecen Airport, 4026 Debrecen, Hungary'),
  ('Hungarian Airlines', 1946, 13, 39, 'Szeged Airport, 6728 Szeged, Hungary'),
  ('Aer Lingus', 1936, 14, 40, 'Dublin Airport, 10001 Dublin, Ireland'),
  ('Aer Lingus', 1936, 14, 41, 'Cork Airport, 18001 Cork, Ireland'),
  ('Aer Lingus', 1936, 14, 42, 'Shannon Airport, 64002 Limerick, Ireland'),
  ('Alitalia', 1947, 15, 43, 'Fiumicino Airport, 00054 Rome, Italy'),
  ('Alitalia', 1947, 15, 44, 'Malpensa Airport, 21010 Milan, Italy'),
  ('Alitalia', 1947, 15, 45, 'Capodichino Airport, 80144 Naples, Italy'),
  ('Air Baltic', 2004, 16, 46, 'Riga Airport, 1053 Riga, Latvia'),
  ('Air Baltic', 2004, 16, 47, 'Daugavpils Airport, 5401 Daugavpils, Latvia'),
  ('Air Baltic', 2004, 16, 48, 'Liepaja Airport, 3401 Liepaja, Latvia'),
  ('Air Lithuania', 1991, 17, 49, 'Vilnius Airport, 02121 Vilnius, Lithuania'),
  ('Air Lithuania', 1991, 17, 50, 'Kaunas Airport, 50196 Kaunas, Lithuania'),
  ('Air Lithuania', 1991, 17, 51, 'Klaipeda Airport, 93221 Klaipeda, Lithuania'),
  ('Luxair', 1961, 18, 52, 'Luxembourg Airport, 2987 Luxembourg City, Luxembourg'),
  ('Luxair', 1961, 18, 53, 'Ettelbruck Airport, 9068 Ettelbruck, Luxembourg'),
  ('Luxair', 1961, 18, 54, 'Differdange Airport, 4550 Differdange, Luxembourg'),
  ('Air Malta', 1973, 19, 55, 'Luqa Airport, LQA 4000 Valletta, Malta'),
  ('Air Malta', 1973, 19, 56, 'Mosta Airport, 1033 Mosta, Malta'),
  ('Air Malta', 1973, 19, 57, 'Sliema Airport, 1001 Sliema, Malta'),
  ('KLM', 1919, 20, 58, 'Schiphol Airport, 1118 Amsterdam, Netherlands'),
  ('KLM', 1919, 20, 59, 'Rotterdam Airport, 3041 Rotterdam, Netherlands'),
  ('KLM', 1919, 20, 60, 'Utrecht Airport, 3584 Utrecht, Netherlands'),
  ('LOT Polish Airlines', 1929, 21, 61, 'Chopin Airport, 00-175 Warsaw, Poland'),
  ('LOT Polish Airlines', 1929, 21, 62, 'John Paul II International Airport, 31-586 Krakow, Poland'),
  ('Wizz Air', 2003, 21, 63, 'Wroclaw Copernicus Airport, 54-530 Wroclaw, Poland'),
  ('TAP Air Portugal', 1945, 22, 64, 'Lisbon Humberto Delgado Airport, 1700-008 Lisbon, Portugal'),
  ('SATA Air Açores', 1941, 22, 65, 'Francisco Sá Carneiro Airport, 4470-558 Porto, Portugal'),
  ('Azores Airlines', 1990, 22, 66, 'Beja Airport, 7800-505 Beja, Portugal'),
  ('TAROM', 1954, 23, 67, 'Henri Coandă International Airport, 075100 Bucharest, Romania'),
  ('Blue Air', 2004, 23, 68, 'Cluj-Napoca International Airport, 400619 Cluj-Napoca, Romania'),
  ('Wizz Air', 2003, 23, 69, 'Traian Vuia International Airport, 300630 Timisoara, Romania'),
  ('Air Slovakia', 1993, 24, 70, 'M. R. Štefánik Airport, 82104 Bratislava, Slovakia'),
  ('Go2Sky', 2011, 24, 71, 'Košice International Airport, 04001 Košice, Slovakia'),
  ('Air Explore', 2011, 24, 72, 'Nitra Airport, 94901 Nitra, Slovakia'),
  ('Adria Airways', 1961, 25, 73, 'Ljubljana Jože Pučnik Airport, 1000 Ljubljana, Slovenia'),
  ('Amadeus Air', 1999, 25, 74, 'Maribor Edvard Rusjan Airport, 2000 Maribor, Slovenia'),
  ('Air Slovenia', 1992, 25, 75, 'Celje Airport, 3000 Celje, Slovenia'),
  ('Iberia', 1927, 26, 76, 'Adolfo Suárez Madrid–Barajas Airport, 28042 Madrid, Spain'),
  ('Vueling', 2004, 26, 77, 'Barcelona-El Prat Airport, 08820 Barcelona, Spain'),
  ('Air Europa', 1986, 26, 78, 'Valencia Airport, 46940 Valencia, Spain'),
  ('SAS', 1946, 27, 79, 'Stockholm Arlanda Airport, 190 45 Stockholm, Sweden'),
  ('Norwegian Air Shuttle', 1993, 27, 80, 'Göteborg Landvetter Airport, 404 80 Gothenburg, Sweden'),
  ('Braathens', 1946, 27, 81, 'Malmö Airport, 232 37 Malmö, Sweden');
 select * from airlines;
#-----------------------------------------------------------------------------------------------------


# drop table if exists airline_planes;
create table if not exists airline_planes(
	airplane_id smallint primary key auto_increment,
  airline smallint not null,
  airplane smallint not null,
  issue_date year not null comment = 'рік створення',
  flight_hours MEDIUMINT UNSIGNED not null comment = 'загальний наліт годин',
  flight_distance MEDIUMINT UNSIGNED not null comment = 'загальний наліт відстані',
  status varchar(255),
  FOREIGN KEY (airline) REFERENCES airlines(airline),
  FOREIGN KEY (airplane) REFERENCES airplane_models(airplane)  
) comment = 'літаки авіокомпаній';
# --
#truncate airline_planes;
insert into airline_planes (airline, airplane, issue_date, flight_hours, flight_distance)
# іноді запит може видавати помилку!
WITH RECURSIVE airline_planes_gen AS (
    SELECT 1 AS i, 1 as airline, 1 as airplane2, 1 as issue_date, 1 as flight_hours, 1 as flight_distance
    UNION ALL    
    SELECT i + 1,
  			cast(1 + ((select count(*) from airlines) - 1 + 1) * RAND() as signed) as airline,
  			cast(1 + ((select count(*) from airplane_models) - 2 + 1) * RAND() as signed) as airplane2,
  			cast(am.creation + (YEAR(CURDATE()) - am.creation + 1) * RAND() as signed) as issue_date,
  			cast(100 + (am.flying_hours - 100 + 1) * RAND() as signed) as flight_hours,
  			cast(100 + (am.flight_range - 100 + 1) * RAND() as signed) as flight_distance        
    FROM airline_planes_gen
    JOIN airplane_models am ON am.airplane = airplane2
    WHERE i < 100 #(SELECT @@cte_max_recursion_depth)
)
select airline, airplane2, issue_date, flight_hours, flight_distance from airline_planes_gen where airline != 1;
# ---
select * from airline_planes;
# --------------------------------------------------------------------------------------------------------------------------------------------------------


#drop table if exists flight_list;
create table if not exists flight_list (
	flight SMALLINT primary key auto_increment,
  airport_departure int not null comment = 'аеропорт вильоту',
  airport_arrival int not null comment = 'аеропорт прильоту',
  FOREIGN KEY (airport_departure) REFERENCES airports(airport),
  FOREIGN KEY (airport_arrival) REFERENCES airports(airport)
) comment = 'список рейсів';
#---
insert into flight_list (airport_departure, airport_arrival) select a1.airport, a2.airport from airports a1, airports a2 where a1.airport != a2.airport;
select * from flight_list;

