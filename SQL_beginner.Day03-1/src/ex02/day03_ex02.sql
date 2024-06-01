SELECT m.pizza_name, m.price, pi.name AS pizzeria_name
FROM menu AS m
         LEFT JOIN (SELECT * FROM person_order) AS po ON po.menu_id = m.id
         JOIN pizzeria AS pi ON m.pizzeria_id = pi.id
WHERE po.person_id IS NULL
ORDER BY 1, 2;
