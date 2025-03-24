SELECT pi.name AS visited_pizzeria
FROM (SELECT * FROM person_visits WHERE visit_date = '2022-01-08') AS pv
         JOIN (SELECT * FROM person WHERE name = 'Dmitriy') AS p ON p.id = pv.person_id
         JOIN pizzeria as pi ON pi.id = pv.pizzeria_id
         JOIN (SELECT * FROM menu WHERE price < 800) AS m ON m.pizzeria_id = pi.id;


