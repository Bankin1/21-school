SELECT p.name
FROM (SELECT name FROM v_persons_female UNION SELECT name FROM v_persons_male) AS p
ORDER BY name