-- https://dfn.mdpu.org.ua/pluginfile.php/94468/mod_resource/content/3/SPJ2.sql



SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";




--

-- --------------------------------------------------------

--
-- Структура таблицы Parts
--

CREATE TABLE Parts (
  PNUM int(11) NOT NULL,
  PNAME char(20) DEFAULT NULL,
  COLOR char(10) DEFAULT NULL,
  WEIGHT int(11) DEFAULT NULL,
  CITY char(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы Parts
--

INSERT INTO Parts (PNUM, PNAME, COLOR, WEIGHT, CITY) VALUES
(1, 'Nut', 'Red', 12, 'London'),
(2, 'Bolt', 'Green', 17, 'Paris'),
(3, 'Screw', 'Blue', 17, 'Rome'),
(4, 'Screw', 'Red', 14, 'London'),
(5, 'Cam', 'Blue', 12, 'Paris'),
(6, 'Cog', 'Red', 19, 'London');

-- --------------------------------------------------------

--
-- Структура таблицы Jobs
--

CREATE TABLE Jobs (
  JNUM int(11) NOT NULL,
  JNAME char(20) DEFAULT NULL,
  CITY char(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы Jobs
--

INSERT INTO Jobs (JNUM, JNAME, CITY) VALUES
(1, 'Sorter', 'Paris'),
(2, 'Display', 'Rome'),
(3, 'OCR', 'Athens'),
(4, 'Console', 'Athens'),
(5, 'RAID', 'London'),
(6, 'EDS', 'Oslo'),
(7, 'Tape', 'London');

-- --------------------------------------------------------

--
-- Структура таблицы spj
--
-- Структура чтения ошибок для таблицы study_delivery.spj: #1812 - Tablespace is missing for table study_delivery.spj.
-- Ошибка считывания данных таблицы study_delivery.spj: #1064 - У вас ошибка в запросе. Изучите документацию по используемой версии MySQL на предмет корректного синтаксиса около 'FROM study_delivery.spj' на строке 1

-- --------------------------------------------------------

--
-- Структура таблицы Suppliers
--

CREATE TABLE Suppliers (
  SNUM int(11) NOT NULL,
  SNAME char(20) DEFAULT NULL,
  STATUS int(11) DEFAULT NULL,
  CITY char(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы Suppliers
--

INSERT INTO Suppliers (SNUM, SNAME, STATUS, CITY) VALUES
(1, 'Smith', 20, 'London'),
(2, 'Jones', 10, 'Paris'),
(3, 'Black', 30, 'Paris'),
(4, 'Clark', 20, 'London'),
(5, 'Adams', 30, 'Athens');

--
-- Индексы сохранённых таблиц
--


CREATE TABLE `spj` (
  `SNUM` int(11) NOT NULL,
  `PNUM` int(11) NOT NULL,
  `JNUM` int(11) NOT NULL,
  `QTY` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `spj`
--

INSERT INTO SPJ (SNUM, PNUM, JNUM, QTY) VALUES
(1, 1, 1, 200),
(1, 1, 4, 700),
(2, 3, 1, 400),
(2, 3, 2, 200),
(2, 3, 3, 200),
(2, 3, 4, 500),
(2, 3, 5, 600),
(2, 3, 6, 400),
(2, 3, 7, 800),
(2, 5, 2, 100),
(3, 3, 1, 200),
(3, 4, 2, 500),
(4, 6, 3, 300),
(4, 6, 7, 300),
(5, 2, 2, 200),
(5, 2, 4, 100),
(5, 5, 5, 500),
(5, 5, 7, 100),
(5, 6, 2, 200),
(5, 1, 4, 100),
(5, 3, 4, 200),
(5, 4, 4, 800),
(5, 5, 4, 400),
(5, 6, 4, 500);


--
-- Индексы таблицы Parts
--
ALTER TABLE Parts
  ADD PRIMARY KEY (PNUM),
  ADD KEY PNAME (PNAME);

--
-- Индексы таблицы Jobs
--
ALTER TABLE Jobs
  ADD PRIMARY KEY (JNUM),
  ADD KEY JNAME (JNAME);

--
-- Индексы таблицы Suppliers
--
ALTER TABLE Suppliers
  ADD PRIMARY KEY (SNUM),
  ADD KEY SNAME (SNAME);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;