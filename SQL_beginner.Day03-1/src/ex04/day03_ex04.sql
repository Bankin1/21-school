WITH female(name) AS
         (SELECT DISTINCT p.name
          FROM pizzeria AS p
                   JOIN menu AS m ON m.pizzeria_id = p.id
                   JOIN (SELECT *
                         FROM person_order
                         WHERE person_id IN (SELECT id FROM person WHERE gender = 'female')) AS po
                        ON po.menu_id = m.id),
     male(name) AS
         (SELECT DISTINCT p.name
          FROM pizzeria AS p
                   JOIN menu AS m ON m.pizzeria_id = p.id
                   JOIN (SELECT *
                         FROM person_order
                         WHERE person_id IN (SELECT id FROM person WHERE gender = 'male')) AS po ON po.menu_id = m.id)
SELECT mm.name AS pizzeria_name
FROM (SELECT *
      FROM female
      EXCEPT
      SELECT *
      FROM male) AS mm
UNION
(SELECT *
 FROM male
 EXCEPT
 SELECT *
 FROM female)
ORDER BY pizzeria_name;