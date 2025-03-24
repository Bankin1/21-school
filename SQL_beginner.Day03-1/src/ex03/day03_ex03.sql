WITH femail(name, counter) AS
         (SELECT name, count(name) AS count_femail
          FROM pizzeria
                   JOIN person_visits AS pv ON pizzeria.id = pv.pizzeria_id AND
                                               pv.person_id IN (SELECT id FROM person WHERE gender = 'female')
          GROUP BY name),
     male(name, counter) AS
         (SELECT name, count(name) AS count_femail
          FROM pizzeria
                   JOIN person_visits AS pv ON pizzeria.id = pv.pizzeria_id AND
                                               pv.person_id IN (SELECT id FROM person WHERE gender = 'male')
          GROUP BY name)
SELECT mm.name AS pizzeria_name
FROM male AS mm
         JOIN femail AS ff ON mm.name = ff.name AND ff.counter <> mm.counter
ORDER BY pizzeria_name;

WITH femail(name, counter) AS
         (SELECT name, count(name) AS count_femail
          FROM pizzeria
                   JOIN person_visits AS pv ON pizzeria.id = pv.pizzeria_id AND
                                               pv.person_id IN (SELECT id FROM person WHERE gender = 'female')
          GROUP BY name),
     male(name, counter) AS
         (SELECT name, count(name) AS count_femail
          FROM pizzeria
                   JOIN person_visits AS pv ON pizzeria.id = pv.pizzeria_id AND
                                               pv.person_id IN (SELECT id FROM person WHERE gender = 'male')
          GROUP BY name)
SELECT mm.name AS pizzeria_name
FROM (SELECT *
      FROM male
      EXCEPT ALL
      SELECT *
      FROM femail) AS mm
ORDER BY pizzeria_name;



