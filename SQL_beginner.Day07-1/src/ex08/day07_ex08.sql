SELECT p2.address, p.name, count(p.id) AS count_of_orders
FROM person_order AS po
         JOIN public.menu m on m.id = po.menu_id
         JOIN public.pizzeria p on p.id = m.pizzeria_id
         JOIN public.person p2 on p2.id = po.person_id
GROUP BY p2.address, p.name
ORDER BY 1, 2;