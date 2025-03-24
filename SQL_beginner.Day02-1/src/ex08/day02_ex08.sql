SELECT p.name AS name
FROM (SELECT * FROM person WHERE gender = 'male' AND address IN ('Moscow', 'Samara')) AS p
         JOIN person_order AS po ON po.person_id = p.id
         JOIN menu AS m ON po.menu_id = m.id
WHERE m.pizza_name IN ('mushroom pizza', 'pepperoni pizza')
ORDER BY name DESC;
