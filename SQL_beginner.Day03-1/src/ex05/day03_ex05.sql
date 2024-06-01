WITH visited(name) AS (SELECT DISTINCT name
                       FROM pizzeria
                                JOIN public.person_visits pv on pizzeria.id = pv.pizzeria_id AND pv.person_id =
                                                                                                 (SELECT id FROM person WHERE name = 'Andrey')),
     ordered(name) AS (SELECT DISTINCT name
                       FROM pizzeria
                                JOIN menu AS m ON pizzeria.id = m.pizzeria_id
                                JOIN person_order po ON m.id = po.menu_id AND
                                                        po.person_id = (SELECT id FROM person WHERE name = 'Andrey'))
SELECT p.name AS pizzeria_name
FROM (SELECT *
      FROM visited
      EXCEPT
      SELECT *
      FROM ordered) AS p
ORDER BY pizzeria_name;