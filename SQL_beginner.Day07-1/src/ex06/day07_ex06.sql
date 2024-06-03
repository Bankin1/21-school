SELECT p.name,
       count(p.id)                                 AS count_of_orders,
       round(SUM(m.price) / count(p.id),2) AS average_price,
       MAX(m.price)                                AS max_price,
       MIN(m.price)                                AS min_price
FROM person_order
         JOIN public.menu m on m.id = person_order.menu_id
         JOIN public.pizzeria p on p.id = m.pizzeria_id
GROUP BY p.name
ORDER BY 1;