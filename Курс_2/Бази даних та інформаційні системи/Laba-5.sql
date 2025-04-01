-- 513-і, Золотухін Андрій
-- Лабораторна робота № 5, Варіант № 8
-- Завдання: https://dfn.mdpu.org.ua/pluginfile.php/15934/mod_resource/content/4/5.SQL%20join.pdf

SHOW TABLES;
SELECT * FROM Jobs LIMIT 10;
SELECT * FROM Parts LIMIT 10;
SELECT * FROM SPJ LIMIT 10;
SELECT * from Suppliers LIMIT 10;
------------------------------------------------------

-- 8. Вибрати тільки назви та міста проектів та постачальників, такі що проект та постачальник знаходяться в одному місті.
SELECT * /*j.JNAME, j.CITY, supp.CITY*/
FROM SPJ s
INNER JOIN Suppliers supp USING(SNUM)
INNER JOIN Parts p USING(PNUM)
INNER JOIN Jobs j USING(JNUM)
WHERE p.CITY = supp.CITY


-- 11. Вибрати всі можливі комбінації міста постачальника та міста деталі без повторень (постачання не потрібно).
SELECT DISTINCT p.CITY AS "City Parts", supp.CITY AS "City Suppliers"
FROM Suppliers supp, Parts p
/*SPJ s
INNER JOIN Suppliers supp USING(SNUM)
INNER JOIN Parts p USING(PNUM)
*/


-- 23. Вибрати всю інформацію про всі поставки постачальника зі статусом >20.
SELECT * 
FROM SPJ s
INNER JOIN Suppliers supp USING(SNUM)
INNER JOIN Parts p USING(PNUM)
INNER JOIN Jobs j USING(JNUM)
WHERE supp.STATUS > 20

-- 33. Вибрати всіх постачальників разом із поставками, якщо такі є.
-- Вивести: Ім'я постачальника, Статус постачальника, Місто постачальника, Назва деталі, Місто деталі, Кількість.
-- Сортувати за Містом постачальника, Ім'я постачальника та Назвою деталі.
SELECT supp.SNAME, supp.STATUS, supp.CITY, p.PNAME, p.CITY, s.QTY
FROM Suppliers supp
LEFT JOIN SPJ s USING(SNUM)
INNER JOIN Parts p USING(PNUM)
ORDER BY supp.CITY, supp.SNAME, p.PNAME

-- 44. Вибрати всю інформацію про постачання постачальників із міста (постачальника) «Paris» або червоних деталей.
SELECT * 
FROM SPJ s
INNER JOIN Suppliers supp USING(SNUM)
INNER JOIN Parts p USING(PNUM)
INNER JOIN Jobs j USING(JNUM)
WHERE supp.CITY = 'Paris' OR p.COLOR = 'Red'

