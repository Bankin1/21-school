INSERT INTO person_visits (id, person_id, pizzeria_id, visit_date)
VALUES ((SELECT MAX(id) + 1 FROM person_order),
        (SELECT id FROM person WHERE name = 'Dmitriy'),
        (SELECT pi.id
         FROM pizzeria AS pi
                  JOIN menu AS m ON pi.id = m.pizzeria_id
                  JOIN mv_dmitriy_visits_and_eats AS mv ON pi.name <> mv.visited_pizzeria
         WHERE m.price < 800
         LIMIT 1),
        '2022-01-08');
REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;