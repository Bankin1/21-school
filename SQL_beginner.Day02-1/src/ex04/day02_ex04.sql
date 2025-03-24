SELECT ma.pizza_name, pizzeria.name AS pizzeria_name, ma.price
FROM (SELECT * FROM menu WHERE pizza_name IN ('mushroom pizza', 'pepperoni pizza')) AS ma
         FULL JOIN pizzeria ON pizzeria.id = ma.pizzeria_id WHERE ma.pizza_name IS NOT NULL
ORDER BY pizza_name, pizzeria_name;
