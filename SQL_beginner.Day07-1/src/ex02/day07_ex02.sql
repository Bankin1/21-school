WITH orders(name, count, action_type) AS
         (SELECT p.name AS name, count(po.id) AS count, 'order'
          FROM pizzeria AS p
                   JOIN public.menu m on p.id = m.pizzeria_id
                   JOIN public.person_order po on m.id = po.menu_id
          GROUP BY p.name
          ORDER BY count DESC
          LIMIT 3),
     visits(name, count, action_type) AS
         (SELECT p.name AS name, count(po.id) AS count, 'visit'
          FROM pizzeria AS p
                   JOIN public.person_visits po on po.pizzeria_id = p.id
          GROUP BY p.name
          ORDER BY count DESC
          LIMIT 3)
SELECT *
FROM orders
UNION
SELECT *
FROM visits
ORDER BY 3, 2 DESC;
