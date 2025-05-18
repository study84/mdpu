-- 513-і, Золотухін Андрій
-- Лабораторна робота № 7, Варіант № 8
-- Завдання: https://dfn.mdpu.org.ua/pluginfile.php/15934/mod_resource/content/4/5.SQL%20join.pdf

SHOW TABLES;
SELECT * FROM Jobs LIMIT 10; -- проекти
SELECT * FROM Parts LIMIT 10; -- деталі
SELECT * FROM SPJ LIMIT 10;
SELECT * from Suppliers LIMIT 10; -- постачальники
------------------------------------------------------

-- 6. Вибрати загальну суму статусів усіх постачальників
SELECT SUM(STATUS) from Suppliers;

-- 21. Вибрати найбільшу масу серед деталей по містах, де вони виробляються
SELECT CITY, MAX(WEIGHT) FROM Parts GROUP BY 1 ORDER BY 2 DESC, 1;

-- 26. Порахувати суму мас всіх деталей у поставках (з урахуванням кількості та ваги кожної деталі) рахувати загальну вагу за містами проектів, до котрих вони поставляються. Але відобразити лише міста, де проектів більше 1.
-- порахувати сумму масс всех деталей по поставкам, по городам куда поставки(город проекта)
WITH tab1 AS (SELECT JNUM, COUNT(*) FROM SPJ GROUP BY 1 HAVING COUNT(*) > 1)
SELECT j.CITY, SUM(s.QTY * p.WEIGHT) sum_weight
FROM SPJ s
INNER JOIN Parts p USING(PNUM)
INNER JOIN Jobs j USING(JNUM)
WHERE s.JNUM IN(SELECT JNUM FROM tab1)
GROUP BY 1


-- 48. Вибрати назви деталей, що постачаються в середній кількості > =250 (на постачання)
SELECT PNAME, COLOR, AVG_QTY FROM (SELECT PNUM, ROUND(AVG(QTY)) FROM SPJ GROUP BY 1 HAVING ROUND(AVG(QTY)) >= 250) tab (PNUM, AVG_QTY)
INNER JOIN Parts USING(PNUM);


-- 54. Отримати номери постачальників, що поставляють деталь Р1 для деякого проекту у кількості, більшій за середню кількість деталей Р1 у поставках для цього проекту.


-- 50. Отримати всі міста, в яких розташований принаймні один постачальник, одна деталь або проект
SELECT DISTINCT j.CITY FROM Jobs j
WHERE j.CITY IN (SELECT p.CITY FROM Parts p) AND j.CITY IN (SELECT s.CITY FROM Suppliers s)
---
SELECT DISTINCT j.CITY
FROM Jobs j
INNER JOIN Parts p USING(CITY)
INNER JOIN Suppliers s USING(CITY)



