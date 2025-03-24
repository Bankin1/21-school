WITH person_count(name, count_of_visits) AS
         (SELECT p.name AS name, count(pv.id) AS count_of_visits
          FROM person AS p
                   join public.person_visits pv on p.id = pv.person_id
          GROUP BY 1
          ORDER BY count_of_visits DESC
          LIMIT(4))
SELECT *
FROM person_count
ORDER BY count_of_visits DESC, name;