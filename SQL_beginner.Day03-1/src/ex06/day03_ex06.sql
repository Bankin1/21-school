SELECT m.pizza_name AS pizza_name, p.name AS pizzeria_name_1, p2.name AS pizzeria_name_2, m.price
FROM menu AS m
         JOIN pizzeria as p ON m.pizzeria_id = p.id
         JOIN menu m2 on m.id <> m2.id AND m2.pizza_name = m.pizza_name AND
                         m2.price = m.price
         JOIN pizzeria p2 on p2.id = m2.pizzeria_id
WHERE m.id > m2.id
ORDER BY pizza_name;
