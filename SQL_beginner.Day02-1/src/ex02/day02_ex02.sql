SELECT COALESCE(p.name, '-') AS person_name, visit_date, COALESCE(p2.name, '-') AS pizzeria_name
FROM (SELECT *
      FROM person_visits
      WHERE visit_date BETWEEN '2022-01-01' AND '2022-01-03') AS date
         FULL JOIN person p on p.id = date.person_id
         FULL JOIN pizzeria p2 on p2.id = date.pizzeria_id
ORDER BY person_name, visit_date, pizzeria_name;
