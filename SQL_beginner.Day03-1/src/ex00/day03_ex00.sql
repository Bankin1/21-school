SELECT m.pizza_name, m.price, pi.name AS pizzeria_name, pv.visit_date
FROM (SELECT * FROM person WHERE name = 'Kate') AS per
         JOIN person_visits as pv ON pv.person_id = per.id
         JOIN (SELECT * FROM menu WHERE price BETWEEN 800 AND 1000) AS m ON m.pizzeria_id = pv.pizzeria_id
         JOIN pizzeria AS pi ON pi.id = pv.pizzeria_id
ORDER BY 1, 2, 3;


