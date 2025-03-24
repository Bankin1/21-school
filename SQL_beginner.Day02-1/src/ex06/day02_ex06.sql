SELECT m.pizza_name AS pizza_name, pp.name AS pizzeria_name
FROM person_order AS po
         FULL JOIN menu m ON m.id = po.menu_id
         FULL JOIN pizzeria AS pp ON pp.id = m.pizzeria_id
         FULL JOIN person AS per ON po.person_id = per.id
WHERE per.name IN ('Denis', 'Anna')
ORDER BY pizza_name, pizzeria_name;