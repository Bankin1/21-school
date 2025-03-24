SELECT p.id AS person_id, count(pv.id) AS count_of_visits
FROM person AS p
         join public.person_visits pv on p.id = pv.person_id
GROUP BY 1
ORDER BY 2 DESC, 1;
