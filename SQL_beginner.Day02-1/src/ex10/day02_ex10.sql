SELECT p1.name AS person_name1, p2.name AS person_name2, p1.address AS common_address
FROM person AS p1
JOIN (SELECT * FROM person) as p2 ON p2.id < p1.id
WHERE p2.address = p1.address
ORDER BY person_name1, person_name2, common_address;




