SELECT p.name,
       m.pizza_name                        AS pizza_name,
       m.price                             AS price,
       m.price * (100 - pd.discount) / 100 AS discount_price,
       p2.name                             AS pizzeria_name
FROM person_order
         JOIN public.menu m on m.id = person_order.menu_id
         JOIN public.person p on p.id = person_order.person_id
         JOIN public.person_discounts pd on p.id = pd.person_id
         JOIN public.pizzeria p2 on p2.id = m.pizzeria_id
ORDER BY 1, 2;
