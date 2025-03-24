WITH peperoni AS (SELECT p.name AS name
                  FROM (SELECT * FROM person WHERE gender = 'female') AS p
                           JOIN person_order AS po ON po.person_id = p.id
                           JOIN (SELECT * FROM menu WHERE pizza_name = 'pepperoni pizza') AS m2 ON po.menu_id = m2.id),
     cheese AS (SELECT p.name AS name
                FROM (SELECT * FROM person WHERE gender = 'female') AS p
                         JOIN person_order AS po ON po.person_id = p.id
                         JOIN (SELECT * FROM menu WHERE pizza_name = 'cheese pizza') AS m2 ON po.menu_id = m2.id)
SELECT pep.name AS name FROM peperoni AS pep
JOIN cheese AS ch ON ch.name = pep.name
ORDER BY name;