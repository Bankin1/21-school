SELECT p.address,
       round(MAX(p.age)::numeric(5, 2) - (MIN(p.age)::numeric(5, 2) / MAX(p.age)::numeric(5, 2)), 2) AS formula,
       round(AVG(p.age), 2)                                                                          AS average,
       (CASE
            WHEN round(MAX(p.age)::numeric(5, 2) - (MIN(p.age)::numeric(5, 2) / MAX(p.age)::numeric(5, 2)), 2) >
                 round(AVG(p.age), 2)
                THEN true
            else false
           end)                                                                                      AS comparison
FROM person AS p
GROUP BY p.address
ORDER BY 1;