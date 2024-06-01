WITH orders(name, count, action_type) AS
         (SELECT p.name AS name, count(po.id) AS count, 'order'
          FROM pizzeria AS p
                   JOIN public.menu m on p.id = m.pizzeria_id
                   JOIN public.person_order po on m.id = po.menu_id
          GROUP BY p.name),
     visits(name, count, action_type) AS
         (SELECT p.name AS name, count(po.id) AS count, 'visit'
          FROM pizzeria AS p
                   JOIN public.person_visits po on po.pizzeria_id = p.id
          GROUP BY p.name)
SELECT p.name, COALESCE(o.count, 0) + COALESCE(v.count, 0) AS total_count
FROM pizzeria AS p
         FULL JOIN orders AS o ON o.name = p.name
         FULL JOIN visits AS v ON v.name = p.name
ORDER BY 2 DESC, 1;

