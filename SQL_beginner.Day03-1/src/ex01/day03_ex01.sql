SELECT m.id AS menu_id
FROM menu AS m
LEFT JOIN person_order AS po ON po.menu_id = m.id
WHERE po.person_id IS NULL
ORDER BY 1;

