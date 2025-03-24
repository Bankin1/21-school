WITH visits(name, count_of_visits) AS
         (SELECT p.name AS name, count(pi.id) AS count_of_visits
          FROM person AS p
                   JOIN person_visits pv on pv.person_id = p.id
                   JOIN pizzeria AS pi ON pv.pizzeria_id = pi.id
          GROUP BY p.name)
SELECT v1.name, v1.count_of_visits
FROM visits AS v1
         INNER JOIN visits as v2 ON v1.name = v2.name AND v1.count_of_visits > 3
