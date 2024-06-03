SELECT DISTINCT name
FROM person AS p
         JOIN public.person_order po on p.id = po.person_id
         JOIN public.person_visits pv on p.id = pv.person_id
ORDER BY 1;