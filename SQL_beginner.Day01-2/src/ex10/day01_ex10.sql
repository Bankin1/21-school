SELECT person_name, pizza_name, pizzeria_name FROM person_order
JOIN (SELECT name AS person_name, id FROM person) AS ppn ON ppn.id = person_order.person_id
JOIN (SELECT pizza_name AS pizza_name, pizzeria_id, id FROM menu) AS mpn ON mpn.id = person_order.menu_id
JOIN (SELECT name AS pizzeria_name, id FROM pizzeria) AS pn ON pn.id = mpn.pizzeria_id
ORDER BY person_name, pizza_name, pizzeria_name;